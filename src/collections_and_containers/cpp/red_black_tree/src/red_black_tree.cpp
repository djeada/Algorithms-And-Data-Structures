#include "red_black_tree.h"
#include <algorithm>
#include <stdexcept>

template <class T> RedBlackTree<T>::RedBlackTree() : root(nullptr), n(0) {}

template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T> &t) : root(nullptr), n(0) {
  for (const auto &v : t.in_order_traversal()) {
    insert(v);
  }
}

template <class T>
RedBlackTree<T> &RedBlackTree<T>::operator=(const RedBlackTree<T> &t) {
  if (this != &t) {
    clear();
    for (const auto &v : t.in_order_traversal()) {
      insert(v);
    }
  }
  return *this;
}

template <class T> RedBlackTree<T>::~RedBlackTree() { clear(); }

template <class T> void RedBlackTree<T>::insert(const T &v) {
  insert(v, root);
  if (root != nullptr) {
    root->is_red = false;
  }
}

template <class T> void RedBlackTree<T>::remove(const T &v) {
  remove(v, root);
  if (root != nullptr) {
    root->is_red = false;
  }
}

template <class T> bool RedBlackTree<T>::contains(const T &v) const {
  return contains(v, root);
}

template <class T> T RedBlackTree<T>::find_min() const {
  if (root == nullptr) {
    throw std::out_of_range("Tree is empty");
  }
  const Node *p = root.get();
  while (p->left != nullptr) {
    p = p->left.get();
  }
  return p->data;
}

template <class T> T RedBlackTree<T>::find_max() const {
  if (root == nullptr) {
    throw std::out_of_range("Tree is empty");
  }
  const Node *p = root.get();
  while (p->right != nullptr) {
    p = p->right.get();
  }
  return p->data;
}

template <class T> void RedBlackTree<T>::clear() {
  clear(root);
  n = 0;
}

template <class T> int RedBlackTree<T>::height() const { return height(root); }

template <class T> int RedBlackTree<T>::size() const { return n; }

template <class T> bool RedBlackTree<T>::empty() const { return n == 0; }

template <class T> std::vector<T> RedBlackTree<T>::in_order_traversal() const {
  std::vector<T> v;
  in_order_traversal(root, v);
  return v;
}

template <class T> std::vector<T> RedBlackTree<T>::pre_order_traversal() const {
  std::vector<T> v;
  pre_order_traversal(root, v);
  return v;
}

template <class T>
std::vector<T> RedBlackTree<T>::post_order_traversal() const {
  std::vector<T> v;
  post_order_traversal(root, v);
  return v;
}

template <class T>
void RedBlackTree<T>::insert(const T &v, std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    p = std::make_unique<Node>();
    p->data = v;
    p->is_red = true;
    n++;
  } else if (v < p->data) {
    insert(v, p->left);
  } else if (v > p->data) {
    insert(v, p->right);
  } else {
    throw std::invalid_argument("Value already exists in tree");
  }
  balance(p);
}

template <class T>
bool RedBlackTree<T>::remove(const T &v, std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    return false;
  }

  if (v < p->data) {
    if (remove(v, p->left)) {
      return fix_left_deficit(p);
    }
    return false;
  }
  if (v > p->data) {
    if (remove(v, p->right)) {
      return fix_right_deficit(p);
    }
    return false;
  }

  if (p->left != nullptr && p->right != nullptr) {
    // Replace by the in-order successor and remove that node instead.
    Node *successor = p->right.get();
    while (successor->left != nullptr) {
      successor = successor->left.get();
    }
    p->data = successor->data;
    if (remove(successor->data, p->right)) {
      return fix_right_deficit(p);
    }
    return false;
  }

  // At most one child. A red node has none; a black node's only child is red.
  bool was_black = !p->is_red;
  if (p->left != nullptr || p->right != nullptr) {
    std::unique_ptr<Node> child =
        std::move(p->left != nullptr ? p->left : p->right);
    child->is_red = false;
    p = std::move(child);
    n--;
    return false;
  }
  p = nullptr;
  n--;
  return was_black;
}

// The right subtree of p is one black node shorter than the left one.
template <class T>
bool RedBlackTree<T>::fix_right_deficit(std::unique_ptr<Node> &p) {
  Node *s = p->left.get();
  if (s->is_red) {
    rotate_right(p);
    p->is_red = false;
    p->right->is_red = true;
    fix_right_deficit(p->right);
    return false;
  }
  bool parent_red = p->is_red;
  if (s->left != nullptr && s->left->is_red) {
    rotate_right(p);
  } else if (s->right != nullptr && s->right->is_red) {
    rotate_left(p->left);
    rotate_right(p);
  } else {
    s->is_red = true;
    if (parent_red) {
      p->is_red = false;
      return false;
    }
    return true;
  }
  p->is_red = parent_red;
  p->left->is_red = false;
  p->right->is_red = false;
  return false;
}

// The left subtree of p is one black node shorter than the right one.
template <class T>
bool RedBlackTree<T>::fix_left_deficit(std::unique_ptr<Node> &p) {
  Node *s = p->right.get();
  if (s->is_red) {
    rotate_left(p);
    p->is_red = false;
    p->left->is_red = true;
    fix_left_deficit(p->left);
    return false;
  }
  bool parent_red = p->is_red;
  if (s->right != nullptr && s->right->is_red) {
    rotate_left(p);
  } else if (s->left != nullptr && s->left->is_red) {
    rotate_right(p->right);
    rotate_left(p);
  } else {
    s->is_red = true;
    if (parent_red) {
      p->is_red = false;
      return false;
    }
    return true;
  }
  p->is_red = parent_red;
  p->left->is_red = false;
  p->right->is_red = false;
  return false;
}

template <class T>
bool RedBlackTree<T>::contains(const T &v,
                               const std::unique_ptr<Node> &p) const {
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

template <class T> void RedBlackTree<T>::clear(std::unique_ptr<Node> &p) {
  if (p != nullptr) {
    clear(p->left);
    clear(p->right);
    p = nullptr;
  }
}

template <class T>
int RedBlackTree<T>::height(const std::unique_ptr<Node> &p) const {
  if (p == nullptr) {
    return 0;
  } else {
    return 1 + std::max(height(p->left), height(p->right));
  }
}

template <class T>
void RedBlackTree<T>::in_order_traversal(const std::unique_ptr<Node> &p,
                                         std::vector<T> &v) const {
  if (p != nullptr) {
    in_order_traversal(p->left, v);
    v.push_back(p->data);
    in_order_traversal(p->right, v);
  }
}

template <class T>
void RedBlackTree<T>::pre_order_traversal(const std::unique_ptr<Node> &p,
                                          std::vector<T> &v) const {
  if (p != nullptr) {
    v.push_back(p->data);
    pre_order_traversal(p->left, v);
    pre_order_traversal(p->right, v);
  }
}

template <class T>
void RedBlackTree<T>::post_order_traversal(const std::unique_ptr<Node> &p,
                                           std::vector<T> &v) const {
  if (p != nullptr) {
    post_order_traversal(p->left, v);
    post_order_traversal(p->right, v);
    v.push_back(p->data);
  }
}

template <class T> void RedBlackTree<T>::balance(std::unique_ptr<Node> &p) {
  if (p == nullptr) {
    return;
  }

  // Color flip
  if (p->left != nullptr && p->left->is_red && p->right != nullptr &&
      p->right->is_red) {
    p->is_red = true;
    p->left->is_red = false;
    p->right->is_red = false;
    return;
  }

  // Left subtree cases
  if (p->left != nullptr && p->left->is_red) {
    if (p->left->left != nullptr && p->left->left->is_red) {
      // Left-Left case
      rotate_right(p);
      p->is_red = false;
      if (p->right != nullptr) {
        p->right->is_red = true;
      }
    } else if (p->left->right != nullptr && p->left->right->is_red) {
      // Left-Right case
      rotate_left(p->left);
      rotate_right(p);
      p->is_red = false;
      if (p->right != nullptr) {
        p->right->is_red = true;
      }
    }
  }

  // Right subtree cases
  if (p->right != nullptr && p->right->is_red) {
    if (p->right->right != nullptr && p->right->right->is_red) {
      // Right-Right case
      rotate_left(p);
      p->is_red = false;
      if (p->left != nullptr) {
        p->left->is_red = true;
      }
    } else if (p->right->left != nullptr && p->right->left->is_red) {
      // Right-Left case
      rotate_right(p->right);
      rotate_left(p);
      p->is_red = false;
      if (p->left != nullptr) {
        p->left->is_red = true;
      }
    }
  }
}

template <class T> void RedBlackTree<T>::rotate_left(std::unique_ptr<Node> &p) {
  std::unique_ptr<Node> r = std::move(p->right);
  p->right = std::move(r->left);
  r->left = std::move(p);
  p = std::move(r);
}

template <class T>
void RedBlackTree<T>::rotate_right(std::unique_ptr<Node> &p) {
  std::unique_ptr<Node> l = std::move(p->left);
  p->left = std::move(l->right);
  l->right = std::move(p);
  p = std::move(l);
}

template class RedBlackTree<int>;
template class RedBlackTree<std::string>;
template class RedBlackTree<double>;
template class RedBlackTree<float>;
