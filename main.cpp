#include <iostream>
#include <algorithm>

class Vector{
private:

    double* elementai;
    int dydis;

public:
    //KONSTRUKTORIAI
    Vector(): dydis(0), elementai(new double[dydis]) {}

    Vector(int d): dydis {d}, elementai{new double [dydis]}{
        std::fill_n(elementai, d, 0.0);
    }
    Vector(int d, double reiksme): dydis (d), elementai(new double [dydis]){
        std::fill_n(elementai, d, reiksme);
    }
    Vector(const Vector&v){
        elementai=new double [v.dydis];
        dydis=v.dydis;
        for (int i=0; i!=dydis; i++) elementai[i]=v.elementai[i];
    }

    Vector(std::initializer_list<double> elm)
    :dydis{static_cast<int>(elm.size())},
     elementai{new double[elm.size()]}
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
    bool isempty(){ if (elementai[0]==elementai[dydis-1]) return true;}
    int getsize(){return dydis;}

    //void push_back( const& value );

};

int main() {
    Vector a{10};
    Vector b{10, 5.0};
    std::cout<<b.getsize();
    Vector v {1,3,4,5,6,8};
    for (int i = 0; i != v.getsize() ; ++i) {
        std::cout<<v[i];}
    return 0;
}