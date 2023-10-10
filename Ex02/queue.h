#ifndef QUEUE_H
#define QUEUE_H

// Insert the relevant headers here 

// Define a struct for representing three dimensional points with integral coordinates 
struct Point {
// Complete 
public: int x, y, z;
};


// Class for representing a queue 
class Queue {
public:
 // Constructor: It allocates memory for an array of size max_size
 Queue(int max_size=100) : _max_size(max_size), _num_items(0), 
   _first(0), _last(0), _items(new Point[max_size]) {}

 ~Queue() { delete[] _items; }

 // Interface
 
 // Check whether the queue is empty 
 // (the implementation will go in queue.cpp)
 bool empty();

 // Check whether the queue is full
 // (the implementation will go in queue.cpp)
 bool full();

 // Return the number of elements in the queue 
 // (the implementation will go in queue.cpp)
 int size();

 // Insert an element in the queue 
 // print an error message on std::cerr and exit in case of overflow
 // (the implementation will go in queue.cpp)
 void enqueue(Point);

 // Remove an element from the queue 
 // print an error message on std::cerr and exit in case of underflow
 // (the implementation will go in queue.cpp)
 void dequeue();

 // Acces the least recently added element
 // (the implementation will go in queue.cpp)
 Point peek();

private:
  int _num_items; // number of elements in the queue
  int _max_size; // capacity of the fixed-size queue
  int _first; // index to the first element of the queue
  int _last; // index of the next available slot 
  Point* _items; // data container 

};
#endif 