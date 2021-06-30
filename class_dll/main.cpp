#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int (__stdcall *dll_create_api)();

int main() {

    HINSTANCE mydll = LoadLibraryA("class_export.dll");

    std::cout << "Loading library" << std::endl;

    if (!mydll) {
        std::cout << "Could not load the library" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Library loaded successfully" << std::endl;

    dll_create_api create_api_function = (dll_create_api)GetProcAddress(mydll, "CreateAPI");

    std::cout << "Locating function" << std::endl;

    if (!create_api_function) {
        std::cout << "Could not locate the function" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "create_api_function() " << create_api_function() << std::endl;

    return EXIT_SUCCESS;
}