#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int (__stdcall *dll_sum_func)(int, int);
typedef int (__stdcall *dll_multiply_func)(int, int);

int main() {
	
	HINSTANCE mydll = LoadLibraryA("mylib.dll");

	std::cout << "Loading library" << std::endl;

	if (!mydll) {
		std::cout << "Could not load the library" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Library loaded successfully" << std::endl;

	dll_sum_func sum = (dll_sum_func)GetProcAddress(mydll, "sum");
	dll_multiply_func multiply = (dll_multiply_func)GetProcAddress(mydll, "multiply");

	std::cout << "Locating function" << std::endl;

	if (!sum || !multiply) {
		std::cout << "Could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "sum() returned " << sum(1, 1) << std::endl;
	std::cout << "multiply() returned " << multiply(5, 5) << std::endl;

	return EXIT_SUCCESS;
}
