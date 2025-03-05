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
    // Constructor
    explicit name_vector(const std::string& name);

    // Member functions
    std::vector<T>& vector();
    const std::vector<T>& vector() const;
    std::string name() const;
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t n);
    void resize(size_t n);
  };
}

#include "../Src/vector.tpp"

#endif /* _VECTOR_HPP_ */
