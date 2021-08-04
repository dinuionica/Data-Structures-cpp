#ifndef __CIRCULA_LINKED_LIST__
#define __CIRCULA_LINKED_LIST__


#include <iostream>
#include <string>
template <typename T>

// class of a node
class Node {
public:
    T data;
    Node *next;
};

// class of a circular linked list
template <typename T>
class CircularLinkedList {

public:
    int size;
    Node<T> *head;

    // constructor
    CircularLinkedList() {
        this->size = 0;
        this->head = NULL;
    }

    // the function that add a new number 
    void add(int position, T new_value) {

        Node<T> *new_node = new Node<T>;
        new_node->data = new_value;

        // check if the list is empty
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            size++;

        } else if (position == 0) {
            // insert at the first position
            Node<T> *temp = head;
            Node<T> *current = head;
            while (current->next != head) {
                current = current->next;
            }
            head = new_node;
            new_node->next = temp;
            current->next = head;
            size++;

        }  else if (position > size) {
            // insert at the last position
            Node<T> *current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = head;
            size++;
        } else {
            // insert at the specific position
            Node<T> *current = head;
            int count = 0;
            while (count != position - 1) {
                current = current->next;
                count++;
            }
            new_node->next = current->next;
            current->next = new_node;
            size++;
        }
    }

    // the function that remove an element
    void remove(int position) {

        // check if the list is empty
        if (head == NULL) {
            return;
        }
        
        // if the list has only element
        if (head->next == head && position == 0) {
            delete head;
            head = NULL;
            head->next = NULL;
            size--;
        } else if (position == 0) {
            // find tail node and remove from position 0
            Node<T> *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            Node<T> *temp_head = head->next;
            delete head;
            head = temp_head;
            tail->next = temp_head;
            size--;
        } else if (position >= (size - 1)) {
            // remove from last position
            Node<T> *previous = NULL;
            Node<T> *tail = head;
            while (tail->next != head) {
                previous = tail;
                tail = tail->next;
            }
            previous->next = head;
            delete tail;
            size--;
        } else {
            // remove from a specifc position
            Node<T> *current = head;
            for (int i = 0; current != head && i < position - 1; ++i) {
                current = current->next;
            }
            if (current == head && current->next == head) {
                return;
            }
            Node<T> *next_node = current->next->next;
            delete current->next;
            current->next = next_node;
            size--;
        }
    }

    // the function that print tail and head of the list
    void print_tail_head() {
        Node<T> *current = head;
        while (current->next != head) {
            current = current->next;
        }
        std::cout << " Current tail data: " << current->data;
        std::cout << " Current head data: " << current->next->data; 
        std::cout <<"\n";
    }

    // the function that print elements of the list
    void print_elements() {
        Node<T> *current = head;
        while (current->next != head) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << current->data << "\n";
    }

    // the function that print current size of the list
    void print_size() {
        std::cout << "Current size: " << size << "\n";
    }
};

#endif // __CIRCULA_LINKED_LIST__
