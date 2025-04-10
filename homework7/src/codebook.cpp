#include "codebook.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <random>
#include <limits>

namespace ipb {

float EuclideanDistance(const cv::Mat& a, const cv::Mat& b) {
  return cv::norm(a, b, cv::NORM_L2);
}

std::vector<cv::Mat> GetInitialClusterCenters(const std::vector<cv::Mat>& descriptors, int k) {
  std::vector<cv::Mat> centroids;
  centroids.reserve(k);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(0, descriptors.size() - 1);

  for (int i = 0; i < k; ++i) {
    int index = distribution(gen);
    centroids.push_back(descriptors[index].clone());
  }

  return centroids;
}

void AssignToClusters(const std::vector<cv::Mat>& descriptors,
                      const std::vector<cv::Mat>& centroids,
                      std::map<int, std::vector<cv::Mat>>& clusters) {
  for (const auto& descriptor : descriptors) {
    float min_distance = std::numeric_limits<float>::max();
    int best_id = -1;

    for (size_t j = 0; j < centroids.size(); ++j) {
      float dist = EuclideanDistance(centroids[j], descriptor);
      if (dist < min_distance) {
        min_distance = dist;
        best_id = static_cast<int>(j);
      }
    }

    clusters[best_id].push_back(descriptor);
  }
}

std::vector<cv::Mat> RecomputeCenters(int k,
                                      const std::map<int, std::vector<cv::Mat>>& clusters,
                                      const std::vector<cv::Mat>& old_centroids,
                                      const std::vector<cv::Mat>& descriptors) {
  std::vector<cv::Mat> new_centroids = GetInitialClusterCenters(descriptors, k);

  for (const auto& [cluster_id, cluster] : clusters) {
    if (cluster.empty()) continue;

    cv::Mat sum = cv::Mat::zeros(cluster[0].size(), cluster[0].type());
    for (const auto& descriptor : cluster) {
      sum += descriptor;
    }
    new_centroids[cluster_id] = sum / static_cast<float>(cluster.size());
  }

  return new_centroids;
}

cv::Mat KMeans(const std::vector<cv::Mat>& descriptors, int k, int max_iter) {
  std::vector<cv::Mat> descriptors_32f;
  for (const auto& descriptor : descriptors) {
    cv::Mat temp;
    descriptor.convertTo(temp, CV_32FC1);
    descriptors_32f.push_back(temp);
  }

  auto centroids = GetInitialClusterCenters(descriptors_32f, k);

  for (int iter = 0; iter < max_iter; ++iter) {
    std::map<int, std::vector<cv::Mat>> clusters;
    AssignToClusters(descriptors_32f, centroids, clusters);
    centroids = RecomputeCenters(k, clusters, centroids, descriptors_32f);
  }

  cv::Mat result;
  for (const auto& centroid : centroids) {
    result.push_back(centroid);
  }

  return result;
}

}  // namespace ipb
