// test_ArrayQueue.cpp
#include "ArrayQueue.h"
#include <iostream>

int main(void) {
    ArrayQueue queue;

    // Testing enqueue
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("!");

    // Testing peek
    std::cout << "Peek: " << queue.peek() << std::endl;

    // Testing dequeue
    queue.dequeue();

    // Testing size
    std::cout << "Size: " << queue.size() << std::endl;

    // Testing empty
    std::cout << "Empty: " << (queue.empty() ? "true" : "false") << std::endl;

    return 0;
}