// Fraction.h

#pragma once
#include <iostream>


class Fraction {
    private:
        int num, den;
        bool isVaild(int _num, int _den);
        void simplify();
        float equal() const;
    public:
        Fraction(int _num, int _den);
        Fraction(int random);
        Fraction();
        friend std::ostream& operator<<(std::ostream& os, const Fraction _Frac);
        friend std::istream& operator>>(std::istream& is, Fraction &_Frac);
        Fraction operator++();    //Tien to
        Fraction operator++(int); //Hau to
        Fraction operator--();    //Tien to
        Fraction operator--(int); //Hau to
        friend Fraction operator+(Fraction left, Fraction right);
        friend Fraction operator-(Fraction left, Fraction right);
        friend Fraction operator*(Fraction left, Fraction right);
        friend Fraction operator/(Fraction left, Fraction right);
        friend bool operator<(const Fraction _Frac1, const Fraction _Frac2);
        friend bool operator>(const Fraction _Frac1, const Fraction _Frac2);
        friend bool operator==(const Fraction _Frac1, const Fraction _Frac2);
        friend bool operator!=(const Fraction _Frac1, const Fraction _Frac2);

};