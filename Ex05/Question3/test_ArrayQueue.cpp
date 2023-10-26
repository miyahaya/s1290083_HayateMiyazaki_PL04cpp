#include "ArrayQueue.h"
#include <iostream>

int main(void) {
    // Testing code from questions 1 and 2

    // Complete: Test the move operators and your implementation of the move semantic.
    ArrayQueue queue1;
    queue1.enqueue("Item 1");
    queue1.enqueue("Item 2");
    queue1.enqueue("Item 3");

    ArrayQueue queue2 = std::move(queue1); // Move constructor
    std::cout << "Queue 2 size: " << queue2.size() << std::endl;
    std::cout << "Queue 2 peek: " << queue2.peek() << std::endl;

    ArrayQueue queue3;
    queue3.enqueue("Item A");
    queue3.enqueue("Item B");

    queue3 = std::move(queue2); // Move assignment operator
    std::cout << "Queue 3 size: " << queue3.size() << std::endl;
    std::cout << "Queue 3 peek: " << queue3.peek() << std::endl;

    return 0;
}