#include "queue.hpp"

int main(void) {

    QUEUE<char> *my_queue = new QUEUE<char>;

    my_queue->enqueue('a');
    my_queue->enqueue('b');
    my_queue->enqueue('c');

    my_queue->show_all_elements();
    std::cout << "\n";
    
    my_queue->dequeue();

    my_queue->show_all_elements();
    return 0;
}