#include "linked_list.h"
#include <stdexcept>

template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), n(0) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &l)
    : head(nullptr), tail(nullptr), n(0) {
  Node *p = l.head.get();
  while (p != nullptr) {
    push_back(p->data);
    p = p->next.get();
  }
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &l) {
  if (this != &l) {
    clear();
    Node *p = l.head.get();
    while (p != nullptr) {
      push_back(p->data);
      p = p->next.get();
    }
  }
  return *this;
}

template <class T> LinkedList<T>::~LinkedList() { clear(); }

template <class T> void LinkedList<T>::push_back(const T &v) {
  if (empty()) {
    head = std::make_unique<Node>();
    head->data = v;
    tail = head.get();
  } else {
    tail->next = std::make_unique<Node>();
    tail = tail->next.get();
    tail->data = v;
  }
  n++;
}

template <class T> void LinkedList<T>::push_front(const T &v) {
  if (empty()) {
    head = std::make_unique<Node>();
    head->data = v;
    tail = head.get();
  } else {
    std::unique_ptr<Node> new_head = std::make_unique<Node>();
    new_head->data = v;
    new_head->next = std::move(head);
    head = std::move(new_head);
  }
  n++;
}

template <class T> void LinkedList<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("pop_back() called on empty list");
  }
  if (size() == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    Node *p = head.get();
    while (p->next.get() != tail) {
      p = p->next.get();
    }
    p->next = nullptr;
    tail = p;
  }
  n--;
}

template <class T> void LinkedList<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("pop_front() called on empty list");
  }
  if (size() == 1) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = std::move(head->next);
  }
  n--;
}

template <class T> T &LinkedList<T>::front() {
  if (empty()) {
    throw std::out_of_range("front() called on empty list");
  }
  return head->data;
}

template <class T> T &LinkedList<T>::back() {
  if (empty()) {
    throw std::out_of_range("back() called on empty list");
  }
  return tail->data;
}

template <class T> bool LinkedList<T>::empty() { return n == 0; }

template <class T> void LinkedList<T>::clear() {
  head = nullptr;
  tail = nullptr;
  n = 0;
}

template <class T> int LinkedList<T>::size() { return n; }

template <class T> void LinkedList<T>::remove(const T &v) {
  if (empty()) {
    throw std::out_of_range("remove() called on empty list");
  }
  if (head->data == v) {
    pop_front();
  } else {
    Node *p = head.get();
    while (p->next.get() != nullptr && p->next->data != v) {
      p = p->next.get();
    }
    if (p->next.get() == nullptr) {
      throw std::out_of_range("remove() called on non-existent value");
    }
    if (p->next.get() == tail) {
      pop_back();
    } else {
      p->next = std::move(p->next->next);
      n--;
    }
  }
}

template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;