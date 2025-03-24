#include <iostream>

using namespace std;

int main() {
	int c1 = 0, c2 = 0;
	__asm {
		mov ebx, c2
		mov eax, c1
		imul eax, c1
		imul eax, 4
		sub eax, 1
		cmp eax, 4
		jl EXIT
		CYCL :
		sub eax, 4
			add ebx, 1
			cmp eax, 4
			jl EXIT
			jmp CYCL
			EXIT :
		mov c2, ebx
	}
	cout << "In assembler: " << c2 << endl;
	cout << "In C++: " << (4 * c1 * c1 - 1) / 4 << endl;
	return 0;
}