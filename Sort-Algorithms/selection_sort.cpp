#include <iostream>


void selection_sort(int *array, int size) {
    int min_index = 0;
    // array iteration
    for (int i = 0; i < size - 1; ++i) {
        // find the minimum element in array
        min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        // swap the found minimum element with the first element
        std::swap(array[min_index], array[i]);
    }
}

int main(void) {
    int array[100], size = 0;
    // read array from input
    std::cin >> size;
    for (int  i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // sort using selection sort
    selection_sort(array, size);

    // print element of the sorted array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
