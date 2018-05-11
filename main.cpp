#include <iostream>
#include <algorithm>
#include "vector.h"
int main() {
    Vector a(10, 3.8);

    std::cout<<"talpa "<<a.capacity()<<std::endl;
    std::cout<<"paskutinis elementas "<<a.back()<<std::endl;
    std::cout<<"dydis "<<a.size()<<std::endl;
    std::cout<<std::endl;


    a.resize(15);
    std::cout<<"talpa po resize "<<a.capacity()<<std::endl;
    std::cout<<"dydis po resize "<<a.size()<<std::endl;
    std::cout<<"elementai po resize "<<std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout<<i+1<<"  "<<a[i]<<std::endl;
    }

    a.pop_back();
    std::cout<<"talpa po pop_back "<<a.capacity()<<std::endl;
    std::cout<<"dydis po pop_back "<<a.size()<<std::endl;
    std::cout<<"elementai po pop_back "<<std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout<<i+1<<"  "<<a[i]<<std::endl;}



    return 0;
}