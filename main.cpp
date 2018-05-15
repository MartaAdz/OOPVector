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

    Vector <double> c {0,1,2,3,4,5,6,7,8,9};
    c.size();
    c.insert(c.begin()+2, 4.9);
    //c.assign(3, 6.7);
//    std::cout<<"talpa po swap "<<c.begin()<<std::endl;
//    std::cout<<"dydis po swap "<<c.end()<<std::endl;
    std::cout<<"elementai po swap "<<std::endl;
    for (int i = 0; i < c.size(); ++i) {
        std::cout<<i<<"  "<<c[i]<<std::endl;
    }


    return 0;
}