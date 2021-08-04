#include <iostream>

int Stack[20], top = -1;

void push(int new_value) {
    Stack[++top] = new_value;
}

void pop() {
    top--;
}

int front() {
    return Stack[top];
}

bool is_empty() {
    if (top == -1) {
        return true;
    }
    return false;
}

int main(void) {

    push(1);
    push(2);    
    push(3);    
    std::cout << front() << "\n";
    pop();
    std::cout << front() << "\n";
    return 0;
}