#include <iostream>

using namespace std;

int main() {
	int a = 2, res;
	__asm {
		mov eax, 1
		mov ebx, 12
	BEGC1:
		imul eax, a
		sub ebx, 1
		cmp ebx, 0
		jne BEGC1
		mov res, eax
		mov edx, res
		mov eax, 1
		mov ebx, 8
	BEGC2:
		imul eax, a
		sub ebx, 1
		cmp ebx, 0
		jne BEGC2
		mov res, eax
		add edx, res
		add edx, a
		mov res, edx
	}
	cout << res;
	return 0;
}