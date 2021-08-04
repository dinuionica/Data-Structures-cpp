#include "doubly_circular_linkedlist.hpp"

int main(void) {

    // create list
    DoublyCircularLinkedList<int> doubly_circular_list;
    // insert new element
    doubly_circular_list.add(0, 1);
    doubly_circular_list.add(1, 2);
    doubly_circular_list.add(2, 3);
    doubly_circular_list.add(0, 5);

    // delete an element
    doubly_circular_list.remove(2);

    // print head and tail
    doubly_circular_list.print_tail_head();

    // print all elements
    doubly_circular_list.print_elements();
    return 0;
}