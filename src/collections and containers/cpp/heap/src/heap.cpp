#include "heap.h"

template <class T>
Heap<T>::Heap(std::function<bool(T, T)> comp) : data{T()}, comp(comp) {}

template <class T>
MinHeap<T>::MinHeap() : Heap<T>([](const T &a, const T &b) { return a < b; }) {}

template <class T>
MaxHeap<T>::MaxHeap() : Heap<T>([](const T &a, const T &b) { return a > b; }) {}

template <class T> void Heap<T>::push(const T &val) {
  data.emplace_back(val);

  auto index = data.size() - 1;
  while (parentIdx(index) != -1 && comp(data[index], data[parentIdx(index)])) {
    std::iter_swap(data.begin() + index, data.begin() + parentIdx(index));
    index = parentIdx(index);
  }
}

template <class T> T Heap<T>::pop() {
  assertNotEmpty();

  T firstElement = peek();
  int index = 0;
  data[index] = data.back();

  data.erase(data.begin() + (data.size() - 1));

  while ((leftNodeIdx(index) != -1 &&
          comp(data[leftNodeIdx(index)], data[index])) ||
         (rightNodeIdx(index) != -1 &&
          comp(data[rightNodeIdx(index)], data[index]))) {

    int leftIdx = leftNodeIdx(index);
    int rightIdx = rightNodeIdx(index);

    int swapIdx;
    if (leftIdx == -1)
      swapIdx = rightIdx;
    else if (rightIdx == -1)
      swapIdx = leftIdx;
    else
      swapIdx = comp(data[leftIdx], data[rightIdx]) ? leftIdx : rightIdx;

    std::iter_swap(data.begin() + index, data.begin() + swapIdx);
    index = swapIdx;
  }

  return firstElement;
}

template <class T> T Heap<T>::peek() {
  assertNotEmpty();

  if (isMaxHeap())
    return data.front();

  return data[1];
}

template <class T> void Heap<T>::assertNotEmpty() {
  if (empty())
    throw std::invalid_argument("Heap is empty.");
}

template <class T> unsigned int Heap<T>::size() { return data.size() - 1; }

template <class T> bool Heap<T>::empty() { return data.size() <= 1; }

template <class T> bool Heap<T>::isMaxHeap() { return comp(2, 1); }

template <class T> bool Heap<T>::isMinHeap() { return comp(1, 2); }

template <class T> int Heap<T>::leftNodeIdx(int index) {
  unsigned int result = index * 2;
  if (result >= data.size())
    return -1;

  return result;
}

template <class T> int Heap<T>::rightNodeIdx(int index) {
  unsigned int result = index * 2 + 1;
  if (result >= data.size())
    return -1;

  return result;
}

template <class T> int Heap<T>::parentIdx(int index) {
  if (index <= 0)
    return -1;

  return index / 2;
}

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
