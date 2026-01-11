#include "avl_tree.h"
#include <algorithm>
#include <stdexcept>

template <class T> AvlTree<T>::AvlTree() : root(nullptr), n(0) {}

template <class T>
AvlTree<T>::AvlTree(const AvlTree<T> &t) : root(nullptr), n(0) {
  for (const auto &v : t.in_order_traversal()) {
    insert(v);
  }
}

template <class T> AvlTree<T> &AvlTree<T>::operator=(const AvlTree<T> &t) {
  if (this != &t) {
    clear();
    for (const auto &v : t.in_order_traversal()) {
      insert(v);
    }
  }
  return *this;
}

template <class T> AvlTree<T>::~AvlTree() { clear(); }

template <class T> void AvlTree<T>::insert(const T &v) { insert(v, root); }

template <class T> void AvlTree<T>::remove(const T &v) { remove(v, root); }

template <class T> bool AvlTree<T>::contains(const T &v) const {
  return contains(v, root);
}

template <class T> T AvlTree<T>::find_min() const {
  if (root == nullptr) {
    throw std::out_of_range("Tree is empty");
  }
  const Node *p = root.get();
  while (p->left != nullptr) {
    p = p->left.get();
  }
  return p->data;
}

template <class T> T AvlTree<T>::find_max() const {
  if (root == nullptr) {
    throw std::out_of_range("Tree is empty");
  }
  const Node *p = root.get();
  while (p->right != nullptr) {
    p = p->right.get();
  }
  return p->data;
}

template <class T> void AvlTree<T>::clear() { clear(root); }

template <class T> int AvlTree<T>::height() const { return height(root); }

template <class T> int AvlTree<T>::size() const { return n; }

template <class T> bool AvlTree<T>::empty() const { return n == 0; }

template <class T> std::vector<T> AvlTree<T>::in_order_traversal() const {
  std::vector<T> v;
  in_order_traversal(root, v);
  return v;
}

template <class T> std::vector<T> AvlTree<T>::pre_order_traversal() const {
  std::vector<T> v;
  pre_order_traversal(root, v);
  return v;
}

template <class T> std::vector<T> AvlTree<T>::post_order_traversal() const {
  std::vector<T> v;
  post_order_traversal(root, v);
  return v;
}

template <class T>
void AvlTree<T>::insert(const T &v, std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    p = std::make_unique<Node>();
    p->data = v;
    n++;
  } else if (v < p->data) {
    insert(v, p->left);
  } else if (v > p->data) {
    insert(v, p->right);
  } else {
    throw std::invalid_argument("duplicate value");
  }
  balance(p);
}

template <class T>
void AvlTree<T>::remove(const T &v, std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    throw std::invalid_argument("value not found");
  } else if (v < p->data) {
    remove(v, p->left);
  } else if (v > p->data) {
    remove(v, p->right);
  } else {
    if (p->left == nullptr && p->right == nullptr) {
      p = nullptr;
      n--;
    } else if (p->left == nullptr) {
      p = std::move(p->right);
      n--;
    } else if (p->right == nullptr) {
      p = std::move(p->left);
      n--;
    } else {
      // Find in-order predecessor
      Node *pred = p->left.get();
      while (pred->right != nullptr) {
        pred = pred->right.get();
      }
      p->data = pred->data;
      remove(pred->data, p->left);
    }
  }
  if (p != nullptr) {
    balance(p);
  }
}

template <class T>
bool AvlTree<T>::contains(const T &v, const std::unique_ptr<Node> &p) const {
  if (p == nullptr) {
    return false;
  } else if (v < p->data) {
    return contains(v, p->left);
  } else if (v > p->data) {
    return contains(v, p->right);
  } else {
    return true;
  }
}

template <class T> void AvlTree<T>::clear(std::unique_ptr<Node> &p) {
  if (p != nullptr) {
    clear(p->left);
    clear(p->right);
    p = nullptr;
    n--;
  }
}

template <class T> int AvlTree<T>::height(const std::unique_ptr<Node> &p) const {
  if (p == nullptr) {
    return 0;
  } else {
    return 1 + std::max(height(p->left), height(p->right));
  }
}

template <class T>
void AvlTree<T>::in_order_traversal(const std::unique_ptr<Node> &p,
                                    std::vector<T> &v) const {
  if (p != nullptr) {
    in_order_traversal(p->left, v);
    v.push_back(p->data);
    in_order_traversal(p->right, v);
  }
}

template <class T>
void AvlTree<T>::pre_order_traversal(const std::unique_ptr<Node> &p,
                                     std::vector<T> &v) const {
  if (p != nullptr) {
    v.push_back(p->data);
    pre_order_traversal(p->left, v);
    pre_order_traversal(p->right, v);
  }
}

template <class T>
void AvlTree<T>::post_order_traversal(const std::unique_ptr<Node> &p,
                                      std::vector<T> &v) const {
  if (p != nullptr) {
    post_order_traversal(p->left, v);
    post_order_traversal(p->right, v);
    v.push_back(p->data);
  }
}

template <class T> void AvlTree<T>::balance(std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    return;
  }
  
  int leftHeight = height(p->left);
  int rightHeight = height(p->right);
  
  if (leftHeight - rightHeight > 1) {
    // Left-heavy
    if (height(p->left->left) >= height(p->left->right)) {
      // Left-Left case
      rotate_right(p);
    } else {
      // Left-Right case
      rotate_left(p->left);
      rotate_right(p);
    }
  } else if (rightHeight - leftHeight > 1) {
    // Right-heavy
    if (height(p->right->right) >= height(p->right->left)) {
      // Right-Right case
      rotate_left(p);
    } else {
      // Right-Left case
      rotate_right(p->right);
      rotate_left(p);
    }
  }
}

template <class T> void AvlTree<T>::rotate_left(std::unique_ptr<Node> &p) {
  std::unique_ptr<Node> r = std::move(p->right);
  p->right = std::move(r->left);
  r->left = std::move(p);
  p = std::move(r);
}

template <class T> void AvlTree<T>::rotate_right(std::unique_ptr<Node> &p) {
  std::unique_ptr<Node> l = std::move(p->left);
  p->left = std::move(l->right);
  l->right = std::move(p);
  p = std::move(l);
}

template class AvlTree<int>;
template class AvlTree<std::string>;
template class AvlTree<double>;
template class AvlTree<float>;
