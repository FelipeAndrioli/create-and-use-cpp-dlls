#include <iostream>

#include "calc_api_interface.h"

class calc_api : public calc_api_interface {
    public:
        virtual void initialize();
        virtual int sum(int a, int b);
        virtual int multiply(int a, int b);
};

void calc_api::initialize() {
    std::cout << "Initializing library" << std::endl;
}

int calc_api::sum(int a, int b) {
    return a + b;
}

int calc_api::multiply(int a, int b) {
    return a * b;
}

extern "C" calc_api_interface* getDllClass() {
    static calc_api instance;
    return &instance;
}