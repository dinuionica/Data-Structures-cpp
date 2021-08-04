#ifndef __QUEUE__
#define __QUEUE__

#include <iostream>
#include "linked_list.hpp"


template <typename T>

class QUEUE {

private:
    LinkedList<T> *queue = new LinkedList<T>;

public:

    // function to check is the queue is empty
    bool is_empty() {
        if (queue->head == NULL) {
            return true;
        }
        return false;
    }

    // function to add a new element in queue
    void enqueue(T new_value) {
        queue->AddElement(new_value, 0);
    } 

    // function to remove a new element from the queue
    void dequeue() {
        if (!is_empty()) {
            queue->RemoveElement(queue->size + 1);
        }
    }

    // function to return the front elment of the queue
    T front() {
        if (!is_empty()) {
            return queue->head->data;
        } 
    }
    
    // function to display all element of the list
    void show_all_elements() {
        queue->ShowElements();
    }
    
};

#endif // __QUEUE__