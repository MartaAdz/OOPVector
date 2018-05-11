//
// Created by Marta on 5/11/2018.
//
#include<iostream>
#include<algorithm>
#include "vector.h"


    //OPERATORIAI

    Vector& Vector::operator=(const Vector& v){
        auto*p= new double[v.dydis];
        for (int i=0; i!=v.dydis; i++) p[i]=v.elementai[i];
        delete[]elementai;
        elementai=p;
        dydis=v.dydis;
        return *this;
    }

    //FUNKCIJOS


    void Vector::clear(){
        delete [] elementai;
        dydis = 0;
    }

    void Vector::push_back(const double& naujas)
    {
        if(dydis==talpa) talpa=talpa+3;

        elementai[dydis]=naujas;
        dydis++;
    }
    void Vector::reserve(size_t newtalpa){
        if(newtalpa>talpa){
            auto * newelementai = new double[newtalpa];
            for (unsigned int i = 0; i <dydis; i++)
                newelementai[i] = elementai[i];
            talpa=newtalpa;
            delete[] elementai;
            elementai = newelementai;
        }
    }
    void Vector::resize (unsigned int newdydis){
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

    void Vector::pop_back(){
        dydis--;
        auto * newelementai = new double[dydis];
        for (unsigned int i = 0; i != dydis; i++)
            newelementai[i] = elementai[i];

        delete[] elementai;
        elementai = newelementai;

    }

