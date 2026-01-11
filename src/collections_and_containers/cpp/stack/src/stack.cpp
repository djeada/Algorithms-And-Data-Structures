#include "stack.h"
#include <stdexcept>

static constexpr int DEFAULT_INIT_SIZE = 16;

template <class T>
Stack<T>::Stack()
    : data(new T[DEFAULT_INIT_SIZE]), n(0), maxSize(DEFAULT_INIT_SIZE) {}

template <class T> Stack<T>::Stack(const Stack &other) : data(nullptr) {
  copy(other);
}

template <class T> Stack<T>::~Stack() { delete[] data; }

template <class T> void Stack<T>::copy(const Stack &other) {
  n = other.n;
  maxSize = other.maxSize;
  data = new T[maxSize];

  for (int i = 0; i < n; i++) {
    data[i] = other.data[i];
  }
}

template <class T> void Stack<T>::expand() {
  int newMaxSize = maxSize * 2;
  T *newData = new T[newMaxSize];

  for (int i = 0; i < n; i++) {
    newData[i] = data[i];
  }

  delete[] data;
  data = newData;
  maxSize = newMaxSize;
}

template <class T> T Stack<T>::pop() {
  if (n <= 0)
    throw std::out_of_range("Stack is empty");

  return data[--n];
}

template <class T> void Stack<T>::push(T element) {
  if (n >= maxSize)
    expand();

  data[n++] = element;
}

template <class T> T Stack<T>::top() const {
  if (n <= 0)
    throw std::out_of_range("Stack is empty");

  return data[n - 1];
}

template <class T> int Stack<T>::size() const { return n; }

template <class T> bool Stack<T>::isEmpty() const { return n == 0; }

template <class T> void Stack<T>::clear() { n = 0; }

template <class T> Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
  if (this != &other) {
    delete[] data;
    copy(other);
  }
  return *this;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
