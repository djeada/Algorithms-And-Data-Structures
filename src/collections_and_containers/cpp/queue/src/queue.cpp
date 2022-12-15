#include "queue.h"
#include <stdexcept>

#define DEFAULT_INIT_SIZE 1000

template <class T>
Queue<T>::Queue()
    : data(new T[DEFAULT_INIT_SIZE]), n(0), maxSize(DEFAULT_INIT_SIZE), head(0),
      tail(0) {}

template <class T> Queue<T>::Queue(const Queue &other) { copy(other); }

template <class T> Queue<T>::~Queue() { delete[] data; }

template <class T> void Queue<T>::copy(const Queue &other) {

  n = other.n;
  maxSize = other.maxSize;
  head = other.head;
  tail = other.tail;

  data = new T[maxSize];

  for (int i = 0; i < n; i++)
    data[i] = other.data[i];
}

template <class T> void Queue<T>::expand() {

  int newMaxSize = maxSize * 2;
  T *newData = new T[newMaxSize];

  for (int i = 0; i < maxSize; i++)
    newData[i] = data[i];

  maxSize = newMaxSize;
  head = 0;
  tail = maxSize;

  T *oldData = data;
  data = newData;
  delete[] oldData;
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

template <class T> T Queue<T>::front() {
  if (n <= 0)
    throw std::out_of_range("Queue is empty");

  return data[head];
}

template <class T> T Queue<T>::back() {
  if (n <= 0)
    throw std::out_of_range("Queue is empty");

  return data[tail];
}

template <class T> int Queue<T>::size() { return n; }

template <class T> bool Queue<T>::isEmpty() { return n == 0; }

template <class T> Queue<T> &Queue<T>::operator=(const Queue<T> &other) {
  delete[] data;
  copy(other);
  return *this;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
