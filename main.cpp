#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int (__stdcall *f_funci)();

int main() {
	
	HINSTANCE mydll = LoadLibraryA("mylib.dll");

	std::cout << "Loading library" << std::endl;

	if (!mydll) {
		std::cout << "Could not load the library" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Library loaded successfully" << std::endl;

	f_funci funci = (f_funci)GetProcAddress(mydll, "funci");

	std::cout << "Locating function" << std::endl;

	if (!funci) {
		std::cout << "Could not locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "funci() returned " << funci() << std::endl;

	return EXIT_SUCCESS;
}
