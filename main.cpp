#include <iostream>
#include <algorithm>
#include "vector.h"
int main() {

    Vector b(10, 3.8);
    Vector c(7, 9.9);
    Vector a=b;
    std::cout<<"talpa "<<a.capacity()<<std::endl;
    std::cout<<"paskutinis elementas "<<a.back()<<std::endl;
    std::cout<<"dydis "<<a.size()<<std::endl;
    std::cout<<std::endl;



    swap(a, c);
    std::cout<<"talpa po swap "<<a.capacity()<<std::endl;
    std::cout<<"dydis po swap "<<a.size()<<std::endl;
    std::cout<<"elementai po swap "<<std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout<<i<<"  "<<a[i]<<std::endl;
    }


    return 0;
}