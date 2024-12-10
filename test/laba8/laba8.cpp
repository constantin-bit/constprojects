#include <iostream>
#include "calc.cpp"
#include "stack.h"

using namespace std;

int main(){
    string str1 = "-((-2)+(-38))*(-6)";
    string str2 = "(28+3)*6";
    expression st1(str1);
    expression st2(str2);
    //st1.check();
    //st1.calculate();
    st1.check();
    st1.calculate();
    return 0;
}