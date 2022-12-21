#include <functional>
#include <memory>
#include <vector>


template <class T> class Heap {

public:
  Heap(std::function<bool(T, T)> comp);
  Heap(const Heap &other);

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

  int parentIdx(int index);
  int leftNodeIdx(int index);
  int rightNodeIdx(int index);
};

template <class T> class MinHeap : public Heap<T> {
public:
  MinHeap();
};

template <class T> class MaxHeap : public Heap<T> {
public:
  MaxHeap();
};
