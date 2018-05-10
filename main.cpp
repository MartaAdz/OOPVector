#include <iostream>
#include <algorithm>
#include <iterator>

class Vector{
private:

    double* elementai;
    int dydis;
    unsigned int talpa;


public:
    //KONSTRUKTORIAI
    Vector(): dydis(0), elementai(new double[dydis]), talpa(0) {}

    Vector(int d): dydis {d}, elementai{new double [dydis]}, talpa(d){
        std::fill_n(elementai, d, 0.0);
    }
    Vector(int d, double reiksme): dydis (d), elementai(new double [dydis]), talpa (d){
        std::fill_n(elementai, d, reiksme);
    }
    Vector(const Vector&v){
        elementai=new double [v.dydis];
        dydis=v.dydis;
        talpa=v.talpa;
        for (int i=0; i!=dydis; i++) elementai[i]=v.elementai[i];
    }

    Vector(std::initializer_list<double> elm)
    :dydis{static_cast<int>(elm.size())},
     elementai{new double[elm.size()],
     talpa=dydis}
    {
        std::copy(elm.begin(),elm.end(),elementai);
    }

    //DESTRUKTORIUS
    ~Vector() {delete[]elementai;}

    //OPERATORIAI
    double&operator[](int i){ return elementai[i];}
    const double&operator[](int i)const{ return elementai[i];}
    Vector& operator=(const Vector& v){double*p= new double[v.dydis];
    for (int i=0; i!=v.dydis; i++) p[i]=v.elementai[i];
    delete[]elementai;
    elementai=p;
    dydis=v.dydis;
    return *this;
    }

    //FUNKCIJOS

    bool isempty(){if (dydis==0) return true; }

    int size(){return dydis;}
    int capacity(){return talpa;}
    void clear(){
        delete [] elementai;
        dydis = 0;
    }

    const double& front(){return elementai[0]; }

    const double& back(){return elementai[dydis-1]; }

    void push_back(const double& naujas) {
        if(dydis==talpa) talpa+=3;
        elementai[dydis]=naujas;
        dydis++;
    }

};

int main() {
    Vector a{10};
    Vector b{10, 5.0};
    std::cout<<"dydis1: "<<b.size()<<std::endl;
    std::cout<<"talpa1 "<<b.capacity()<<std::endl;
    std::cout<<"pirmas galas "<<b.back()<<std::endl;
    b.push_back(3);
    b.back();
    std::cout<<"antras galas "<<b.size()<<std::endl;
    std::cout<<"dydis2 "<<b.size()<<std::endl;
    std::cout<<"talpa2 "<<b.capacity()<<std::endl;
    b.clear();
    std::cout<<b.size()<<std::endl;
    /*for (int i = 0; i != b.getsize() ; ++i) {
        std::cout<<b[i]<<std::endl;
    }*/



    return 0;
}