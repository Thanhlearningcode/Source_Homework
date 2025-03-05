#include <iostream>
#include "vector.hpp"

int main() {
    ipb::name_vector<int> my_vector("MyIntVector");

    std::cout << "Vector Name: " << my_vector.name() << "\n";
    std::cout << "Is Empty: " << std::boolalpha << my_vector.empty() << "\n";

    my_vector.vector().push_back(10);
    my_vector.vector().push_back(20);
    
    std::cout << "Vector Size: " << my_vector.size() << "\n";
    std::cout << "Vector Capacity: " << my_vector.capacity() << "\n";

    return 0;
}
