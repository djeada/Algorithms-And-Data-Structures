#pragma once

#include <functional>
#include <memory>
#include <vector>


template <class T> class Heap {

public:
  Heap(std::function<bool(T, T)> comp);
  Heap(const Heap &other);
  Heap &operator=(const Heap &other);

  void push(const T &val);
  T pop();
  const T &peek() const;
  unsigned int size() const;
  bool empty() const;
  void clear();
  bool isMaxHeap() const;
  bool isMinHeap() const;

private:
  std::vector<T> data;
  std::function<bool(const T &, const T &)> comp;

  int parentIdx(int index) const;
  int leftNodeIdx(int index) const;
  int rightNodeIdx(int index) const;
};

template <class T> class MinHeap : public Heap<T> {
public:
  MinHeap();
};

template <class T> class MaxHeap : public Heap<T> {
public:
  MaxHeap();
};
