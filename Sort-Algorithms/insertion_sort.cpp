#include <iostream>


void insertion_sort(int *array, int size) {
    // array iteration
    for (int i = 0; i < size; ++i) {
        int p = i;
        while ( p > 0 && array[p] < array[p - 1]) {
            // swap element of the two parts
            std::swap(array[p], array[p - 1]);
            p--;
        }
    }
}

int main(void) {
    int array[100], size = 0;
    // read array from input
    std::cin >> size;
    for (int  i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // sort using insertion sort
    insertion_sort(array, size);

    // print element of the sorted array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
