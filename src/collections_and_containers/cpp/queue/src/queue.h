#include <string>

template <class T> class Queue {

public:
  Queue();
  Queue(const Queue &other);
  ~Queue();
  void enqueue(T element); // adds an element to the end of the queue
  T dequeue();             // removes an element from the front of the queue
  T front();               // returns the element at the front of the queue
  T back();                // returns the element at the end of the queue
  int size();
  bool isEmpty();
  Queue &operator=(const Queue &other);

private:
  T *data;
  int head;
  int tail;
  int n;
  int maxSize;
  void copy(const Queue &other);
  void expand();
};
