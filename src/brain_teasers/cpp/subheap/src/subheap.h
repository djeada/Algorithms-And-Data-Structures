#include <vector>

template <class T> class BinaryHeap {

public:
  BinaryHeap(std::vector<T>&);
  ~BinaryHeap();
  void insert(T value);
  T remove();
  T peek();
  int size();
  bool isEmpty();
  void print();
  std::vector<T> arrayRepresentation();
  static bool is_binary_heap(std::vector<T>& arr);
  BinaryHeap<T>& operator=(const BinaryHeap<T>& other);
  BinaryHeap subHeap(int start, int end);

private:
  std::vector<T> heap;
  unsigned int leftChild(unsigned int i);
  unsigned int rightChild(unsigned int i);
  unsigned int parent(unsigned int i);
  void heapify(unsigned int i);

};
