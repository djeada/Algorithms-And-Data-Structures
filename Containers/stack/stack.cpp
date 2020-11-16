#include "stack.h"
#include <stdexcept>

template<class T>
Containers::Stack<T>::Stack() : 
	data(new T[defaultInitSize]), 
	n(0), 
	maxSize(defaultInitSize) {
}
       
template<class T>
Containers::Stack<T>::Stack(const Stack& other) {
	copy(other);
}
 
template<class T>
Containers::Stack<T>::~Stack() {
	delete[] data;
}

template<class T>
void Containers::Stack<T>::copy(const Stack& other) {
	n = other.n;
	maxSize = other.maxSize;

	data = new T[maxSize];

	for (int i = 0; i < n; i++)
		data[i] = other.data[i];
}

template<class T>
void Containers::Stack<T>::expand() {
	int newMaxSize = maxSize * 2;
	T* newData = new T[newMaxSize];

	for (int i = 0; i < maxSize; i++)
		newData[i] = data[i];

	maxSize = newMaxSize;

	T* oldData = data;
	data = newData;
	delete[] oldData;
}

template<class T>
T Containers::Stack<T>::pop() {
  if (n <= 0) 
	throw std::invalid_argument(invalidSizeMsg);

  T element = data[--n];

  return element;
}

template<class T>
void Containers::Stack<T>::push(T element) {
  if (size >= maxSize)
	expand();

  data[n++] = element;
}

template<class T>
T Containers::Stack<T>::peek() {
  if (n <= 0) 
	throw std::invalid_argument(invalidSizeMsg);

  return data[n - 1];
}

template<class T>
int Containers::Stack<T>::size() {
  return n;
}

template<class T>
bool Containers::Stack<T>::isEmpty() {
  return n == 0;
}

template<class T>
Containers::Stack<T>& Containers::Stack<T>::operator=(const Stack<T>& other) {
  delete[] data;
  copy(other);
  return *this;
}
