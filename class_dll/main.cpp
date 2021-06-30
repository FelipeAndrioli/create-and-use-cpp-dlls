#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {

    HINSTANCE mydll = LoadLibraryA("class_export.dll");

    std::cout << "Loading library" << std::endl;

    if (!mydll) {
        std::cout << "Could not load the library" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Library loaded successfully" << std::endl;
    

    return EXIT_SUCCESS;
}