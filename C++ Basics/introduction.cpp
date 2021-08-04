#include "functions_introduction.hpp"
#include "header1.hpp"
#include "header2.hpp"

int main(void) {

    Complex number(2,3);
    number.show();

    Complex conjugate_number = number.conjugate();

    conjugate_number.show();

    // dynamic allocation of a class
    Complex *new_number = new Complex(4,3);
    new_number->show();

    // dynamic allocation of a vector
    int *array = new int[10];

    for (int i = 0; i <= 9; ++i) {
        array[i] = i;
    }

    for (int i = 0; i <= 9; ++i) {
        std::cout << array[i] << " ";
    }

    delete[] array;

    // dynamic allocation of a matrix
    int **matrix = new int*[10];
    for (int i = 0; i <= 9; ++i) {
        matrix[i] = new int[10];
    }

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            matrix[i][j] = 4;
        }
    }

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i <= 9; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // auto keyword
    auto d = 2.5;
    std::cout << d;

    // namespaces
    std::cout << first::number << second::number << '\n';
    return 0;
}