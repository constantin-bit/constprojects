#include <iostream>

using namespace std;

int main() {
	int c1 = 56, c2 = 0;
	__asm {
		mov ecx, 0
		mov ebx, 0
		mov eax, c1
		imul eax, c1
		BEG_CYCL :
		cmp eax, 10
			jl EXIT
			CYCL :
		sub eax, 10
			add ebx, 1
			cmp eax, 10
			jl EXIT
			jmp CYCL
			EXIT :
		cmp eax, 3
			je ACT
			jmp EXIT2
			ACT :
		add ecx, 1
			EXIT2 :
			mov c1, ebx
			mov eax, c1
			mov ebx, 0
			cmp eax, 0
			jne BEG_CYCL
			mov c2, ecx
	}
	cout << c2;
	return 0;
}