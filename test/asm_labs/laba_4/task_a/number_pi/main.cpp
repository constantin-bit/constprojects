#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	long float pi = 3.141592653589793;
	long float a = 0.0;
	/*for (int i = 1; i < 10000; i++) {
		__asm {
			MOV eax, i
			BEGC:
			cmp eax, 0
			jle EXIT1
			sub eax, 2
			jmp BEGC
			EXIT1:
			cmp eax, 0
				FLD1
				FILD i
				FDIV
				FILD i
				FDIV
				FLD a
			je SIT
			FADD ST, ST(1)
			jmp EXIT2
			SIT:
			FSUB ST, ST(1)
			EXIT2:
			FXCH
			FSTP a
			FSTP a
		}
		cout << i << " " << fixed << setprecision(15) << pow(12 * a, 0.5) << endl;
	}*/
	for (int i = 1; i < 5000; i++) {
		long float a = 0.0;
		int b = 0;
		__asm {
			mov eax, i
			BEGC1:
			cmp eax, 1
			jl	EXIT1
				mov b, eax
				mov ebx, b
				BEGC2:
				cmp ebx, 0
				jle EXIT2
					sub ebx, 2
					jmp BEGC2
				EXIT2 :
				cmp ebx, 0
					FLD1
					FILD b
					FDIV
					FILD b
					FDIV
					FLD a
				je SIT
					FADD ST, ST(1)
				jmp EXIT3
				SIT :
					FSUB ST, ST(1)
				EXIT3 :
				FXCH
				FSTP a
				FSTP a
				sub eax, 1
				jmp BEGC1
			EXIT1:
			mov b, 12
			FILD b
			FLD a
			FMUL ST, ST(1)
			FSQRT
			FXCH
			FSTP a
			FSTP a
		}
		cout << i << "--" << fixed << setprecision(15) << a << endl;
	}
	cout << "pi:   " << fixed << setprecision(15) << pi << endl;
	return 0;
}
/*#include <iostream>

using namespace std;

int main() {
	float a = 10.2;
	float b = 5.7;
	float c = 0;

	float d = 14.2;
	float PI = 0;
	__asm {
		FLD b
		FLD a
		FLDPI
		FSUB ST, ST(2)
		FSTP PI
		FSTP a
		FSTP b
	}

	cout << PI << endl;
	cout << a << endl;

	cout << b << endl;

	a = 3.2;
	__asm {
		;finit
		FLDZ
		FLD a
		FCOM
		;FCOMI ST, ST(1)
		FSTSW ax
		SAHF
		jz EXIT1
		FLDPI
		FSTP a
		EXIT1:
	}
	cout << a << endl;
	return 0;
}*/