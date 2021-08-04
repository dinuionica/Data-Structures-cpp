#ifndef __DOUBLY_CIRCULAR_LINKEDLIST
#define __DOUBLY_CIRCULAR_LINKEDLIST

#include <iostream>
#include <string>

template <typename T>

// class of a node
class Node {
public:
    T data;
    Node *next;
    Node *prev;
};

// class of a doubly circular linkedlist
template <typename T>
class DoublyCircularLinkedList {

public:
    int size;
    Node<T> *head;

    // constructor
    DoublyCircularLinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    // the function that add a new number in list
    void add(int position, int value) {

        Node<T> *new_node = new Node<T>();
        new_node->data = value;

        // check if the list is empty
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            new_node->prev = head;
            size++;
        } else if (position == 0) {
            // add at the first position
            Node<T> *last = head->prev;

            new_node->next = head;
            new_node->prev = last;
            last->next = new_node;
            head->prev = new_node;
            head = new_node;
            size++;
        } else if (position >= (size - 1)) {
            // add at the last position
            Node<T> *last = head->prev;
            new_node->next = head;
            head->prev = new_node;
            last->next = new_node;
            new_node->prev = last;
            size++;
        } else {
            // add at the specific position
            Node<T> *current = head;
            int count = 0;
            while (count != position - 1) {
                current = current->next;
            }
            new_node = current->next;
            new_node = current->next->next;
            new_node->prev = current;
            size++;
        }
    }

    // the function that remove an element
    void remove(int position) {
        
        // check if the list is empty
        if (head == NULL) {
            return;
        }

        // if the list has only one element
        if (head->next == head) {
            delete head;
            head = NULL;
            head->next = head->prev = NULL;
            size--;
        } else if (position == 0) {
            // remove from the first position
            Node<T> *last = head->prev;
            Node<T> *current_head = head->next;
            delete head;
            head = current_head;
            head->prev = last;
            last->next = head;
            size--;
        } else if (position >= (size - 1)) {
            // remove from the last position
            Node<T> *last = head->prev;
            head->prev = last->prev;
            last->prev->next = head;
            delete last;
            last->next = NULL;
            last->prev = NULL;
            size--;
        } else {
            
            // remove from a specific position
            Node<T> *current = head;
            Node<T> *previous = NULL;
            int count = 0;
            while (count != position - 1) {
                previous = current;
                current = current->next;
                count++;
            }

            previous->next = current->next;
            current->next->prev = previous;
            delete current;
            current->next = NULL;
            current->prev = NULL;
            size--;

        }
    }

    // the function that print head and tail 
    void print_tail_head() {
        std::cout << "Current head " << head->data << "\n";
        std::cout << "Current tail " << head->prev->data << "\n";
    }
    
    // the function that print all elements
    void print_elements() {
        Node<T> *current = head;
        while (current->next != head) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << current->data << "\n";
    }
};

#endif //  __DOUBLY_CIRCULAR_LINKEDLIST