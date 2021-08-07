#include <functional>
#include <memory>
#include <vector>

template <class T> class Heap {

public:
  Heap(std::function<bool(T, T)> comp);

  void push(const T &val);
  T pop();
  T peek();
  unsigned int size();
  bool empty();
  bool isMaxHeap();
  bool isMinHeap();

private:
  std::vector<T> data;
  std::function<bool(const T &, const T &)> comp;

  int leftNodeIdx(int index);
  int rightNodeIdx(int index);
  int parentIdx(int index);
  void assertNotEmpty();
};

template <class T> class MinHeap : public Heap<T> {
public:
  MinHeap();
};

template <class T> class MaxHeap : public Heap<T> {
public:
  MaxHeap();
};
