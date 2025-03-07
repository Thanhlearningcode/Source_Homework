#include <iostream>
#include "ibp.hpp"

void Byebye(void);

int main() {
    atexit(Byebye);
    
    ipb::name_vector<int> acc("name", {4, 2, 1, 3});

   // std::cout << "Sum: " << ipb::accmulate(acc) << std::endl;
    std::cout << "Count of 1: " << ipb::count(acc, 1) << std::endl;
    std::cout << "All even: " << (ipb::all_even(acc) ? "TRUE" : "NO") << std::endl;
    
    // ipb::clamp(vec, 0, 15);
    // std::cout << "After clamping: ";
    // ipb::print(vec);
    
    // vec.resize(10);  // Đảm bảo đủ chỗ trước khi fill
    // ipb::fill(vec, -99);
    

    ipb::toupper(acc);
    std::cout << "Uppercase name: " << acc.name() << std::endl;

    ipb::sort(acc);
    ipb::print(acc);

    ipb::rotate(acc, 1);
    ipb::print(acc);

    ipb::reverse(acc);
    ipb::print(acc);

    return 0;
}

void Byebye(void) {
    std::cout << "Bye bye! See you soon" << std::endl;
}
