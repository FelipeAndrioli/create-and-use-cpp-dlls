#include <iostream>
#include <windows.h>

#include "calc_api_interface.h"

typedef calc_api_interface* (*InitializeApi)();

int main() {

    std::cout << "Loading library" << std::endl;
    HINSTANCE dll = LoadLibraryA("mylib.dll");

    if (!dll) {
        std::cout << "Could not load the library" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Library loaded successfully" << std::endl;
    std::cout << "Searching for function to create a object" << std::endl;

    InitializeApi init_api = (InitializeApi)GetProcAddress(dll, "getDllClass");

    if (!init_api) {
        std::cout << "Could not found the function" << std::endl;
        return EXIT_FAILURE;
    }

    calc_api_interface* api_calc = init_api();
    api_calc->initialize();
    std::cout << api_calc->sum(10, 38) << std::endl;
    std::cout << api_calc->multiply(2, 25) << std::endl;    

    return EXIT_SUCCESS;
}