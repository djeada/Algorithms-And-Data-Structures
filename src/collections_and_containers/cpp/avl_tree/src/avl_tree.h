#pragma once

#include <functional>
#include <memory>
#include <vector>

template <class T> class AvlTree {

public:
  AvlTree();
  AvlTree(const AvlTree<T> &t);
  AvlTree<T> &operator=(const AvlTree<T> &t);
  ~AvlTree();

  void insert(const T &v);
  void remove(const T &v);
  bool contains(const T &v) const;
  T find_min() const;
  T find_max() const;
  void clear();
  int height() const;
  int size() const;
  bool empty() const;
  std::vector<T> in_order_traversal() const;
  std::vector<T> pre_order_traversal() const;
  std::vector<T> post_order_traversal() const;

private:
  struct Node {
    T data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  std::unique_ptr<Node> root;
  int n;

  void insert(const T &v, std::unique_ptr<Node> &p);
  void remove(const T &v, std::unique_ptr<Node> &p);
  bool contains(const T &v, const std::unique_ptr<Node> &p) const;
  void clear(std::unique_ptr<Node> &p);
  int height(const std::unique_ptr<Node> &p) const;
  void in_order_traversal(const std::unique_ptr<Node> &p,
                          std::vector<T> &v) const;
  void pre_order_traversal(const std::unique_ptr<Node> &p,
                           std::vector<T> &v) const;
  void post_order_traversal(const std::unique_ptr<Node> &p,
                            std::vector<T> &v) const;
  void balance(std::unique_ptr<Node> &p);
  void rotate_left(std::unique_ptr<Node> &p);
  void rotate_right(std::unique_ptr<Node> &p);
};
