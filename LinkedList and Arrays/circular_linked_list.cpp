#include "circular_linked_list.hpp"

int main(void) {
    
    // create the list
    CircularLinkedList<int> circular_list;

    // adding number
    circular_list.add(0, 1);
    circular_list.add(1, 2);
    circular_list.add(2, 3);
    
    // removing from a position
    circular_list.remove(2);

    // print head and tail data
    circular_list.print_tail_head();
    
    // print all elements
    circular_list.print_elements();

    // print current size
    circular_list.print_size();
    return 0;
}
