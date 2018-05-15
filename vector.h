#include<iostream>
#include<iomanip>
#include<algorithm>

#ifndef UZDUOTYS_VECTOR_H
#define UZDUOTYS_VECTOR_H

template <class T>
class Vector{
private:

    T * elementai;
    unsigned int dydis;
    size_t talpa;


public:


    //MEMBERTYPES

    typedef T           value_type;
   // typedef Allocator allocator_type;
    typedef unsigned int size_type;
    typedef ptrdiff_t   difference_type;
    typedef T &         reference;
    typedef const T &   const_reference;
    typedef T *         pointer;
    typedef const T *   const_pointer;
    typedef T *         iterator;
    typedef const T * const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    //KONSTRUKTORIAI
    Vector(): dydis(0), elementai(new T[dydis]), talpa(4) {}

    Vector(unsigned int d): dydis {d}, elementai{new T [dydis]}, talpa{d}{
        std::fill_n(elementai, d, 0.0);
    }

    Vector(unsigned int d, T reiksme) : dydis (d), elementai(new T[dydis]), talpa (d){
        std::fill_n(elementai, d, reiksme);
    }

    Vector(const Vector&v){
        elementai=new T[v.dydis];
        dydis=v.dydis;
        talpa=v.talpa;
        for (int i=0; i!=dydis; i++) elementai[i]=v.elementai[i];
    }

    Vector(std::initializer_list<T> elm)
            :dydis{static_cast<unsigned int>(elm.size())},
             elementai{new T[elm.size()]}
    {
        std::copy(elm.begin(),elm.end(),elementai);
        talpa=dydis;
    }
    Vector( Vector&& v1 ) :
            elementai{v1.elementai},
            dydis{v1.dydis}
    {
        v1.elementai= nullptr;
        v1.dydis=0;
    }

    //DESTRUKTORIUS
    ~Vector() {delete[]elementai;}

    //OPERATORIAI

    Vector& operator=(const Vector& v);
    Vector& operator=(Vector&& v);
    Vector& operator=(std::initializer_list<T>);


    //FUNKCIJOS


    void assign (size_type count, const T& value);

        //CAPACITY

    bool empty(){if (dydis==0) return true; }
    unsigned int size(){return dydis;}
    //max_size
    void reserve(size_t newtalpa);
    size_t capacity(){return talpa;}
    void shrink_to_fit(){ talpa=dydis;}

        //ELEMENT_ACCESS

    //at
    reference operator[](size_type i){ return elementai[i];}
    const_reference operator[](size_type i)const{ return elementai[i];}

    reference front(){return elementai[0]; }
    const reference front() const {return elementai[0]; }

    reference back() {return elementai[dydis-1]; }
    const reference back()const {return elementai[dydis-1]; }

        //ITERATORS

    iterator begin() noexcept {return elementai; }
    const_iterator cbegin()const noexcept {return elementai; }

    reverse_iterator rbegin() noexcept{return reverse_iterator (elementai+dydis);}
    reverse_iterator rcbegin() const noexcept{return reverse_iterator (elementai+dydis);}

    iterator end() noexcept {return elementai+dydis; }
    const_iterator cend() noexcept {return elementai+dydis; }

    reverse_iterator rend() noexcept {return reverse_iterator (elementai); }
    reverse_iterator rcend() const noexcept {return reverse_iterator (elementai); }


    //data

        //MODIFIERS

    void clear();
    iterator insert(T* pos,const T& elm);
    iterator insert(const_iterator position,T&& elm);
    iterator insert( const_iterator pos, size_type count, const T& value );
    template <class InputIt> iterator insert(iterator pos, InputIt first, InputIt last);
    iterator insert( const_iterator pos, std::initializer_list<T> newval );
    //emplace

    iterator erase(iterator);
    iterator erase(iterator first, iterator last );
    void push_back(const T& naujas);
    void push_back( T&& value);
    //emplace_back
    void resize (unsigned int newdydis);
    void resize(unsigned int count, const T& value );
    void pop_back();


};

    template<class T>
    Vector<T>& Vector<T>::operator = (const Vector<T> & v){
        auto*p= new T [v.dydis];
        for (int i=0; i!=v.dydis; i++) p[i]=v.elementai[i];
        delete[]elementai;
        elementai=p;
        dydis=v.dydis;
        return *this;
    }
    
    template<class T>
    Vector<T>& Vector<T>::operator=(Vector&& v){
        auto*p= new T [v.dydis];
        for (int i=0; i!=v.dydis; i++) p[i]=std::move(v.elementai[i]);
        delete[]elementai;
        elementai=p;
        dydis=v.dydis;
        return *this;
    }
    template<class T>
    Vector<T>& Vector<T>::operator=(std::initializer_list<T> nariai){

        if (talpa<nariai.size()) talpa=nariai.size();
        dydis = 0;
        for (auto &item: nariai)
            elementai[dydis++] = item;


    }

    //FUNKCIJOS
    template <class T>
    void Vector<T>::assign (typename Vector<T>::size_type count, const T& value){

        if (talpa<count) talpa=count;
        for (unsigned int i = 0; i < count; ++i) {
            elementai[i]=value;
        }

    }


//CAPACITY

//max_size


//ELEMENT_ACCESS

//at
//data

//MODIFIERS

    template<class T>
    void Vector<T>::clear(){
        auto newelementai = new T [0];
        delete [] elementai;
        elementai = newelementai;
        dydis = 0;
        talpa=0;
    }

    template<class T>
    T* Vector<T>::insert(T* pos,const T& elm){
        if(dydis==talpa) talpa=talpa+3;
        dydis++;
        auto * newelementai = new T [dydis];

        for (unsigned int j = 0; j != *pos; ++j) newelementai[j] = elementai[j];
        unsigned int index = pos - begin();
        newelementai[index]=elm;

        for (unsigned int i = *pos+1; i < dydis; ++i) newelementai[i] = elementai[i-1];

        delete[] elementai;
        elementai = newelementai;
    }

    template<class T>
    T* Vector<T>::insert(const T* pos, T&& elm){
        if(dydis==talpa) talpa=talpa+3;
        dydis++;
        auto * newelementai = new T [dydis];
         unsigned int index = pos - begin();
        newelementai[index]=elm;
        for (int j = 0; j != *pos; ++j) newelementai[j] = elementai[j];
        newelementai[pos]=elm;
        for (int i = *pos+1; i < dydis; ++i) newelementai[i] = elementai[i-1];

        delete[] elementai;
        elementai = newelementai;

    }

    template<class T>
    T* Vector<T>::insert(const_iterator pos, size_type count, const T& elm ){
        if(talpa<dydis+count) talpa+=count;
        dydis+=count;

        auto * newelementai = new T [dydis];

        for (int i = 0; i != *pos; ++i) newelementai[i]=elementai[i];

        for (int j = *pos; j != *pos+count; ++j) newelementai[j]=elm;

        for (int k = *pos+count; k != dydis ; ++k) newelementai[k]=elementai[k-count];

        delete[] elementai;
        elementai = newelementai;

    }
    template<class T>                                                       //NEEDS ATTENTION
    template <class InputIt>
    T* Vector<T>::insert(iterator pos, InputIt first, InputIt last){



        auto * newelementai = new T [dydis];



        delete[] elementai;
        elementai = newelementai;

    }
    template <class T>                                                       //NEEDS ATTENTION
    T* Vector<T>::insert( const_iterator pos, std::initializer_list<T> newval ){


    }

//emplace
    template<class T>
    T* Vector<T>::erase (T* pos){
        auto newelementai = new T [dydis -1];
        for (unsigned int i = 0; i != *pos; ++i) {
            newelementai[i]=elementai[i];
        }
        for (unsigned int j = *pos; j != dydis; ++j) {
            newelementai[j]=elementai[j+1];
        }
        delete [] elementai;
        elementai = newelementai;
        dydis--;

    }
    template<class T>
    T* Vector<T>::erase(T* first, T* last ){
        auto newelementai = new T [dydis -1];
        auto diff=last-first;
        for (unsigned int i = 0; i != *first+1; ++i) {
            newelementai[i]=elementai[i];
        }
        for (unsigned int j = *last-1; j !=dydis; ++j) {
            newelementai[j]=elementai[j+diff];
        }
        delete [] elementai;
        elementai = newelementai;
        dydis-=diff;

    }

    template<class T>
    void Vector<T>::push_back(const T& naujas)
    {
        if(dydis==talpa) talpa=talpa+3;

        elementai[dydis]=naujas;
        dydis++;
    }
    template <class T>
    void Vector<T>::push_back( T&& value ){
        if(dydis==talpa) talpa=talpa+3;

        elementai[dydis]=value;
        dydis++;
    };

    //emplace_back
    template<class T>
    void Vector<T>::reserve(size_t newtalpa){
        if(newtalpa>talpa){
            auto * newelementai = new T[newtalpa];
            for (unsigned int i = 0; i <dydis; i++) newelementai[i] = elementai[i];
            talpa=newtalpa;
            delete[] elementai;
            elementai = newelementai;
        }
    }
    template<class T>
    void Vector<T>::resize (unsigned int newdydis){

        auto * newelementai = new double[newdydis];
        for (unsigned int i = 0; i != newdydis; i++) newelementai[i] = elementai[i];
        dydis=newdydis;
        if (talpa<newdydis) talpa=newdydis;
        delete[] elementai;
        elementai = newelementai;
    }

    template<class T>
    void Vector<T>::resize(unsigned int count, const T& value ){

        auto * newelementai = new T [dydis+count];
        for (unsigned int i = 0; i != size(); i++) newelementai[i] = elementai[i];
        for (unsigned int j = dydis; j < dydis+count; ++j) newelementai[j]=value;

        if (talpa<count) talpa=count;
        dydis=count;

        delete[] elementai;
        elementai = newelementai;
    }

    template<class T>
    void Vector<T>::pop_back(){
        dydis--;
        auto * newelementai = new double[dydis];
        for (unsigned int i = 0; i != dydis; i++) newelementai[i] = elementai[i];

        delete[] elementai;
        elementai = newelementai;

    }
    template<class T>
    void swap (Vector<T>&v1, Vector<T>&v2){
        Vector<T> tmp {std::move(v1)};
        v1=std::move (v2);
        v2=std::move(tmp);
    }

    template <class T>
    void swap (Vector<T>&v1,Vector<T>&v2);
#endif //UZDUOTYS_VECTOR_H
