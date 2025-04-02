#include <iostream>

using namespace std;

int main() {
	const int n = 20;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	__asm {
		cmp n, 2
		jge EXIT1
		jmp EXIT2
		EXIT1:
		mov a[1 * 4], 1
		mov eax, 1
		BEGC:
		add eax, 1
		cmp eax, n
		jne CYCL
		jmp EXIT2
		CYCL:
		mov ebx, a[eax * 4 - 4]
		add ebx, a[eax * 4 - 8]
		mov a[eax * 4], ebx
		jmp BEGC
		EXIT2:

	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
