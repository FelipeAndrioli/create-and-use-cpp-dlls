#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

typedef void* (*VoidReturnFunc)();
extern "C" __declspec(dllimport) void* __stdcall createClass();

int main() {

    HINSTANCE dll = LoadLibraryA("mylib.dll");
    Interface* api;

    VoidReturnFunc myFunc;

    std::cout << "Loading library" << std::endl;

    if (!dll) {
        std::cout << "Could not load the library" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Library loaded successfully" << std::endl;

    std::cout << "Looking for function to create class" << std::endl;

    myFunc = (VoidReturnFunc)GetProcAddress(dll, "createClass");

    if (!myFunc) {
        std::cout << "Could not found function" << std::endl;
        return EXIT_FAILURE;
    }

    api = (Interface*) myFunc();
    api->initialize();

    return EXIT_SUCCESS;
}