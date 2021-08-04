#ifndef __FUNCTIONS_INTRODUCTION__
#define __FUNCTIONS_INTRODUCTION__
#include <iostream>

// class example1
class Complex {

    double re;
    double im;

public:
    // constructor
    Complex(double real, double imaginar);

    void show();

    Complex conjugate();
};

Complex::Complex(double real, double imaginar) {
    this->re = real;
    this->im = imaginar;
};

void Complex::show() {
    std::cout << re << " + " << im << "i" << std::endl;
}

Complex Complex::conjugate() {
    Complex new_number(re, -im);
    return new_number;
    
}
#endif // __FUNCTIONS_INTRODUCTION__