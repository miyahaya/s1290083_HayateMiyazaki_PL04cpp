# include <iostream> 
# include "queue.h"
# include <optional>

struct QueueEmptyException : public std::exception {
    const char* what() const throw() {
        return "Queue is empty. Cannot dequeue.";
    }
};

class queue : Queue{
    private:
    int _num_items = 0; // number of elements in the queue
    int _max_size; // capacity of the fixed-size queue
    int _first; // index to the first element of the queue
    int _last; // index of the next available slot 
    Point *_items; // data container

    public:
    queue(int max_size = 100) : _max_size(max_size), _num_items(0), 
   _first(0), _last(0), _items(new Point[max_size]) {}
  ~queue() { delete[] _items; }

    bool empty(){
        return _last <= _first;
    }

    bool full(){
        return _last == _max_size;
    }

    int size(){
        return _num_items;
    };

    void enqueue(Point point){
        if(full()){
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        _items[_last] = point;
        _last++;
        _num_items++;
    };

    void dequeue(){
        if(empty()){
            std::cout << _last << _first << std::endl;
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Point *keep = new Point[100];
        for(int i = 0 ; i < _max_size - 1; i++){
            keep[i] = _items[i+1];
        }

        _items = keep;
        delete keep;
        _last--;
        _num_items--;
    };

    Point peek(){
        if(empty()){
            throw QueueEmptyException();
        }
        else {
            Point peek = _items[_first];
            Point *keep = new Point[_max_size];
            for(int i = 0 ; i < _max_size - 1; i++){
                keep[i] = _items[i+1];
            }

            _items = keep;
            delete keep;
            _last--;
            _num_items--;
            return peek;
        }
    }
};