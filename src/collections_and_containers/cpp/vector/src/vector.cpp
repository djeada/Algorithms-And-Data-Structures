#include "vector.h"
#include <stdexcept>

template <class T> Vector<T>::Vector() : capacity(0), n(0), data(nullptr) {}

template <class T> Vector<T>::Vector(const Vector<T> &v) {
  n = v.n;
  capacity = v.capacity;
  data = new T[n];
  for (int i = 0; i < n; i++)
    data[i] = v.data[i];
}

template <class T> Vector<T> &Vector<T>::operator=(const Vector<T> &v) {
  delete[] data;
  n = v.n;
  capacity = v.capacity;
  data = new T[capacity];

  for (int i = 0; i < n; i++)
    data[i] = v.data[i];

  return *this;
}

template <class T> Vector<T>::~Vector() { delete[] data; }

template <class T> typename Vector<T>::iterator Vector<T>::begin() {
  return data;
}

template <class T> typename Vector<T>::iterator Vector<T>::end() {
  return data + size();
}

template <class T> T &Vector<T>::front() { return data[0]; }

template <class T> T &Vector<T>::back() { return data[n - 1]; }

template <class T> void Vector<T>::push_back(const T &v) {
  if (n >= capacity)
    reserve(capacity + 5);
  data[n++] = v;
}

template <class T> bool Vector<T>::empty() { return n == 0; }

template <class T> T Vector<T>::pop_back() { return data[n--]; }

template <class T> void Vector<T>::reserve(unsigned int newCapacity) {

  T *newData = new T[newCapacity];
  capacity = newCapacity;

  if (newCapacity < n)
    n = newCapacity;

  for (int i = 0; i < n; i++)
    newData[i] = data[i];

  delete[] data;
  data = newData;
}

template <class T> int Vector<T>::size() { return n; }

template <class T> void Vector<T>::resize(unsigned int newSize) {
  reserve(newSize);
  n = newSize;
}

template <class T> T &Vector<T>::operator[](unsigned int index) {
  if (index >= n)
    throw std::out_of_range("Index out of range");
  return data[index];
}

template <class T> void Vector<T>::clear() {
  capacity = 0;
  n = 0;
  delete[] data;
  data = nullptr;
}

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
template class Vector<char>;
