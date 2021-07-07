#include <iostream>
#include <windows.h>

#include "interface.h"

class CalcAPI : public Interface {
    void initialize();
};

void CalcAPI::initialize() {
    std::cout << "Initializing API" << std::endl;
}

extern "C" __declspec(dllexport) void* __stdcall createClass() {
    return static_cast<void*>(new CalcAPI);
}