#include "serialize.hpp"

#include "convert_dataset.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include <iostream>
#include <opencv2/xfeatures2d.hpp>
  // Thêm dòng này
#include <experimental/filesystem> // Hoặc #include <filesystem> nếu dùng C++17
namespace fs = std::experimental::filesystem; // Hoặc std::filesystem

namespace ipb::serialization::sifts {

std::tuple<cv::Mat, std::vector<cv::KeyPoint>> ComputeSifts(const std::string& fileName) {
    // Đọc ảnh
    cv::Mat kInput = cv::imread(fileName, cv::IMREAD_GRAYSCALE);
    if (kInput.empty()) {
        std::cerr << "Error: Could not open or find the image " << fileName << std::endl;
        return {};
    }

    // Phát hiện keypoints
    cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(kInput, keypoints);

    // Tính toán descriptors
    cv::Mat descriptors;
    detector->compute(kInput, keypoints, descriptors);

    return std::make_tuple(descriptors, keypoints);
}

void ConvertDataset(const fs::path &img_path) {
    fs::path bin_dir = img_path.parent_path() / "bin";
    fs::create_directory(bin_dir);

    for (const auto &dir_entry : fs::directory_iterator(img_path)) {
        if (dir_entry.path().extension() == ".png") {
            auto sifts = ComputeSifts(dir_entry.path().string());
            cv::Mat descriptors = std::get<0>(sifts);

            fs::path output_file = bin_dir / dir_entry.path().filename();
            output_file.replace_extension(".bin");

            Serialize(descriptors, output_file);
        }
    }
}

std::vector<cv::Mat> LoadDataset(const fs::path &bin_path) {
    std::vector<cv::Mat> descriptors;
    
    for (const auto &dir_entry : fs::directory_iterator(bin_path)) {
        if (dir_entry.path().extension() == ".bin") {
            cv::Mat descriptor = Deserialize(dir_entry.path());
            descriptors.push_back(descriptor);
        }
    }
    return descriptors;
}

} // namespace ipb::serialization::sifts
