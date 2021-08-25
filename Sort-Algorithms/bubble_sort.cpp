#include <iostream>

void bubble_sort(int *array, int size) {
    // array iteration
    for (int step = 0; step < size; ++step) {
        bool is_sorted = true;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                // swap elements that doesn't respect the wanted order
                std::swap(array[i], array[i + 1]);
                is_sorted = false;
            }
        } 
        // if array is already sorted stop the program
        if (is_sorted == true) {
            return;
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

    // sort using bubble sort
    bubble_sort(array, size);

    // print element of the sorted array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
