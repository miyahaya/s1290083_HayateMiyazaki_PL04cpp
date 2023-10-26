// test_ArrayQueue.cpp
#include "ArrayQueue.h"
#include <iostream>

int main(void) {
    ArrayQueue queue1;

    // Testing enqueue
    queue1.enqueue("Hello");
    queue1.enqueue("World");
    queue1.enqueue("!");

    // Testing peek
    std::cout << "Peek: " << queue1.peek() << std::endl;

    // Testing dequeue
    queue1.dequeue();

    // Testing size
    std::cout << "Size: " << queue1.size() << std::endl;

    // Testing empty
    std::cout << "Empty: " << (queue1.empty() ? "true" : "false") << std::endl;

    // Testing copy constructor
    ArrayQueue queue2(queue1);
    std::cout << "Copied Queue Size: " << queue2.size() << std::endl;

    // Testing assignment operator
    ArrayQueue queue3;
    queue3 = queue1;
    std::cout << "Assigned Queue Size: " << queue3.size() << std::endl;

    return 0;
}