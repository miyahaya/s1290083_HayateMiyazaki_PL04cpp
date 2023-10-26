// ArrayQueue.h

#include <string>
#include <iostream>

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

class ArrayQueue {
private:
    int _num_items; // number of items in the queue
    int _allocated_size; // size of memory allocated
    int _first; // index to the first element of the queue 
    int _last; // index of the next available slot 
    std::string* _items; // container 

    void resize(int max_size) {
        if (max_size == 0) max_size++;

        // Move stack to a new array of size max
        std::string* temp = new std::string[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[(i+_first)%_allocated_size];
        }
        delete[] _items;
        _items = temp;

        _first = 0; 
        _last = _num_items;
        _allocated_size = max_size;
    }

public:
    // Constructors:
    // Default constructor 
    ArrayQueue() : _num_items(0), _allocated_size(1), _first(0), _last(0), _items(new std::string[1]) {}

    explicit ArrayQueue(int allocated_size) : _num_items(0), _allocated_size(allocated_size), _first(0), _last(0), _items(new std::string[allocated_size]) {}

    // Copy constructor
    ArrayQueue(const ArrayQueue& other) : _num_items(other._num_items), _allocated_size(other._allocated_size), _first(other._first), _last(other._last), _items(new std::string[other._allocated_size]) {
        for (int i = 0; i < _num_items; ++i) {
            _items[i] = other._items[(i + _first) % _allocated_size];
        }
    }

    // Destructor:
    ~ArrayQueue() {
        delete[] _items;
    }

    // Assignment operator
    ArrayQueue& operator=(const ArrayQueue& other) {
        if (this != &other) {
            // Delete existing data
            delete[] _items;

            // Copy data from other
            _num_items = other._num_items;
            _allocated_size = other._allocated_size;
            _first = other._first;
            _last = other._last;
            _items = new std::string[other._allocated_size];
            for (int i = 0; i < _num_items; ++i) {
                _items[i] = other._items[(i + _first) % _allocated_size];
            }
        }
        return *this;
    }

    // Add an item to the queue 
    void enqueue(const std::string& item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_last++] = item; 
        if (_last == _allocated_size) _last = 0; // wrap 
        _num_items++; 
    }

    // Remove the item that was least recently added 
    void dequeue() {
        _num_items--;
        _first++; 
        if (_first == _allocated_size) _first = 0; // wrap 
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    // Access the top-most item 
    std::string peek() {
        return _items[_first];
    }

    // Check if the stack is empty 
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack 
    int size() const { return _num_items; }
};

#endif // ARRAY_QUEUE_H