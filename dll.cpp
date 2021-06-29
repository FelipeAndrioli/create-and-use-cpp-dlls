#include <iostream>
#include <stdio.h>

extern "C" void __declspec(dllexport) __stdcall funci() {
	std::cout << "Hello World!" << std::endl;
}
