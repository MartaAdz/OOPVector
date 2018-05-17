#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.h"
#include "timer.hpp"
int main() {
    Timer t;

    std::vector<int> v1;
    for (int i = 1; i <= 100; ++i) v1.push_back(i);
    for (int j = 0; j < v1.size(); ++j) {
        std::cout<<j<<" "<<v1[j]<<std::endl;
    }
    std::cout << t.elapsed() << " s";

// Pradėti v2 užpildymo laiko matavimą

    t.reset();

    Vector<int> v2;
    for (int i = 1; i <= 100; ++i){ v2.push_back(i); }
    for (int j = 0; j < v2.size(); ++j) {
        std::cout<<j<<" "<<v2[j]<<std::endl;
    }

    std::cout << t.elapsed() << " s";



    return 0;
}