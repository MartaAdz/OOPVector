#include <iostream>
#include <algorithm>
#include <iterator>

class Vector{
private:

    double* elementai;
    unsigned int dydis;
    size_t talpa;


public:
    //KONSTRUKTORIAI
    Vector(): dydis(0), elementai(new double[dydis]), talpa(4) {}

    Vector(unsigned int d): dydis {d}, elementai{new double [dydis]}, talpa{d}{

        std::fill_n(elementai, d, 0.0);
    }

    Vector(unsigned int d, double reiksme): dydis (d), elementai(new double [dydis]), talpa (d){
        std::fill_n(elementai, d, reiksme);
    }

    Vector(const Vector&v){
        elementai=new double [v.dydis];
        dydis=v.dydis;
        talpa=v.talpa;
        for (int i=0; i!=dydis; i++) elementai[i]=v.elementai[i];
    }

    Vector(std::initializer_list<double> elm)
    :dydis{static_cast<unsigned int>(elm.size())},
     elementai{new double[elm.size()]}
    {
        std::copy(elm.begin(),elm.end(),elementai);
        talpa=dydis;
    }

    //DESTRUKTORIUS
    ~Vector() {delete[]elementai;}

    //OPERATORIAI
    double&operator[](int i){ return elementai[i];}
    const double&operator[](int i)const{ return elementai[i];}
    Vector& operator=(const Vector& v){auto*p= new double[v.dydis];
    for (int i=0; i!=v.dydis; i++) p[i]=v.elementai[i];
    delete[]elementai;
    elementai=p;
    dydis=v.dydis;
    return *this;
    }

    //FUNKCIJOS

    bool isempty(){if (dydis==0) return true; }

    int size(){return dydis;}
    size_t capacity(){return talpa;}

    void clear(){
        delete [] elementai;
        dydis = 0;
    }

    const double& front(){return elementai[0]; }

    const double& back(){return elementai[dydis-1]; }

    void push_back(const double& naujas)
    {
        if(dydis==talpa) talpa=talpa+3;

        elementai[dydis]=naujas;
        dydis++;
    }
    void reserve(size_t newtalpa){
        if(newtalpa>talpa){
            auto * newelementai = new double[newtalpa];
            for (unsigned int i = 0; i <dydis; i++)
                newelementai[i] = elementai[i];
            talpa=newtalpa;
            delete[] elementai;
            elementai = newelementai;
        }
    }
    void resize (unsigned int newdydis){
        if (newdydis<dydis){
            auto * newelementai = new double[newdydis];
            for (unsigned int i = 0; i != newdydis; i++)
                newelementai[i] = elementai[i];
            dydis=newdydis;
            delete[] elementai;
            elementai = newelementai;
        }

        else std::cerr<<"netinkamas parametras"<<std::endl;
    }
    void shrink_to_fit(){
         talpa=dydis;
    }
    void pop_back(){
        dydis--;
        auto * newelementai = new double[dydis];
        for (unsigned int i = 0; i != dydis; i++)
            newelementai[i] = elementai[i];

        delete[] elementai;
        elementai = newelementai;

    }


};

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