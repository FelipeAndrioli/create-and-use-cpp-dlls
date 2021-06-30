#include <iostream>
#include <stdio.h>

class Calculation_Api {
    public:
        //virtual ~Calculation_Api();
        virtual void initialize();
        virtual int sum(int a, int b);
        virtual int multiply(int a, int b);
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

class API: public Calculation_Api {

};

extern "C" __declspec (dllexport) Calculation_Api* CreateAPI() {
    std::cout << "Creating API" << std::endl;
    Calculation_Api* calc_api = new API();
    return calc_api;
}