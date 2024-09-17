#include <iostream>
#include <cmath>

using namespace std;
//using std::cout;
//using std::cin;

int main(){
    double x, k, slag, sum1, sum2;
    int step = 2;
    cin >> x >> k;
    slag = -x / 2;
    sum1 = 1 / (pow(1 + x, 0.5));
    sum2 = 1;
    while (abs(slag) >= pow(10, -k)){
        sum2 = sum2 + slag;
        step = step + 2;
        slag = slag * (-1) * x / step * abs(step - 3);
    }
    cout.precision(10); 
    if (sum1 > sum2) cout << sum1 << ' > ' << sum2;
    else{
        if (sum1 == sum2) cout << sum1 << ' = ' << sum2;
        else cout << sum1 << ' < ' << sum2;
    }
    cout << endl;
    cout << sum2;
    return 0;
}