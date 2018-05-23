#include <iostream>
#include <algorithm>
#include <vector>
#include "vector.h"
#include "timer.hpp"
#define kiekis 10000000
int main() {
//    Timer t;

    //for (int j = 0; j != 6 ; ++j) {


//        std::vector<int> v1;
//        for (int i = 1; i <= kiekis; ++i) v1.push_back(i);
//        std::cout << t.elapsed() << " s ";
//
//        t.reset();
//
//        Vector<int> v2;
//
//        for (int i = 1; i <= kiekis; ++i) { //std::cout<<i<<std::endl;
//            v2.push_back(i);
//        }
//
//        std::cout << t.elapsed() << " s\n";
//        t.reset();

//    }


    Vector<int> v2a {2,4,6,8,10,12,14};
    std::initializer_list<int> v3a {1,3,5,7,9,11,14};

    std::cout<<"size"<<v2a.size()<<std::endl;
    std::cout<<"cpt"<<v2a.capacity()<<std::endl;
    v2a.emplace_back(4);

    int k=0;
    for (auto i = v2a.begin(); i < v2a.end(); ++i) {
        std::cout<<k+1<<"   "<<*i<<std::endl;
        k++;
    }
    std::cout<<"size"<<v2a.size()<<std::endl;
    std::cout<<"cpt"<<v2a.capacity()<<std::endl;


//    void assign (size_type count, const T& value);
//    void assign( InputIt first, InputIt last );
//    void assign( std::initializer_list<T> elm );
//    allocator_type get_allocator() const;
//
//    //get_allocator()
//
//    //ELEMENT_ACCESS
//
//    reference at( size_type pos );
//    const_reference at( size_type pos ) const;
//
//    reference operator[](size_type i){ return elem[i];}
//    const_reference operator[](size_type i)const{ return elem[i];}
//
//    reference front(){return elem[0]; }
//    const_reference front() const {return elem[0]; }
//
//    reference back() {return elem[sz-1]; }
//    const_reference back()const {return elem[sz-1]; }
//
//    //ITERATORS
//
//    iterator begin() noexcept {return elem; }
//    const_iterator cbegin()const noexcept {return elem; }
//
//    reverse_iterator rbegin() noexcept{return reverse_iterator (elem+sz);}
//    reverse_iterator rcbegin() const noexcept{return reverse_iterator (elem+sz);}
//
//    iterator end() noexcept {return elem+sz; }
//    const_iterator cend() noexcept {return elem+sz; }
//
//    reverse_iterator rend() noexcept {return reverse_iterator (elem); }
//    reverse_iterator rcend() const noexcept {return reverse_iterator (elem); }
//
//    iterator data() noexcept{return elem; }
//    const_iterator data() const noexcept{return elem; }
//
//    //CAPACITY


    return 0;
}