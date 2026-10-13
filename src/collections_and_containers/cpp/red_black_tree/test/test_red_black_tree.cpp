#include <algorithm>
#include <functional>
#include <memory>
#include <random>
#include <set>
#include <vector>
// Tests inspect node colours, which are private.
#define private public
#include "red_black_tree.h"
#undef private
#include "gtest/gtest.h"

namespace {
// Returns the black height of p, or -1 when a red-black rule is violated.
template <class NodePtr> int blackHeight(const NodePtr &p, bool parentRed) {
  if (p == nullptr) {
    return 1;
  }
  if (p->is_red && parentRed) {
    return -1;
  }
  int l = blackHeight(p->left, p->is_red);
  int r = blackHeight(p->right, p->is_red);
  if (l < 0 || r < 0 || l != r) {
    return -1;
  }
  return l + (p->is_red ? 0 : 1);
}

template <class Tree> bool isValidRedBlack(const Tree &t) {
  if (t.root != nullptr && t.root->is_red) {
    return false;
  }
  return blackHeight(t.root, false) > 0;
}
} // namespace

TEST(RedBlackTreeTest, DefaultConstructor) {
  RedBlackTree<int> tree;
  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(RedBlackTreeTest, Insert) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  EXPECT_EQ(tree.size(), 10);
  EXPECT_EQ(tree.height(), 5);
  EXPECT_FALSE(tree.empty());
}

TEST(RedBlackTreeTest, RemoveLast) {
  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  tree.remove(7);

  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.height(), 2);
  EXPECT_FALSE(tree.contains(7));
}

TEST(RedBlackTreeTest, RemoveRoot) {
  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  tree.remove(5);

  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.height(), 2);
  EXPECT_FALSE(tree.contains(5));
}

TEST(RedBlackTreeTest, RemoveAll) {
  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);

  tree.remove(5);
  tree.remove(3);
  tree.remove(7);

  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(RedBlackTreeTest, Contains) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  for (int i = 0; i < 10; i++) {
    EXPECT_TRUE(tree.contains(i));
  }

  for (int i = 10; i < 20; i++) {
    EXPECT_FALSE(tree.contains(i));
  }
}

TEST(RedBlackTreeTest, Clear) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  tree.clear();

  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(RedBlackTreeTest, InOrderTraversal) {
  /*
Tree structure:
        5
      /   \
     3     7
    / \   / \
   2   4 6   8

In-order traversal: 2 3 4 5 6 7 8
*/
  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::vector<int> expected = {2, 3, 4, 5, 6, 7, 8};
  std::vector<int> actual = tree.in_order_traversal();

  EXPECT_EQ(expected, actual);
}

TEST(RedBlackTreeTest, PreOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Pre-order traversal: 5 3 2 4 7 6 8
  */
  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::vector<int> expected = {5, 3, 2, 4, 7, 6, 8};
  std::vector<int> actual = tree.pre_order_traversal();

  EXPECT_EQ(expected, actual);
}

TEST(RedBlackTreeTest, PostOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Post-order traversal: 2 4 3 6 8 7 5
  */

  RedBlackTree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::vector<int> expected = {2, 4, 3, 6, 8, 7, 5};
  std::vector<int> actual = tree.post_order_traversal();

  EXPECT_EQ(expected, actual);
}

TEST(RedBlackTreeTest, AssignmentOperator) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  RedBlackTree<int> tree2;
  tree2 = tree;

  EXPECT_EQ(tree2.size(), tree.size());
  EXPECT_EQ(tree2.height(), tree.height());
  EXPECT_FALSE(tree2.empty());

  std::vector<int> v = tree2.in_order_traversal();

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(RedBlackTreeTest, CopyConstructor) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  RedBlackTree<int> tree2(tree);

  EXPECT_EQ(tree2.size(), tree.size());
  EXPECT_EQ(tree2.height(), tree.height());
  EXPECT_FALSE(tree2.empty());

  std::vector<int> v = tree2.in_order_traversal();

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(RedBlackTreeTest, IsTreeAlwaysBalanced) {
  RedBlackTree<int> tree;

  for (int i = 0; i < 100; i++) {
    tree.insert(i);
  }

  EXPECT_EQ(tree.size(), 100);
  EXPECT_EQ(tree.height(), 9);
  EXPECT_FALSE(tree.empty());
}

TEST(RedBlackTreeTest, InvariantsAfterSequentialInsertAndRemove) {
  RedBlackTree<int> tree;
  for (int i = 0; i < 200; i++) {
    tree.insert(i);
    ASSERT_TRUE(isValidRedBlack(tree)) << "after insert " << i;
  }
  for (int i = 0; i < 200; i += 2) {
    tree.remove(i);
    ASSERT_TRUE(isValidRedBlack(tree)) << "after remove " << i;
  }
  EXPECT_EQ(tree.size(), 100);
  for (int i = 199; i >= 0; i--) {
    if (i % 2 == 1) {
      tree.remove(i);
      ASSERT_TRUE(isValidRedBlack(tree)) << "after remove " << i;
    }
  }
  EXPECT_TRUE(tree.empty());
}

TEST(RedBlackTreeTest, InvariantsAfterRandomInsertsAndRemoves) {
  std::mt19937 gen(12345);
  for (int round = 0; round < 30; round++) {
    RedBlackTree<int> tree;
    std::set<int> reference;
    for (int step = 0; step < 300; step++) {
      int v = static_cast<int>(gen() % 100);
      if (gen() % 3 != 0) {
        if (reference.insert(v).second) {
          tree.insert(v);
        }
      } else if (reference.erase(v) > 0) {
        tree.remove(v);
      }
      ASSERT_TRUE(isValidRedBlack(tree));
      ASSERT_EQ(tree.size(), static_cast<int>(reference.size()));
    }
    EXPECT_EQ(tree.in_order_traversal(),
              std::vector<int>(reference.begin(), reference.end()));
  }
}

TEST(RedBlackTreeTest, RemoveMissingValueLeavesTreeUntouched) {
  RedBlackTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.remove(42);
  EXPECT_EQ(tree.size(), 2);
  EXPECT_TRUE(isValidRedBlack(tree));
}
