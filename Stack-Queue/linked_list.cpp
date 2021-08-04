#include "linked_list.hpp"

int main(void) {

    LinkedList<char> list;
    list.AddElement('a', 0);
    list.AddElement('b', 1);
    list.AddElement('c', 2);
    list.Reverse();
    list.ShowElements();
    return 0;
}