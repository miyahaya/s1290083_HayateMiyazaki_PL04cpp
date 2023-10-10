# include <iostream> 
# include "queue.h"

class queue{
    private:
    int _num_items = 0; // number of elements in the queue
    int _max_size; // capacity of the fixed-size queue
    int _first; // index to the first element of the queue
    int _last; // index of the next available slot 
    Point* _items; // data container
    bool empty(){
        return _last < _first;
    }

    bool full(){
        return _last == _max_size - 1;
    }

    int size(){
        return _num_items;
    };

    void enqueue(Point point){
        if(full()){
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        _items[++_last] = point;
        _num_items++;
    };

    void dequeue(Point point){
        if(empty()){
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        _last--;
        _num_items--;
    };

    Point peek(){
        if(empty()){
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        _num_items--;
        return _items[_first++];
    }
};