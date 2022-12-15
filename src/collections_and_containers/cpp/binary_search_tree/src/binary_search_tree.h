#include <functional>
#include <memory>
#include <vector>

template <class T> class BinarySearchTree {

public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree<T> &t);
  BinarySearchTree<T> &operator=(const BinarySearchTree<T> &t);
  ~BinarySearchTree();

  void insert(const T &v);
  void remove(const T &v);
  bool contains(const T &v);
  void clear();
  int height();
  int size();
  bool empty();
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
  bool contains(const T &v, std::unique_ptr<Node> &p);
  void clear(std::unique_ptr<Node> &p);
  int height(std::unique_ptr<Node> &p);
  void in_order_traversal(const std::unique_ptr<Node> &p,
                          std::vector<T> &v) const;
  void pre_order_traversal(const std::unique_ptr<Node> &p,
                           std::vector<T> &v) const;
  void post_order_traversal(const std::unique_ptr<Node> &p,
                            std::vector<T> &v) const;
};
