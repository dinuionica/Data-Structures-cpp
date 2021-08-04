#include <iostream>
#include <list>

int main(void) {
    std::list<int> my_list;

    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);

    my_list.remove(1);
    for (auto it:my_list) {
        std::cout << it << " ";
    }
    return 0;
}