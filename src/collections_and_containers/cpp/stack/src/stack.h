#include <string>

template <class T> class Stack {

public:
  Stack();
  Stack(const Stack &other);
  ~Stack();
  T pop();              // removes an element from the top of the stack
  void push(T element); // adds an element to the top of the stack
  T top();              // returns the element at the top of the stack
  int size();
  bool isEmpty();
  Stack &operator=(const Stack &other);

private:
  T *data;
  int n;
  int maxSize;
  void copy(const Stack &other);
  void expand();
};
