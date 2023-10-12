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
        std::cout << "size: " << std::endl;
        return _num_items;
    };

    void enqueue(Point point){
        if(full()){
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        _items[_last] = point;
        std::cout << "enqueue: "<< "x = " << point.x << ", y = " << point.y << ", z = " << point.z << std::endl;
        _last++;
        _num_items++;
        // Displays information on the current queue.
        printStatus(_items,_first,_last);
        };

    void dequeue(){
        if(empty()){
            std::cout << "dequeue" << std::endl;
            throw QueueEmptyException();
        }
        Point *keep = new Point[100];
        for(int i = 0 ; i < _max_size - 1; i++){
            keep[i] = _items[i+1];
        }

        _items = keep;
        delete keep;
        _last--;
        _num_items--;
        std::cout << "dequeue" << std::endl;
        // Displays information on the current queue.
        printStatus(_items,_first,_last);
    };

    Point peek(){
        if(empty()){
            std::cout << "peek" << std::endl;
            throw QueueEmptyException();
        }
        else {

            // Rebuild the array and minus one index number for all elements.
            Point peek = _items[_first];
            Point *keep = new Point[_max_size];
            for(int i = 0 ; i < _max_size - 1; i++){
                keep[i] = _items[i+1];
            }

            _items = keep;
            delete keep;
            _last--;
            _num_items--;
            std::cout << "peek: "<< "x = " << peek.x << ", y = " << peek.y << ", z = " << peek.z << std::endl; 
            // Displays information on the current queue.
            printStatus(_items,_first,_last);
            return peek;
            
            
        }
    }

//　Function to output queue status
    void printStatus(Point *p, int first, int last){
        std::cout << "status" << std::endl;
        for(int i = first; i < last; i++){
            std::cout << p[i].x << " " << p[i].y << " " << p[i].z <<std::endl;
        }
        std::cout << "" << std::endl;
    }
};

