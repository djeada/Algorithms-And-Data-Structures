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
