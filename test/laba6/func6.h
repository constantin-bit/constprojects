#pragma once
#include <cassert>
#include <cmath>

class proper_fraction{
    public:
        proper_fraction(int _numerator, int _denominator){
            numerator = _numerator;
            denominator = _denominator;
            assert(denominator != 0);
            assert(abs(numerator) < abs(denominator));
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
            if ((denominator != 0) && (numerator != 0) && (numerator != 1) && (abs(denominator) % abs(numerator) == 0)){
                int k = denominator / numerator;
                denominator /= k;
                numerator /= k;
            }
            division = double(numerator) / double(denominator);
            if (division > 0) sign = 1;
            if (division < 0) sign = -1;
            if (numerator != 0)    std::cout << sign * abs(numerator) << "/" << abs(denominator) << std::endl;
            else std::cout << 0 << std::endl;
        }
        proper_fraction operator+(const proper_fraction &b) const {
            return proper_fraction(numerator * b.denominator + denominator * b.numerator, denominator * b.denominator);
        }
        proper_fraction operator*(const proper_fraction &b) const {
            return proper_fraction(numerator * b.numerator, denominator * b.denominator);
        }
        proper_fraction operator/(const proper_fraction &b) const {
            assert(b.numerator != 0); 
            return proper_fraction(numerator / b.numerator, denominator / b.denominator);
        }
        proper_fraction operator+(const int &b) const {
            return proper_fraction(numerator + b * denominator, denominator);
        }
        proper_fraction operator*(const int &b) const {
            return proper_fraction(numerator * b, denominator);
        }
        proper_fraction operator/(const int &b) const {
            assert(b != 0);
            return proper_fraction(numerator / b, denominator);
        }
    private:
        int sign;
        int numerator;
        int denominator;
};