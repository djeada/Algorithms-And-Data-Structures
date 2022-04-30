#include "subheap.h"
#include <algorithm>
#include <iostream>
#include <queue>

template <class T>
BinaryHeap<T>::BinaryHeap(std::vector<T>& arr) {
  heap = arr;
  // check if the array is a binary heap
  if (!is_binary_heap(heap)) {
    heap.clear();
    std::invalid_argument("The array is not a binary heap");
  }

}

template <class T>
BinaryHeap<T>::~BinaryHeap() {
  heap.clear();
}

template <class T>
void BinaryHeap<T>::insert(T value) {
  heap.push_back(value);
  int i = heap.size() - 1;
  while (i > 0 && heap[parent(i)] < heap[i]) {
    std::swap(heap[i], heap[parent(i)]);
    i = parent(i);
  }
}


template <class T>
T BinaryHeap<T>::remove() {
  auto root = heap[0];
  std::swap(heap[0], heap[heap.size() - 1]);
  heap.pop_back();
  heapify(0);
  return root;
}


template <class T>
T BinaryHeap<T>::peek() {
  return heap[0];
}


template <class T>
int BinaryHeap<T>::size() {
  return heap.size();
}


template <class T>
bool BinaryHeap<T>::isEmpty() {
  return heap.size() == 0;
}


template <class T>
void BinaryHeap<T>::print() {
  //for (int i = 0; i < heap.size(); i++) {
  //  std::cout << heap[i] << " ";
  //}
  std::cout << std::endl;
}


template <class T>
std::vector<T> BinaryHeap<T>::arrayRepresentation() {
  return heap;
}


template <class T>
bool BinaryHeap<T>::is_binary_heap(std::vector<T>& arr) {
   for (int i = 0; i < arr.size(); i++) {
       int left_child = 2*i+1;
       int right_child = 2*i+2;
       if (left_child < arr.size() && arr[left_child] < arr[i]) {
           return false;
       }
       if (right_child < arr.size() && arr[right_child] < arr[i]) {
           return false;
       }
   }

    return true;
}

template <class T>
BinaryHeap<T>& BinaryHeap<T>::operator=(const BinaryHeap<T>& other) {
  heap = other.heap;
  return *this;
}


template <class T>
BinaryHeap<T> BinaryHeap<T>::subHeap(int start, int end) {
  if (start < 0 || end >= heap.size()) {
    throw std::invalid_argument("start or end are out of range");
  }

  std::vector<T> sub_array;
    sub_array.push_back(heap[start]);
    std::queue<unsigned int> q;
    q.push(leftChild(start));
    q.push(rightChild(start));
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr < heap.size() && curr <= end) {
            sub_array.push_back(heap[curr]);
            q.push(leftChild(curr));
            q.push(rightChild(curr));
        }
    }
    return sub_array;
}


template <class T>
void BinaryHeap<T>::heapify(unsigned int i) {
  int left = leftChild(i);
  int right = rightChild(i);
  int largest = i;
  if (left < heap.size() && heap[left] > heap[i]) {
    largest = left;
  }
  if (right < heap.size() && heap[right] > heap[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(heap[i], heap[largest]);
    heapify(largest);
  }
}


template <class T>
unsigned int BinaryHeap<T>::leftChild(unsigned int i) {
  return 2*i+1;
}


template <class T>
unsigned int BinaryHeap<T>::rightChild(unsigned int i) {
  return 2*i+2;
}


template <class T>
unsigned int BinaryHeap<T>::parent(unsigned int i) {
  return (i-1)/2;
}


template class BinaryHeap<int>;
template class BinaryHeap<double>;
template class BinaryHeap<std::string>;
template class BinaryHeap<std::vector<int>>;
