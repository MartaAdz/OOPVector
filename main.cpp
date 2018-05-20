#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.h"
#include "timer.hpp"
int main() {
    Timer t;
    for (int j = 1; j != 6; ++j) {

        std::vector<int> v1;
        for (int i = 1; i <= 100000; ++i) v1.push_back(i);
        std::cout << t.elapsed() << " s ";

        t.reset();

        Vector<int> v2;

        for (int i = 1; i <= 100000; ++i) { v2.push_back(i); }

        std::cout << t.elapsed() << " s\n";
        t.reset();


    }


//    for (int i = 0; i < a.size(); ++i) {
//        std::cout<<a[i]<<std::endl;
//
//    }
    return 0;
}