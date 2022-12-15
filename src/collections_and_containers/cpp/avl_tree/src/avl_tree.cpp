#include "avl_tree.h"
#include <stdexcept>

template <class T> AvlTree<T>::AvlTree() : root(nullptr), n(0) {}

template <class T>
AvlTree<T>::AvlTree(const AvlTree<T> &t) : root(nullptr), n(0) {
  for (auto v : t.in_order_traversal()) {
    insert(v);
  }
}

template <class T> AvlTree<T> &AvlTree<T>::operator=(const AvlTree<T> &t) {
  if (this != &t) {
    clear();
    for (auto v : t.in_order_traversal()) {
      insert(v);
    }
  }
  return *this;
}

template <class T> AvlTree<T>::~AvlTree() { clear(); }

template <class T> void AvlTree<T>::insert(const T &v) { insert(v, root); }

template <class T> void AvlTree<T>::remove(const T &v) { remove(v, root); }

template <class T> bool AvlTree<T>::contains(const T &v) {
  return contains(v, root);
}

template <class T> void AvlTree<T>::clear() { clear(root); }

template <class T> int AvlTree<T>::height() { return height(root); }

template <class T> int AvlTree<T>::size() { return n; }

template <class T> bool AvlTree<T>::empty() { return n == 0; }

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
    } else if (p->left == nullptr) {
      p = std::move(p->right);
    } else if (p->right == nullptr) {
      p = std::move(p->left);
    } else {
      std::unique_ptr<Node> &c = p->left;
      while (c->right != nullptr) {
        c = std::move(c->right);
      }
      p->data = c->data;
      c = std::move(c->left);
    }
    n--;
  }
  balance(p);
}

template <class T>
bool AvlTree<T>::contains(const T &v, std::unique_ptr<Node> &p) {
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

template <class T> int AvlTree<T>::height(std::unique_ptr<Node> &p) {
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
  if (p != nullptr) {
    if (height(p->left) - height(p->right) > 1) {
      if (height(p->left->left) >= height(p->left->right)) {
        rotate_right(p);
      } else {
        rotate_left(p->left);
        rotate_right(p);
      }
    } else if (height(p->right) - height(p->left) > 1) {
      if (height(p->right->right) >= height(p->right->left)) {
        rotate_left(p);
      } else {
        rotate_right(p->right);
        rotate_left(p);
      }
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
