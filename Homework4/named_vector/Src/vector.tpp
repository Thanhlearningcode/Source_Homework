#ifndef _VECTOR_TPP_
#define _VECTOR_TPP_

#include "../Inc/vector.hpp"

namespace ipb {

/*Constructor: Initializes the name*/ 
template <typename T>
name_vector<T>::name_vector (const std::string& name) : name_(name) {}

/*Returns a reference to the internal vector*/ 
template <typename T>
std::vector<T>& name_vector<T>::vector() {
    return data_;
}

/*Returns a const reference to the internal vector*/ 
template <typename T>
const std::vector<T>& name_vector<T>::vector() const {
    return data_;
}

template <typename T>
const std::vector<T>& name_vector<T>::operator()() const {
    return data_;
}
/*Returns the name of the vector*/ 
template <typename T>
std::string name_vector<T>::name() const {
    return name_;
}

/*Checks if the vector is empty*/ 
template <typename T>
bool name_vector<T>::empty() const {
    return data_.empty();
}

/*Returns the size of the vector*/ 
template <typename T>
size_t name_vector<T>::size() const {
    return data_.size();
}

/*Returns the capacity of the vector*/ 
template <typename T>
size_t name_vector<T>::capacity() const {
    return data_.capacity();
}

/*Reserves space for the vector*/ 
template <typename T>
void name_vector<T>::reserve(size_t n) {
    data_.reserve(n);
}

/*Resizes the vector*/ 
template <typename T>
void name_vector<T>::resize(size_t n) {
    data_.resize(n);
}

}  

#endif /* _VECTOR_TPP_ */
