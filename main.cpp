#include <iostream>
#include <algorithm>
#include "vector.h"
int main() {
    Vector b(10, 3.8);
    Vector a=b;
    std::cout<<"talpa "<<a.capacity()<<std::endl;
    std::cout<<"paskutinis elementas "<<a.back()<<std::endl;
    std::cout<<"dydis "<<a.size()<<std::endl;
    std::cout<<std::endl;


    a.insert(4,5.3);
    a.swap(4, 7);
    std::cout<<"talpa po insert "<<a.capacity()<<std::endl;
    std::cout<<"dydis po insert "<<a.size()<<std::endl;
    std::cout<<"elementai po insert "<<std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout<<i<<"  "<<a[i]<<std::endl;
    }


    return 0;
}