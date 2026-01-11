#include "queue.h"
#include <stdexcept>

static constexpr int DEFAULT_INIT_SIZE = 16;

template <class T>
Queue<T>::Queue()
    : data(new T[DEFAULT_INIT_SIZE]), n(0), maxSize(DEFAULT_INIT_SIZE), head(0),
      tail(0) {}

template <class T> Queue<T>::Queue(const Queue &other) : data(nullptr) {
  copy(other);
}

template <class T> Queue<T>::~Queue() { delete[] data; }

template <class T> void Queue<T>::copy(const Queue &other) {
  n = other.n;
  maxSize = other.maxSize;
  head = other.head;
  tail = other.tail;

  data = new T[maxSize];
  for (int i = 0; i < maxSize; i++) {
    data[i] = other.data[i];
  }
}

template <class T> void Queue<T>::expand() {
  int newMaxSize = maxSize * 2;
  T *newData = new T[newMaxSize];

  // Copy elements in order from head to tail
  for (int i = 0; i < n; i++) {
    newData[i] = data[(head + i) % maxSize];
  }

  delete[] data;
  data = newData;
  head = 0;
  tail = n;
  maxSize = newMaxSize;
}

template <class T> T Queue<T>::dequeue() {
  if (n <= 0)
    throw std::out_of_range("Queue is empty");

  T element = data[head];
  head = (head + 1) % maxSize;
  n--;

  return element;
}

template <class T> void Queue<T>::enqueue(T element) {
  if (n >= maxSize)
    expand();

  data[tail] = element;
  tail = (tail + 1) % maxSize;
  n++;
}

template <class T> T Queue<T>::front() const {
  if (n <= 0)
    throw std::out_of_range("Queue is empty");

  return data[head];
}

template <class T> T Queue<T>::back() const {
  if (n <= 0)
    throw std::out_of_range("Queue is empty");

  // tail points to next empty slot, so back is at (tail - 1 + maxSize) % maxSize
  return data[(tail - 1 + maxSize) % maxSize];
}

template <class T> int Queue<T>::size() const { return n; }

template <class T> bool Queue<T>::isEmpty() const { return n == 0; }

template <class T> void Queue<T>::clear() {
  head = 0;
  tail = 0;
  n = 0;
}

template <class T> Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
  if (this != &other) {
    delete[] data;
    copy(other);
  }
  return *this;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
