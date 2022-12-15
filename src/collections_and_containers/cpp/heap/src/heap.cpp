#include "heap.h"
#include <stdexcept>

template <class T> Heap<T>::Heap(std::function<bool(T, T)> comp) {
  this->comp = comp;
}

template <class T> Heap<T>::Heap(const Heap &other) {
  this->data = other.data;
  this->comp = other.comp;
}

template <class T> void Heap<T>::push(const T &val) {
  data.push_back(val);
  int index = data.size() - 1;
  int parent = parentIdx(index);

  while (index > 0 && comp(data[index], data[parent])) {
    std::swap(data[index], data[parent]);
    index = parent;
    parent = parentIdx(index);
  }
}

template <class T> T Heap<T>::pop() {
  if (data.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }

  T val = data[0];
  data[0] = data[data.size() - 1];
  data.pop_back();

  int index = 0;
  int left = leftNodeIdx(index);
  int right = rightNodeIdx(index);

  while (left < data.size()) {
    int swapIdx = left;
    if (right < data.size() && comp(data[right], data[left])) {
      swapIdx = right;
    }

    if (comp(data[swapIdx], data[index])) {
      std::swap(data[swapIdx], data[index]);
      index = swapIdx;
      left = leftNodeIdx(index);
      right = rightNodeIdx(index);
    } else {
      break;
    }
  }

  return val;
}

template <class T> T Heap<T>::peek() {
  if (data.size() == 0) {
    throw std::out_of_range("Heap is empty");
  }

  return data[0];
}

template <class T> unsigned int Heap<T>::size() { return data.size(); }

template <class T> bool Heap<T>::empty() { return data.size() == 0; }

template <class T> bool Heap<T>::isMaxHeap() { return comp(2, 1); }

template <class T> bool Heap<T>::isMinHeap() { return comp(1, 2); }

template <class T> int Heap<T>::parentIdx(int index) { return (index - 1) / 2; }

template <class T> int Heap<T>::leftNodeIdx(int index) { return 2 * index + 1; }

template <class T> int Heap<T>::rightNodeIdx(int index) {
  return 2 * index + 2;
}

template <class T> MinHeap<T>::MinHeap() : Heap<T>(std::less<T>()) {}

template <class T> MaxHeap<T>::MaxHeap() : Heap<T>(std::greater<T>()) {}

template class Heap<int>;
template class Heap<float>;
template class Heap<double>;
template class Heap<char>;

template class MinHeap<int>;
template class MinHeap<float>;
template class MinHeap<double>;
template class MinHeap<char>;

template class MaxHeap<int>;
template class MaxHeap<float>;
template class MaxHeap<double>;
template class MaxHeap<char>;
