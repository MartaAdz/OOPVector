#include <iostream>
#include <algorithm>
#include "vector.h"
int main() {
    //Vector a(10, 3.8);

    //Vector a(b);

//    std::cout<<"talpa "<<a.capacity()<<std::endl;
//    std::cout<<"paskutinis elementas "<<a.back()<<std::endl;
//    std::cout<<"dydis "<<a.size()<<std::endl;
//    std::cout<<std::endl;

    Vector c{1,2,3,4,5,6,7};
    c.erase(3);
    std::cout<<"talpa po swap "<<c.capacity()<<std::endl;
    std::cout<<"dydis po swap "<<c.size()<<std::endl;
    std::cout<<"elementai po swap "<<std::endl;
    for (int i = 0; i < c.size(); ++i) {
        std::cout<<i<<"  "<<c[i]<<std::endl;
    }


    return 0;
}