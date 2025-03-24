#include <iostream>

using namespace std;

int main() {
    _int16 a1 = 10, a2 = 1, a3 = 0, b1 = 1, b2 = 32767, b3 =0, c1 = 0, c2 = 0, c3 = 0;
    _asm {
            mov dx, 0
            mov ax, a1
            add ax, b1
            jmp EXIT1
        condition1:
            mov dx, 1
            add dx, 0
            add ax, 32768
        EXIT1:
            js condition1
            mov c1, ax
            add dx, a2
            add dx, b2
            jmp EXIT2
        condition2:
            mov cx, 1
            add dx, 0
            add dx, 32768
        EXIT2:
            js condition2
            mov c2, dx
            add cx, a3
            add cx, b3
            mov c3, cx
    }
    cout << hex << c3 << ", " << c2 << ", " << c1;
    cout << endl << dec << (unsigned long long)(c1 + c2 * pow(2, 16) + c3 * pow(2, 32));
    return 0;
}