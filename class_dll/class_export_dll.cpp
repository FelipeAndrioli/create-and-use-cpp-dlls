#include <iostream>
#include <stdio.h>

class Calculation_Api {
    public:
        void initialize();
        int sum(int a, int b);
        int multiply(int a, int b);
};

void Calculation_Api::initialize() {
    std::cout << "Calculation API initialized!" << std::endl;
}

int Calculation_Api::sum(int a, int b) {
    return a + b;
}

int Calculation_Api::multiply(int a, int b) {
    return a * b;
}

__declspec (dllexport) Calculation_Api* CreateAPI() {
    Calculation_Api* calc_api = new Calculation_Api();
    return calc_api;
}