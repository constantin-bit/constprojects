#include <iostream>

using namespace std;
//using std::cout;
//using std::cin;

int main(){
    int a,b;
    cin >> a >> b;
    while ((a != 0) && (b != 0)){
        if (a > b) a = a % b;
        else b = b % a;
    }
    cout << a + b;
    return 0;
}