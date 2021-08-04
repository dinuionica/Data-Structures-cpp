#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <string>

template <class T>
// class of a node
class Node {
public:
    Node<T> *next;
    T data;
};

template <class T>
// class of a LinkedList
class LinkedList {
public:
    Node<T> *head;
    int size;
    // constructor
    LinkedList() {
        this->head = NULL;
        this->size = 0;
    }

    // function to add a new number in list
    void AddElement(T value, int pos) {
        // create a new node
        Node<T> *new_node = new Node<T>;
        new_node->data = value;
        // check if the list is empty
        if (head == NULL) {
            head = new_node;
            new_node->next = NULL;
            size++;
        } else if (pos == 0) {
            // add at the first position
            Node<T> *temp_node = head;
            head = new_node;
            new_node->next = temp_node;
            size++;
        } else if (pos >= size) {
            // add at the last position
            Node<T> *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = NULL;
            size++;
        } else {
            // add at a specific position
            int count = 0;
            Node<T> *current_node = head;
            while (count != pos - 1) {
                current_node = current_node->next;
                count++;
            }  
            new_node->next = current_node->next;
            current_node->next = new_node;
            size++;

        }
    }

    // function to remove a number from a position 
    void RemoveElement(int pos) {
        // check if the list is empty
        if (head == NULL) {
            return;
        } else if (head->next == NULL) {
            // check if the list has one number
            delete head;
            size = 0;
        } else if (pos == 0) {
            // remove from first position
            Node<T> *temp_node = head->next;
            delete head;
            head = temp_node;
            size--;
        } else if (pos > size) {
            // remove from last position
            Node<T> *current_node = head;
            Node<T> *previous_node = NULL;
            while (current_node->next != NULL) {
                previous_node = current_node;
                current_node = current_node->next;
            }
            delete current_node;
            previous_node->next = NULL;
            size--;            
        } else {
            // remove from specific position
            Node<T> *current_node = head;
            for (int i = 1; current_node != NULL && i < pos - 1; ++i) {
                current_node = current_node->next;
            }
            if (current_node == NULL || current_node->next == NULL) {
                return;
            }
            Node<T> *next_node = current_node->next->next;
            delete current_node->next;
            current_node->next = next_node;
           
        }
    }

    // function to display all elements of the list
    void ShowElements() {
        Node<T> *current = head;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

    // function to reverse a list
    void Reverse() {
        Node<T> *previous_node = NULL;
        Node<T> *current_node = head;
        while (current_node != NULL) {
            Node<T> *next_node = current_node->next;
            current_node->next = previous_node;
            previous_node = current_node;
            current_node = next_node;
        }
        head = previous_node;
    }
};

#endif // __LINKED_LIST__
