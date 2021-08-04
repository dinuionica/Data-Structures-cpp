#include <iostream>

int Queue[20], left = 1, right = 0;

void enqueue(int new_value) {
    Queue[++right] = new_value;
}

void dequeue() {
    left++;
}

bool is_empty() {
    if (left == 0) {
        return true;
    }
    return false;
}

int front() {
    return Queue[left];
}

int main(void) {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    std::cout << front();

    dequeue();

    std::cout << front();

    return 0;
}