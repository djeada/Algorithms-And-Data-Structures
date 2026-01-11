#pragma once

#include <cstddef>

template <class T> class Vector {

public:
  Vector();
  Vector(const Vector<T> &v);
  ~Vector();

  typedef T *iterator;
  typedef const T *const_iterator;
  
  int size() const;
  int capacity() const;
  bool empty() const;
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;
  void push_back(const T &value);
  void pop_back();

  void resize(unsigned int size);
  void reserve(unsigned int capacity);
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
  T &at(unsigned int index);
  const T &at(unsigned int index) const;
  Vector<T> &operator=(const Vector<T> &);
  void clear();

private:
  int n;
  int _capacity;
  T *data;
};
