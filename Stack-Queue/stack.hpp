#ifndef __STACK__
#define __STACK__
#include "linked_list.hpp"

template <typename T>

class Stack {
private:
    LinkedList<T> *stack = new LinkedList<T>;
    
public:
    // function to push a new elemnt in stack
    void push(T new_value) {
        stack->AddElement(new_value, 0);
    }

    // function to remove a element from the stack
    void pop() {
        stack->RemoveElement(0);
    }

    // return the top of the stack
    T front() {
        return stack->head->data;
    }

    // display all elements of the stack
    void show_elements() {
        stack->ShowElements();
    }

    // check if the stack is empty
    bool is_empty() {
        if (stack->head == NULL) {
            return true;
        }
        return false;
    }

};
#endif // __STACK