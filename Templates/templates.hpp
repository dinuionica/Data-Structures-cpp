#ifndef __TEMPLATES__
#define __TEMPLATES__

#include <iostream>

 template <typename T>

T getmax(T number1, T number2) {
    if (number1 > number2) {
        return number1;
    }
    return number2;
} 

// implementation of an array with templates;

template <typename T>

class GenericArray {

private:
    T *generic_array;
public: 
    int size;
    int max_capacity;
    // constructor
    GenericArray(int max_size) {
        this->size = 0;
        this->max_capacity = max_size;

        generic_array = new T[max_size];
    }

    // destructor
    ~GenericArray() {
        delete[] generic_array;
    }

    T GetElement(T index) {
        return generic_array[index];
    }

    void AddElement(T new_element) {
        generic_array[size++] = new_element;
    }
    
    void ShowAllElements() {
        for (int i = 0; i < size; ++i) {
            std::cout << generic_array[i] << " ";
        }
    }
};


#endif //  __TEMPLATES__


