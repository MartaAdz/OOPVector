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

    Vector <double> a {0,1,2,3,4,5,6,7,8,9};

    Vector <double> c {2.1,4.1,6.1,8.1};
    std::initializer_list<double> elm {7.8, 4.7,5.5,6.9};

    //a.insert(a.begin()+2, elm);
    //a.emplace_back(2);
    swap(a,c);

//    std::cout<<"talpa po resize "<<a.capacity()<<std::endl;
//    std::cout<<"2 elementas su at "<<a.at(1)<<std::endl;
//    std::cout<<"dydis po resize "<<a.size()<<std::endl;
    std::cout<<"elementai po resize "<<std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout<<i<<"  "<<a[i]<<std::endl;
    }


    return 0;
}