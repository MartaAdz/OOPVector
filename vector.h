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
    //typedef std::allocator   allocator_type;
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
    typedef iterator    InputIt;


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
    void assign( InputIt first, InputIt last );
    void assign( std::initializer_list<T> elm );
//    allocator_type get_allocator() const;

    //get_allocator()

        //ELEMENT_ACCESS

    reference at( size_type pos );
    const_reference at( size_type pos ) const;

    reference operator[](size_type i){ return elem[i];}
    const_reference operator[](size_type i)const{ return elem[i];}

    reference front(){return elem[0]; }
    const_reference front() const {return elem[0]; }

    reference back() {return elem[sz-1]; }
    const_reference back()const {return elem[sz-1]; }

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
    iterator insert(const_iterator pos, InputIt first, InputIt last);
    iterator insert( const_iterator pos, std::initializer_list<T> elm );


    iterator erase(iterator);
    iterator erase(iterator first, iterator last );

    void push_back(const T& value);
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

        auto newelementai = new T [cpt];

        for (unsigned int i = 0; i < count; ++i) newelementai[i]=value;

        delete [] elem;
        elem = newelementai;

    }

    template <class T>
    void Vector<T>::assign( InputIt first, InputIt last ){

        size_type count = last-first;
        if (cpt<count) cpt=count;

        auto newelementai = new T [cpt];
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

        auto newelementai = new T [cpt];

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

        auto*p= new T [v.cpt];
        for (int i=0; i!=v.sz; i++) p[i]=v.elem[i];

        delete[]elem;

        elem=p;
        sz=v.sz;

        return *this;
    }

    template<class T>
    Vector<T>& Vector<T>::operator=(Vector&& v) noexcept{

        auto*p= new T [v.cpt];
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
    unsigned int Vector<T>::max_size() const noexcept {

            return size_type(-1);
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
        if(sz==cpt) cpt*=2;
        sz++;
        auto * newelementai = new T [cpt];

        for (unsigned int j = 0; j != *pos; ++j) newelementai[j] = elem[j];
        unsigned int index = pos - begin();
        newelementai[index]=elm;

        for (unsigned int i = *pos+1; i < sz; ++i) newelementai[i] = elem[i-1];

        delete[] elem;
        elem = newelementai;
    }

    template<class T>
    T* Vector<T>::insert(const T* pos, T&& elm){
        if(sz==cpt) cpt*=2;
        sz++;
        auto * newelementai = new T [cpt];
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
        if(cpt<sz+count) cpt*=2;
        sz+=count;

        auto * newelementai = new T [cpt];
        size_t index=0;
        for (auto i = begin(); i != pos; ++i) {

            newelementai[index]=*i;
            index++;
        }

        for (auto j = pos; j != pos+count; ++j){
            newelementai[index]=elm;
            index++;
        }

        for (auto k = pos; k != end() ; ++k) {

            newelementai[index]=*k;
            index++;
        }

        delete[] elem;
        elem = newelementai;

    }
    template<class T>
    T* Vector<T>::insert(const_iterator pos, InputIt first, InputIt last) {

        unsigned int count = last - first;

        if (cpt < sz + count) cpt *= 2;

        auto newelementai = new T[cpt];

        size_t k = 0;

        for (auto i = begin(); i != pos; ++i){
            newelementai[k] = (*i);
            k++;
        }

        for (auto  j = pos; j != pos+count; ++j) {
            newelementai[k]=*first;
            first++;
            k++;
        }
        for (auto i = pos; i != end(); ++i){
            newelementai[k]=(*i);
            k++;
        }
        sz += count;
        delete [] elem;
        elem = newelementai;

    }
    template <class T>
    T* Vector<T>::insert( const_iterator pos, std::initializer_list<T> elm ){

        size_t count = elm.size();
        if (cpt<sz+count) cpt*=2;

        auto newelementai = new T [cpt];
        size_t k = 0;
        for (auto i = begin(); i != pos; ++i) {
            newelementai[k] = *i;
            k++;
        }

        int index = 0;
        for (auto j = pos; j != pos+elm.size(); ++j) {

            T value = *(elm.begin()+index);
            index ++;

            newelementai[k]=value;
            k++;
        }
        for (auto i = pos; i != end(); ++i) {

            newelementai[k]=*i;
            k++;
        }

        sz+=count;
        delete [] elem;
        elem = newelementai;

    }

    template <typename T>
    template <class ... Args>
    T* Vector<T>::emplace(const T* pos, Args && ... args) {
        T* it = &elem[pos - elem];
        if (sz == cpt) {
            cpt *= 2;
            reserve(cpt);
        }
        memmove(it + 1, it, (sz - (pos - elem)) * sizeof(T));
        (*it) = std::move( T( std::forward<Args>(args) ... ) );
        ++sz;
        return it;
    }

    template<class T>
    T* Vector<T>::erase (T* pos){
        auto newelementai = new T [cpt];
        size_t index=0;
        for (auto i = begin(); i != pos; ++i) {
            newelementai[index]=*i;
            index++;
        }
        for (auto j = pos; j != end(); ++j) {
            newelementai[index]=*(j+1);
            index++;
        }
        delete [] elem;
        elem = newelementai;
        sz--;

    }
    template<class T>
    T* Vector<T>::erase(T* first, T* last ){
        auto newelementai = new T [cpt];
        auto diff=last-first;
        size_t index=0;
        for (auto i = begin(); i != first+1; ++i) {
            newelementai[index]=*i;
            index++;
        }
        for (auto j = last-1; j !=end(); ++j) {
            newelementai[index]=*(j+diff);
            index++;
        }
        delete [] elem;
        elem = newelementai;
        sz-=diff;

    }

    template<class T>
    void Vector<T>::push_back(const T& value)
    {
        if (sz >= cpt) {
            cpt*=2;
            reserve(cpt);
        }
        sz++;
        elem [sz] = value;

    }
    template<class T>
    void Vector<T>::push_back(T&& value)
    {
        if (sz >= cpt) {
            cpt*=2;

        }
        sz++;
        elem [sz] = std::move(value);

    }


    template <class T>
    template< class... Args >
    void Vector<T>::emplace_back( Args&&... args){
        if(sz==cpt) cpt*=2;
        elem[sz] = std::move( T( std::forward<Args>(args) ... ) );
        sz++;
    }

    template<class T>
    void Vector<T>::reserve(size_t newtalpa){
        if(newtalpa>cpt){
            cpt=newtalpa;
            auto * newelementai = new T [cpt];
            for (unsigned int i = 0; i <sz; i++) newelementai[i] = elem[i];
            delete[] elem;
            elem = newelementai;

        }
    }
    template<class T>
    void Vector<T>::resize (unsigned int newdydis){

        if (cpt<newdydis)  cpt=newdydis;

            auto *  newelementai= new T [cpt];
            for (unsigned int i = 0; i != sz; i++) newelementai[i] = elem[i];
            sz=newdydis;

            delete[] elem;
            elem = newelementai ;

    }

    template<class T>
    void Vector<T>::resize(unsigned int count, const T& value ){

        if (cpt<count) cpt=count;

        auto * newelementai = new T [cpt];

        for (unsigned int i = 0; i != size(); i++) newelementai[i] = elem[i];
        for (unsigned int j = sz; j < sz+count; ++j) newelementai[j]=value;

        sz=count;

        delete[] elem;
        elem = newelementai;
    }

    template<class T>
    void Vector<T>::pop_back(){
        sz--;
        auto * newelementai = new T [cpt];
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
