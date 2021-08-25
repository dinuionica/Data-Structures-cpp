#include <iostream>

int temp[100];

void merge_sort(int *array, int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2;
        // sort the two parts
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        // merge
        int i = left, j = mid + 1, size = 0;
        while (i <= mid && j <= right) {
            if (array[i] < array[j]) {
                temp[++size] = array[i++];
            } else {
                temp[++size] = array[j++];
            }
        }
        while (i <= mid) {
            temp[++size] = array[i++];
        }
         while (j <= right) {
            temp[++size] = array[j++];
        }
        for (int i = left, j = 1; i <= right; ++i, ++j) {
            array[i] = temp[j];
        }
    }
}

int main(void) {

    int array[100], size = 0;
    // read the array from input
    std::cin >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // sort using merge sort
    merge_sort(array, 0, size - 1);

    // print elements of the sorted array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    return 0;
}