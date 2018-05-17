#include<iostream>
#include<iomanip>
#include<algorithm>
#include <stdexcept>
#include <utility>

#ifndef UZDUOTYS_VECTOR_H
#define UZDUOTYS_VECTOR_H

template <class T>
class Vector{
private:

    T * elem;
    unsigned int sz;
    size_t cpt;


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
    Vector(): sz(0), elem(new T[sz]), cpt(4) {}

    explicit Vector(unsigned int d): sz {d}, elem{new T [sz]}, cpt{d}{
        std::fill_n(elem, d, 0.0);
    }

    Vector(unsigned int d, T reiksme) : sz (d), elem(new T[sz]), cpt (d){
        std::fill_n(elem, d, reiksme);
    }

    Vector(const Vector&v){
        elem=new T[v.sz];
        sz=v.sz;
        cpt=v.cpt;
        for (int i=0; i!=sz; i++) elem[i]=v.elem[i];
    }

    Vector(std::initializer_list<T> elm)
            :sz{static_cast<unsigned int>(elm.size())},
             elem{new T[elm.size()]}
    {
        std::copy(elm.begin(),elm.end(),elem);
        cpt=sz;
    }
    Vector( Vector&& v1 ) noexcept :
            elem{v1.elem},
            sz{v1.sz}
    {
        v1.elem= nullptr;
        v1.sz=0;
    }

    //DESTRUKTORIUS
    ~Vector() {delete[]elem;}

    //OPERATORIAI

    Vector& operator=(const Vector& v);
    Vector& operator=(Vector&& v) noexcept;
    Vector& operator=(std::initializer_list<T>);


    //FUNKCIJOS


    void assign (size_type count, const T& value);
    template< class InputIt > void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<T> elm );

    //get_allocator()

        //ELEMENT_ACCESS

    reference at( size_type pos );
    const_reference at( size_type pos ) const;

    reference operator[](size_type i){ return elem[i];}
    const_reference operator[](size_type i)const{ return elem[i];}

    reference front(){return elem[0]; }
    const reference front() const {return elem[0]; }

    reference back() {return elem[sz-1]; }
    const reference back()const {return elem[sz-1]; }

        //ITERATORS

    iterator begin() noexcept {return elem; }
    const_iterator cbegin()const noexcept {return elem; }

    reverse_iterator rbegin() noexcept{return reverse_iterator (elem+sz);}
    reverse_iterator rcbegin() const noexcept{return reverse_iterator (elem+sz);}

    iterator end() noexcept {return elem+sz; }
    const_iterator cend() noexcept {return elem+sz; }

    reverse_iterator rend() noexcept {return reverse_iterator (elem); }
    reverse_iterator rcend() const noexcept {return reverse_iterator (elem); }

    iterator data() noexcept{return elem; }
    const_iterator data() const noexcept{return elem; }

        //CAPACITY

    bool empty(){if (sz==0) return true; }
    unsigned int size(){return sz;}
    unsigned int max_size() const noexcept;
    void reserve(size_t newtalpa);
    size_t capacity(){return cpt;}
    void shrink_to_fit(){ cpt=sz;}

        //MODIFIERS

    void clear();

    iterator insert(T* pos,const T& elm);
    iterator insert(const_iterator pos, T&& elm);
    iterator insert( const_iterator pos, size_type count, const T& elm );
    template <class InputIt> iterator insert(iterator pos, InputIt first, InputIt last);
    iterator insert( const_iterator pos, std::initializer_list<T> elm );

    //emplace

    iterator erase(iterator);
    iterator erase(iterator first, iterator last );

    void push_back(const T& naujas);
    void push_back( T&& value);

    template< class... Args > void emplace_back( Args&&... args );

    void resize (unsigned int newdydis);
    void resize(unsigned int count, const T& value );

    template< class... Args > iterator emplace( const_iterator pos, Args&&... args );

    void pop_back();

};


    template <class T>
    void Vector<T>::assign (typename Vector<T>::size_type count, const T& value){

        if (cpt<count) cpt=count;

        auto newelementai = new T [sz];

        for (unsigned int i = 0; i < count; ++i) newelementai[i]=value;

        delete [] elem;
        elem = newelementai;

    }

    template <class T>
    template <class InputIt>
    void Vector<T>::assign( InputIt first, InputIt last ){

        size_type count = last-first;
        if (cpt<count) cpt=count;

        auto newelementai = new T [sz];

        for (unsigned int i = 0; i < count; ++i) {
            newelementai[i]=*first;
            first++;
        }
        delete [] elem;
        elem = newelementai;
    }

    template <class T>
    void Vector<T>::assign( std::initializer_list<T> elm ){

        size_t count = elm.size();
        if (cpt<count) cpt=count;

        auto newelementai = new T [sz];

        for (int i = 0; i < count; ++i) newelementai[i]=elm.begin()+i;

        delete [] elem;
        elem = newelementai;
    }

    template<class T>
    T& Vector<T>::at( size_type pos ){
        if ( pos >= sz) throw std::out_of_range("Position is out of range");
        return elem[pos];
    }

    template <class T>
    const T& Vector<T>::at( size_type pos ) const{
        if ( pos >= sz) throw std::out_of_range("Position is out of range");
        return elem[pos];
    }

    template<class T>
    Vector<T>& Vector<T>::operator = (const Vector<T> & v){

        auto*p= new T [v.sz];
        for (int i=0; i!=v.sz; i++) p[i]=v.elem[i];

        delete[]elem;

        elem=p;
        sz=v.sz;

        return *this;
    }

    template<class T>
    Vector<T>& Vector<T>::operator=(Vector&& v) noexcept{

        auto*p= new T [v.sz];
        for (int i=0; i!=v.sz; i++) p[i]=std::move(v.elem[i]);

        delete[]elem;

        elem=p;
        sz=v.sz;

        return *this;
    }
    template<class T>
    Vector<T>& Vector<T>::operator=(std::initializer_list<T> nariai) {

        if (cpt<nariai.size()) cpt=nariai.size();
        sz = 0;
        for (auto &item: nariai)
            elem[sz++] = item;

    }

    template <typename T>
    unsigned int Vector<T>::max_size() const noexcept {             //NEEDS ATTENTION

        //return LNI_VECTOR_MAX_SZ;
    }


    template<class T>
    void Vector<T>::clear(){

        auto newelementai = new T [0];
        delete [] elem;

        elem = newelementai;
        sz = 0;
        cpt=0;
    }

    template<class T>
    T* Vector<T>::insert(T* pos, const T& elm){
        if(sz==cpt) cpt=cpt+3;
        sz++;
        auto * newelementai = new T [sz];

        for (unsigned int j = 0; j != *pos; ++j) newelementai[j] = elem[j];
        unsigned int index = pos - begin();
        newelementai[index]=elm;

        for (unsigned int i = *pos+1; i < sz; ++i) newelementai[i] = elem[i-1];

        delete[] elem;
        elem = newelementai;
    }

    template<class T>
    T* Vector<T>::insert(const T* pos, T&& elm){
        if(sz==cpt) cpt=cpt+3;
        sz++;
        auto * newelementai = new T [sz];
         unsigned int index = pos - begin();
        newelementai[index]=elm;
        for (int j = 0; j != *pos; ++j) newelementai[j] = std::move(elem[j]);
        newelementai[pos]=elm;
        for (int i = *pos+1; i < sz; ++i) newelementai[i] = std::move(elem[i-1]);

        delete[] elem;
        elem = newelementai;

    }

    template<class T>
    T* Vector<T>::insert(const_iterator pos, size_type count, const T& elm ){
        if(cpt<sz+count) cpt+=count;
        sz+=count;

        auto * newelementai = new T [sz];

        for (int i = 0; i != *pos; ++i) newelementai[i]=elem[i];

        for (int j = *pos; j != *pos+count; ++j) newelementai[j]=elm;

        for (int k = *pos+count; k != sz ; ++k) newelementai[k]=elem[k-count];

        delete[] elem;
        elem = newelementai;

    }
    template<class T>
    template <class InputIt>
    T* Vector<T>::insert(iterator pos, InputIt first, InputIt last){

        unsigned int count= last-first;

        if (cpt<cpt+count) cpt+=count;
        sz+=count;
        auto newelementai = new T [sz];

        for (int i = 0; i != *pos; ++i) newelementai[i]=elem[i];

        for (int j = *pos; j < *pos+count; ++j) {
            newelementai[j]=*first;
            first++;
        }
        for (int k = *pos+count; k < sz; ++k) newelementai[k]=elem[k-count];

        delete [] elem;
        elem = newelementai;

    }
    template <class T>
    T* Vector<T>::insert( const_iterator pos, std::initializer_list<T> elm ){

        size_t count = elm.size();
        if (cpt<cpt+count) cpt+=count;
        sz+=count;
        auto newelementai = new T [sz];

        for (int i = 0; i != *pos; ++i) newelementai[i]=elem[i];

        unsigned int i = 0;
        for (int j = *pos; j < *pos+elm.size(); ++j) {

            T value = *(elm.begin()+i);
            newelementai[j]=value;
            i++;

        }
        for (int k = *pos+elm.size(); k < sz; ++k) newelementai[k]=elem[k-count];

        delete [] elem;
        elem = newelementai;

    }

//emplace
    template<class T>
    T* Vector<T>::erase (T* pos){
        auto newelementai = new T [sz -1];
        for (unsigned int i = 0; i != *pos; ++i) {
            newelementai[i]=elem[i];
        }
        for (unsigned int j = *pos; j != sz; ++j) {
            newelementai[j]=elem[j+1];
        }
        delete [] elem;
        elem = newelementai;
        sz--;

    }
    template<class T>
    T* Vector<T>::erase(T* first, T* last ){
        auto newelementai = new T [sz -1];
        auto diff=last-first;
        for (unsigned int i = 0; i != *first+1; ++i) {
            newelementai[i]=elem[i];
        }
        for (unsigned int j = *last-1; j !=sz; ++j) {
            newelementai[j]=elem[j+diff];
        }
        delete [] elem;
        elem = newelementai;
        sz-=diff;

    }

    template<class T>
    void Vector<T>::push_back(const T& value)
    {

        if (cpt==0) cpt=1;

        if (sz==cpt) cpt+=3;



        auto newelementai= new T[cpt];
        for (int i = 0; i < sz; ++i) {
            newelementai[i]=elem[i];
        }
        newelementai[sz+1]=value;
        delete[] elem;
        elem=newelementai;
    }


    template <class T>
    template< class... Args >
    void Vector<T>::emplace_back( Args&&... args ){
        if(sz==cpt) cpt=cpt+3;
        elem[sz] = std::move( T( std::forward<Args>(args) ... ) );
        sz++;
    }

    template<class T>
    void Vector<T>::reserve(size_t newtalpa){
        if(newtalpa>cpt){
            auto * newelementai = new T[newtalpa];
            for (unsigned int i = 0; i <sz; i++) newelementai[i] = elem[i];
            cpt=newtalpa;
            delete[] elem;
            elem = newelementai;
        }
    }
    template<class T>
    void Vector<T>::resize (unsigned int newdydis){

        auto * newelementai = new double[newdydis];
        for (unsigned int i = 0; i != newdydis; i++) newelementai[i] = elem[i];
        sz=newdydis;
        if (cpt<newdydis) cpt=newdydis;
        delete[] elem;
        elem = newelementai;
    }

    template<class T>
    void Vector<T>::resize(unsigned int count, const T& value ){

        auto * newelementai = new T [sz+count];
        for (unsigned int i = 0; i != size(); i++) newelementai[i] = elem[i];
        for (unsigned int j = sz; j < sz+count; ++j) newelementai[j]=value;

        if (cpt<count) cpt=count;
        sz=count;

        delete[] elem;
        elem = newelementai;
    }
    template <class T>
    template< class... Args >
    T* Vector<T>::emplace( const T* pos, Args&&... args ){              //needs attention



    }

    template<class T>
    void Vector<T>::pop_back(){
        sz--;
        auto * newelementai = new double[sz];
        for (unsigned int i = 0; i != sz; i++) newelementai[i] = elem[i];

        delete[] elem;
        elem = newelementai;

    }
    template<class T>
    void swap (Vector<T>&v1, Vector<T>&v2){
        Vector<T> tmp {std::move(v1)};
        v1=std::move (v2);
        v2=std::move(tmp);
    }

#endif //UZDUOTYS_VECTOR_H
