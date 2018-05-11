//
// Created by Marta on 5/11/2018.
//

#ifndef UZDUOTYS_VECTOR_H
#define UZDUOTYS_VECTOR_H

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
    Vector& operator=(const Vector& v);
    //operator+

    //FUNKCIJOS

        //CAPACITY

    bool empty(){if (dydis==0) return true; }
    unsigned int size(){return dydis;}
    //max_size
    void reserve(size_t newtalpa);
    size_t capacity(){return talpa;}
    void shrink_to_fit(){ talpa=dydis;}

        //ELEMENT_ACCESS

    //at
    const double& front(){return elementai[0]; }
    const double& back(){return elementai[dydis-1]; }
    //data

        //MODIFIERS

    void clear();
    //insert
    //emplace
    void erase ();
    void push_back(const double& naujas);
    //emplace_back
    void resize (unsigned int newdydis);
    void pop_back();
    //swap

};

#endif //UZDUOTYS_VECTOR_H
