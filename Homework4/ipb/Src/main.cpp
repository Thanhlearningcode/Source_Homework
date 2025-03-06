#include <iostream>
#include "ipb.hpp"
#include <cstdlib>

void Byebye (void);
    int main (int argc, char const *argv[]) {
        atexit (Byebye);
        ipb::named_vector<int> acc("name", {4, 2, 1, 3});
        /*returns the sum over all the elements in the data container*/
        std:: cout<< ipb::acculate (acc) <<std::end;
        /*return how many elements are stored in the container*/
        std:: cout<< ipb::cout (vec,1) << std::end;
        /*returns true if all values in the container are even, false otherwise.*/
        std:: cout<< ipb::all_even (vec) ? "TRUE" :"NO"<<std::endl;
        /*clamp all the values in the container to a given range [min, max]*/
        std:: cout<< ipb::clamp(vec,0,15)<<"After clamping:"<<print(vec);
        std:: cout<< ipb::

        return 1;
    }
void Byebye (void) {
    std::cout <<"Bye bye! See you soon";
    }