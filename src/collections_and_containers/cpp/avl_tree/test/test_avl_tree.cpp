#include "avl_tree.h"
#include "gtest/gtest.h"

TEST(AvlTreeTest, DefaultConstructor) {
  AvlTree<int> tree;
  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(AvlTreeTest, Insert) {
  AvlTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  EXPECT_EQ(tree.size(), 10);
  EXPECT_EQ(tree.height(), 4);
  EXPECT_FALSE(tree.empty());
}

TEST(AvlTreeTest, Remove) {
  AvlTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  for (int i = 0; i < 10; i++) {
    tree.remove(i);
  }

  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(AvlTreeTest, Contains) {
  AvlTree<int> tree;

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

TEST(AvlTreeTest, Clear) {
  AvlTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  tree.clear();

  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.height(), 0);
  EXPECT_TRUE(tree.empty());
}

TEST(AvlTreeTest, InOrderTraversal) {
  /*
Tree structure:
        5
      /   \
     3     7
    / \   / \
   2   4 6   8

In-order traversal: 2 3 4 5 6 7 8
*/
  AvlTree<int> tree;

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

TEST(AvlTreeTest, PreOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Pre-order traversal: 5 3 2 4 7 6 8
  */
  AvlTree<int> tree;

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

TEST(AvlTreeTest, PostOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Post-order traversal: 2 4 3 6 8 7 5
  */

  AvlTree<int> tree;

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

TEST(AvlTreeTest, AssignmentOperator) {
  AvlTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  AvlTree<int> tree2;
  tree2 = tree;

  EXPECT_EQ(tree2.size(), 10);
  EXPECT_EQ(tree2.height(), 4);
  EXPECT_FALSE(tree2.empty());

  std::vector<int> v = tree2.in_order_traversal();

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(AvlTreeTest, CopyConstructor) {
  AvlTree<int> tree;

  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }

  AvlTree<int> tree2(tree);

  EXPECT_EQ(tree2.size(), 10);
  EXPECT_EQ(tree2.height(), 4);
  EXPECT_FALSE(tree2.empty());

  std::vector<int> v = tree2.in_order_traversal();

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(v[i], i);
  }
}

TEST(AvlTreeTest, IsTreeAlwaysBalanced) {
  AvlTree<int> tree;

  for (int i = 0; i < 100; i++) {
    tree.insert(i);
  }

  EXPECT_EQ(tree.size(), 100);
  EXPECT_EQ(tree.height(), 7);
  EXPECT_FALSE(tree.empty());
}
