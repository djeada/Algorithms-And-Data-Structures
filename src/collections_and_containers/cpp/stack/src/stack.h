#include <string>

const std::string invalidSizeMsg = "Invalid Size";
const int defaultInitSize = 10;

template <class T> class Stack {

public:
  Stack();
  Stack(const Stack &other);
  ~Stack();
  T pop();
  void push(T element);
  T peek();
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
