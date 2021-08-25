#include <iostream>

using namespace std;

int binary_search(int *array, int size, int target) {
    int left = 0;
    int right = size;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return 1;
        } else if (array[mid] > target) {
            right = mid - 1;
        } else if (array[mid] < target) {
            left = mid + 1;
        }
    }
    return -1;
} 

int main(void) {

    int array[100], size = 0;
    // read element of array from input
    std::cin >> size;
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    int number;
    std::cin >> number;
    // binary_search
    if (binary_search(array, size - 1, number) == 1) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
    return 0;
}