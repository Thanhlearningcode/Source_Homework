#ifndef IPB_ALGORITHM_HPP
#define IPB_ALGORITHM_HPP

#include "vector.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

namespace ipb {

int accumulate(const name_vector<int>& vec) {
    return std::accumulate(vec.vector().begin(), vec.vector().end(), 0);
}

int count(const name_vector<int>& vec, int value) {
    return std::count(vec.vector().begin(), vec.vector().end(), value);
}

bool all_even(const name_vector<int>& vec) {
    return std::all_of(vec.vector().begin(), vec.vector().end(), [](int n) { return n % 2 == 0; });
}

void clamp(name_vector<int>& vec, int min, int max) {
    std::for_each(vec.vector().begin(), vec.vector().end(), [min, max](int& n) {
        n = std::max(min, std::min(n, max));
    });
}

void fill(name_vector<int>& vec, int value) {
    std::fill(vec.vector().begin(), vec.vector().end(), value);
}

bool find(const name_vector<int>& vec, int value) {
    return std::find(vec.vector().begin(), vec.vector().end(), value) != vec.vector().end();
}

void print(const name_vector<int>& vec) {
    std::cout << "Vector (" << vec.name() << "): ";
    for (int v : vec.vector()) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void toupper(name_vector<int>& vec) {
    std::transform(vec.name().begin(), vec.name().end(), vec.name().begin(), ::toupper);
}


void sort(name_vector<int>& vec) {
    std::sort(vec.vector().begin(), vec.vector().end());
}

void rotate(name_vector<int>& vec, int positions) {
    std::rotate(vec.vector().begin(), vec.vector().begin() + positions, vec.vector().end());
}

void reverse(name_vector<int>& vec) {
    std::reverse(vec.vector().begin(), vec.vector().end());
}

}  // namespace ipb

#endif /* IPB_ALGORITHM_HPP */
