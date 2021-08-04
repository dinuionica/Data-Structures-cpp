#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int> my_vector;

    my_vector.push_back(3);
    my_vector.push_back(1);
    my_vector.push_back(2);

    std::sort(my_vector.begin(), my_vector.end());

    for (auto it:my_vector) {
        std::cout << it << " ";
    }

    return 0;
}