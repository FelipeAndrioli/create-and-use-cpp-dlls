#include <iostream>
#include <stdio.h>

extern "C" __declspec(dllexport) int sum(int a, int b) {
	return a + b;
}

extern "C" __declspec(dllexport) int multiply(int a, int b) {
	return a * b;
}