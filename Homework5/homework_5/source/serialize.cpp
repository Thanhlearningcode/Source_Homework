#include "serialize.hpp"
#include <fstream>  // Thêm thư viện này

namespace ipb::serialization {

void Serialize(const cv::Mat& m, const std::string& filename) {
    std::ofstream f_out(filename, std::ios_base::out | std::ios_base::binary);
    if (!f_out) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    int rows = m.rows;
    int cols = m.cols;
    int type = m.type();
    int channels = m.channels();

    f_out.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    f_out.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    f_out.write(reinterpret_cast<char*>(&type), sizeof(type));
    f_out.write(reinterpret_cast<char*>(&channels), sizeof(channels));
    f_out.write(reinterpret_cast<const char*>(m.data), rows * cols * m.elemSize());
}

cv::Mat Deserialize(const std::string& filename) {
    std::ifstream input(filename, std::ios_base::in | std::ios_base::binary);
    if (!input) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }

    int r = 0, c = 0, type = 0, channels = 0;
    input.read(reinterpret_cast<char*>(&r), sizeof(int));
    input.read(reinterpret_cast<char*>(&c), sizeof(int));
    input.read(reinterpret_cast<char*>(&type), sizeof(int));
    input.read(reinterpret_cast<char*>(&channels), sizeof(int));

    cv::Mat img = cv::Mat::zeros(r, c, type);
    input.read(reinterpret_cast<char*>(img.data), r * c * img.elemSize());

    return img;
}

}
