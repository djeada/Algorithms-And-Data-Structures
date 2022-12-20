"""
#include <functional>
#include <memory>
#include <vector>

template <class T> class LinkedList {

public:
  LinkedList();
  LinkedList(const LinkedList<T> &l);
  LinkedList<T> &operator=(const LinkedList<T> &l);
  ~LinkedList();

  void push_back(const T &v);
  void push_front(const T &v);
  void pop_back();
  void pop_front();
  T &front();
  T &back();
  bool empty();
  void clear();
  int size();
  void remove(const T &v);

private:
  struct Node {
    T data;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> head;
  Node *tail;
  int n;
};
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.n = 0

    def push_back(self, v):
        if self.head is None:
            self.head = Node(v)
        else:
            node = self.head
            while node.next is not None:
                node = node.next
            node.next = Node(v)
        self.n += 1

    def push_front(self, v):
        node = Node(v)
        node.next = self.head
        self.head = node
        self.n += 1

    def pop_back(self):
        if self.head is None:
            return None

        last = self.head
        while last.next is not None:
            prev = last
            last = last.next

        if last == self.head:
            self.head = None
        else:
            prev.next = None

        self.n -= 1
        return last.data

    def pop_front(self):
        if self.head is None:
            return None

        node = self.head
        self.head = node.next
        self.n -= 1
        return node.data

    def front(self):
        if self.head is None:
            return None
        return self.head.data

    def back(self):
        if self.head is None:
            return None

        node = self.head
        while node.next is not None:
            node = node.next
        return node.data

    def empty(self):
        return self.head is None

    def clear(self):
        self.head = None
        self.n = 0

    def size(self):
        return self.n

    def remove(self, v):
        if self.head is None:
            return

        if self.head.data == v:
            self.head = self.head.next
            self.n -= 1
            return

        node = self.head
        while node.next is not None:
            if node.next.data == v:
                node.next = node.next.next
                self.n -= 1
                return
            node = node.next

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node.data
            node = node.next

    def __str__(self):
        return str(list(self))

    def __repr__(self):
        return str(self)
