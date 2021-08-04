#include "stack.hpp"

int main(void) {

    Stack<int> *stack = new Stack<int>;
    stack->push(3);
    stack->push(2);
    stack->pop();

    std::cout << stack->is_empty();

    std::cout << stack->front();
    
    stack->show_elements();

    return 0;
}