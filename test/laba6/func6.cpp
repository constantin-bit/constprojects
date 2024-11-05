#include "func6.h"

proper_fraction operator+(const int &b, const proper_fraction &a){
    return proper_fraction(a.get_numerator() + b * a.get_denominator(), a.get_denominator());
}
proper_fraction operator*(const int &b, const proper_fraction &a){
    return proper_fraction(a.get_numerator() * b, a.get_denominator());
}
proper_fraction operator/(const int &b, const proper_fraction &a){
    return proper_fraction(b * a.get_denominator(), a.get_numerator());
}