// Fraction.cpp

#include "Fraction.h"
#include <iostream>
#include <ctime>

using namespace std;

Fraction::Fraction(int _num, int _den) {
    if (isVaild(_num, _den)) {
        this->num = _num;
        this->den = _den;
    }
    else {
        this->num = 0;
        this->den = 1;
    }
}

Fraction::Fraction(int random) {
    int _num = rand() % (random+1);
    int _den = rand() % (random+1);
    if (isVaild(_num, _den)) {      
        this->num = _num;
        this->den = _den;
    }
    else {
        this->num = 0;
        this->den = 1;
    }
    
}

Fraction::Fraction(){
    this->num = 0;
    this->den = 1;
}

bool Fraction::isVaild(int _num, int _den) {
    return (_den != 0);
}

void Fraction::simplify() {
    if (this->den % this->num == 0 && this->num != 0) {
        this->den /= this->num; 
        this->num /= this->num; 
    }
}

float Fraction::equal() const {
    return ((float)this->num / this->den);
}

std::ostream &operator<<(std::ostream &os, const Fraction _Frac) {
    os << _Frac.num << '/' << _Frac.den;
    return os;
}

istream &operator>>(istream &is, Fraction &_Frac) {
    is >> _Frac.num >> _Frac.den;
    return is;
}

Fraction Fraction::operator++() {
    this->num += this->den;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    this->num += this->den;
    return temp;
}

Fraction Fraction::operator--() {
    this->num -= this->den;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    this->num -= this->den;
    return temp;
}

Fraction operator-(Fraction left, Fraction right) {
    Fraction temp(0, 1);
    temp.num = (left.num * right.den) - (right.num * left.den);
    temp.den = left.den * right.den;
    return temp;
}

Fraction operator+(Fraction left, Fraction right) {
    Fraction temp(0, 1);
    temp.num = (left.num * right.den) + (right.num * left.den);
    temp.den = left.den * right.den;
    return temp;
}

Fraction operator*(Fraction left, Fraction right) {
    Fraction temp(0, 1);
    temp.num = left.num * right.num;
    temp.den = left.den * right.den;
    temp.simplify();
    return temp;
}

Fraction operator/(Fraction left, Fraction right) {
    Fraction temp(0, 1);
    temp.num = left.num * right.den;
    temp.den = right.num * left.den;
    if(temp.den < 0) {
        temp.den *= -1;
        temp.num *= -1;
    }
    return temp;
}

bool operator<(const Fraction _Frac1, const Fraction _Frac2) {
    return (_Frac1.equal() < _Frac2.equal());
}

bool operator>(const Fraction _Frac1, const Fraction _Frac2) {
    return (_Frac1.equal() > _Frac2.equal());
}

bool operator==(const Fraction _Frac1, const Fraction _Frac2) {
    return (_Frac1.equal() == _Frac2.equal());
}

bool operator!=(const Fraction _Frac1, const Fraction _Frac2) {
    return (_Frac1.equal() != _Frac2.equal());
}

