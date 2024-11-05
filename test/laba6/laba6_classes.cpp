#include <iostream>
#include "func6.cpp"

using namespace std;

int main(){
    proper_fraction d1(1, 4);
    cout << "d1=";
    d1.output();
    proper_fraction d2(d1);
    cout << "d2=";
    d2.output();
    cout << d1.get_numerator() << endl;
    cout << d1.get_denominator() << endl;
    proper_fraction d3 = d1 + d2;
    cout << "d3=";    
    d3.output();   
    proper_fraction d4 = d1 * 3;
    cout << "d4=";
    d4.output();
    proper_fraction d5 = d1 / -7;
    cout << "d5=";
    d5.output();
    proper_fraction d6 = d4 * d2;
    cout << "d6=";  
    d6.output();   
    proper_fraction d7 = d3 / d4;
    cout << "d7="; 
    d7.output();   
    //proper_fraction d8 = d1 + 1;//not proper fraction, error
    //d8.output();
    proper_fraction d9 = d7 + d1;
    cout << "d9="; 
    d9.output();   
    proper_fraction d10 = d9 * d3;
    cout << "d10="; 
    d10.output();
    //proper_fraction d11 = d9 / 0;//div 0, error
    //d11.output();
    proper_fraction d12 = -1 + d2;
    cout << "d12=";
    d12.output();
    proper_fraction d13 = 2 * d1;
    cout << "d13=";
    d13.output();
    proper_fraction d14 = 0 / d13;
    cout << "d14=";
    d14.output();
    return 0;
}