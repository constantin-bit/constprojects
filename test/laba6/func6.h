#pragma once
#include <cassert>
#include <cmath>

class proper_fraction{
    public:
        proper_fraction(int _numerator, int _denominator){
            numerator = _numerator;
            denominator = _denominator;
            assert(denominator != 0);
        }
        int get_numerator() const{
            return numerator;
        }
        int get_denominator() const{
            return denominator;
        }
        proper_fraction(proper_fraction &other){
            numerator = other.numerator;
            denominator = other.denominator;
        }
        void output(){
            double division;
            if ((numerator != 0) && (numerator != 1)){
                int den = abs(denominator);
                int num = abs(numerator);
                while ((den != 0) && (num != 0)){
                    if (den > num) den = den % num;
                    else num = num % den;
                }
                numerator /= den + num;
                denominator /= den + num;
            }
            division = double(numerator) / double(denominator);
            if (division > 0) sign = 1;
            if (division < 0) sign = -1;
            if (numerator == 0)    std::cout << 0 << std::endl;
            else{
                if (abs(denominator) < abs(numerator)){
                    std::cout << sign * (abs(numerator) / abs(denominator)) << "," << sign * (abs(numerator) - (abs(numerator) / abs(denominator))* abs(denominator)) << "/" << abs(denominator) << std::endl;
                }
                else{
                    if (abs(denominator) != 1) std::cout << sign * abs(numerator) << "/" << abs(denominator) << std::endl;
                    else std::cout << sign * abs(numerator) << std::endl;
                }
            }
        }
        proper_fraction operator+(const proper_fraction &b) const {
            return proper_fraction(numerator * b.denominator + denominator * b.numerator, denominator * b.denominator);
        }
        proper_fraction operator*(const proper_fraction &b) const {
            return proper_fraction(numerator * b.numerator, denominator * b.denominator);
        }
        proper_fraction operator/(const proper_fraction &b) const {
            assert(b.numerator != 0); 
            return proper_fraction(numerator * b.denominator, denominator * b.numerator);
        }
        proper_fraction operator+(const int &b) const {
            return proper_fraction(numerator + b * denominator, denominator);
        }
        proper_fraction operator*(const int &b) const {
            return proper_fraction(numerator * b, denominator);
        }
        proper_fraction operator/(const int &b) const {
            assert(b != 0);
            return proper_fraction(numerator, b * denominator);
        }
    private:
        int sign;
        int numerator;
        int denominator;
};