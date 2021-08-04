#include <iostream>
#include <queue>

int main(void) {

    std::queue<int> my_queue;

    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    std::cout << my_queue.front() << "\n";

    my_queue.pop();

    std:: cout << my_queue.front() << "\n";

    std::cout << my_queue.empty() << "\n";

    std::cout << my_queue.size() << "\n";
    return 0;
}