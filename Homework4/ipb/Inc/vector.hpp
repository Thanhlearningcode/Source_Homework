#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <vector>
#include <string>

namespace ipb {
  template <typename T>
  class name_vector {
   private:
    std::vector<T> data_;
    std::string name_;

   public:
    explicit name_vector(const std::string& name, std::vector<T> data = {})
        : name_(name), data_(std::move(data)) {}

    std::vector<T>& vector() { return data_; }
    const std::vector<T>& vector() const { return data_; }
    const std::vector<T>& operator()() const { return data_; }
    const std::string& name() const { return name_; }  //< Phiên bản chỉ đọc
    std::string& name() { return name_; }  //< Phiên bản có thể chỉnh sửa
    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }
    size_t capacity() const { return data_.capacity(); }
    void reserve(size_t n) { data_.reserve(n); }
    void resize(size_t n) { data_.resize(n); }
  };
}

#endif /* _VECTOR_HPP_ */
