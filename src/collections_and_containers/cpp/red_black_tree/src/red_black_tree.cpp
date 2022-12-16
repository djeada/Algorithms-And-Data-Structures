#include "red_black_tree.h"
#include <stdexcept>

template <class T> RedBlackTree<T>::RedBlackTree() : root(nullptr), n(0) {}

template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T> &t) : root(nullptr), n(0) {
  for (auto v : t.in_order_traversal()) {
    insert(v);
  }
}

template <class T>
RedBlackTree<T> &RedBlackTree<T>::operator=(const RedBlackTree<T> &t) {
  if (this != &t) {
    clear();
    std::vector<T> v = t.in_order_traversal();
    for (auto i : v) {
      insert(i);
    }
  }
  return *this;
}

template <class T> RedBlackTree<T>::~RedBlackTree() { clear(); }

template <class T> void RedBlackTree<T>::insert(const T &v) {
  insert(v, root);
  root->is_red = false;
}

template <class T> void RedBlackTree<T>::remove(const T &v) {
  remove(v, root);
  if (root != nullptr) {
    root->is_red = false;
  }
}

template <class T> bool RedBlackTree<T>::contains(const T &v) {
  return contains(v, root);
}

template <class T> void RedBlackTree<T>::clear() { clear(root); }

template <class T> int RedBlackTree<T>::height() { return height(root); }

template <class T> int RedBlackTree<T>::size() { return n; }

template <class T> bool RedBlackTree<T>::empty() { return n == 0; }

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
void RedBlackTree<T>::remove(const T &v, std::unique_ptr<Node> &p) {
  auto find_min = [](std::unique_ptr<Node> &p) {
    while (p->left != nullptr) {
      p = std::move(p->left);
    }
    return p->data;
  };
  if (p == nullptr) {
    return;
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

      p->data = find_min(p->right);
      remove(p->data, p->right);
    }
  }
  balance(p);
}

template <class T>
bool RedBlackTree<T>::contains(const T &v, std::unique_ptr<Node> &p) {
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
    n--;
  }
}

template <class T> int RedBlackTree<T>::height(std::unique_ptr<Node> &p) {
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

  if (p->left != nullptr && p->left->is_red) {
    if (p->right != nullptr && p->right->is_red) {
      p->is_red = true;
      p->left->is_red = false;
      p->right->is_red = false;
    } else if (p->left->left != nullptr && p->left->left->is_red) {
      rotate_right(p);
      p->is_red = false;
      p->right->is_red = true;
    } else if (p->left->right != nullptr && p->left->right->is_red) {
      rotate_left(p->left);
      rotate_right(p);
      p->is_red = false;
      p->right->is_red = true;
    }
  } else if (p->right != nullptr && p->right->is_red) {
    if (p->right->left != nullptr && p->right->left->is_red) {
      rotate_right(p->right);
      rotate_left(p);
      p->is_red = false;
      p->left->is_red = true;
    } else if (p->right->right != nullptr && p->right->right->is_red) {
      rotate_left(p);
      p->is_red = false;
      p->left->is_red = true;
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
