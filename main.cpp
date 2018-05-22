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

    std::cout<<"size"<<v2a.size()<<std::endl;
    std::cout<<"cpt"<<v2a.capacity()<<std::endl;
    v2a.resize(15, 3);
//    v2a.erase(v2a.begin()+3, v2a.begin()+5);

    int k=0;
    for (auto i = v2a.begin(); i < v2a.end(); ++i) {
        std::cout<<k<<"   "<<*i<<std::endl;
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
//
//    bool empty(){if (sz==0) return true; }
//    unsigned int size(){return sz;}
//    unsigned int max_size() const noexcept;
//    void reserve(size_t newtalpa);
//    size_t capacity(){return cpt;}
//    void shrink_to_fit(){ cpt=sz;}
//
//    //MODIFIERS
//
//    void clear();
//
//    iterator insert(T* pos,const T& elm);
//    iterator insert(const_iterator pos, T&& elm);
//    iterator insert( const_iterator pos, size_type count, const T& elm );
//    iterator insert(const_iterator pos, InputIt first, InputIt last);
//    iterator insert( const_iterator pos, std::initializer_list<T> elm );
//
//
//    iterator erase(iterator);
//    iterator erase(iterator first, iterator last );
//
//    void push_back(const T& value);
//    void push_back( T&& value);
//
//    template< class... Args > void emplace_back( Args&&... args );
//
//    void resize (unsigned int newdydis);
//    void resize(unsigned int count, const T& value );
//
//    template< class... Args > iterator emplace( const_iterator pos, Args&&... args );
//
//    void pop_back();

    return 0;
}