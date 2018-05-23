#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.h"
#include "timer.hpp"
#define kiekis 1000000
int main() {

//        Timer t;
//
//        std::vector<int> v1;
//        for (int i = 1; i <= kiekis; ++i) {
//
//            v1.push_back(i);
//        }
//        std::cout << t.elapsed() << " s ";
//
//        t.reset();
//
//        Vector<int> v2;
//
//        for (int i = 1; i <= kiekis; ++i) {
//            v2.push_back(i);
//        }
//
//        std::cout << t.elapsed() << " s\n";

        Vector<int> v2 {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
        auto it=v2.begin()+5;
        v2.erase(it, v2.end());
        for (int i = 1; i <= v2.size(); ++i) {
            std::cout<<i<<" "<<v2[i]<<std::endl;
        }



    return 0;
}