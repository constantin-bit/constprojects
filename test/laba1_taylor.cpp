#include <iostream>
#include <cmath>

using namespace std;
//using std::cout;
//using std::cin;

int main(){
    double x, k, n, s1, s2;
    int m = 2;
    cin >> x >> k;
    n = -x / 2;
    s1 = 1 / (pow(1 + x, 0.5));
    s2 = 1;
    while (abs(n) >= pow(10, -k)){
        s2 = s2 + n;
        m = m + 2;
        n = n * (-1) * x / m * abs(m - 3);
    }
    if (s1 > s2) cout << printf("%.5f", s1) << '>' << printf("%.5f", s2);
    else{
        if (s1 == s2) cout << printf("%.5f", s1) << '=' << printf("%.5f", s2);
        else cout << printf("%.5f", s1) << '<' << printf("%.5f", s2);
    }
    cout << endl;
    cout << printf("%.5f", s2);
    return 0;
}