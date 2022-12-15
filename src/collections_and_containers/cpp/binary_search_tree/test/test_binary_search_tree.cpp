#include "binary_search_tree.h"
#include "gtest/gtest.h"

TEST(BinarySearchTreeTest, DefaultConstructor) {
  BinarySearchTree<int> bst;
  EXPECT_EQ(bst.size(), 0);
  EXPECT_EQ(bst.height(), 0);
  EXPECT_TRUE(bst.empty());
}

TEST(BinarySearchTreeTest, CopyConstructor) {
  BinarySearchTree<int> bst;
  for (int i = 0; i < 10; i++) {
    bst.insert(i);
  }

  BinarySearchTree<int> bst2(bst);
  EXPECT_EQ(bst2.size(), 10);
  EXPECT_EQ(bst2.height(), 10);

  for (int i = 0; i < 10; i++) {
    EXPECT_TRUE(bst2.contains(i));
  }
}

TEST(BinarySearchTreeTest, AssignmentOperator) {
  BinarySearchTree<int> bst;
  for (int i = 0; i < 10; i++) {
    bst.insert(i);
  }

  BinarySearchTree<int> bst2;
  bst2 = bst;
  EXPECT_EQ(bst2.size(), 10);
  EXPECT_EQ(bst2.height(), 10);

  for (int i = 0; i < 10; i++) {
    EXPECT_TRUE(bst2.contains(i));
  }
}

TEST(BinarySearchTreeTest, Insert) {
  BinarySearchTree<int> bst;
  bst.insert(0);
  EXPECT_EQ(bst.size(), 1);
  EXPECT_EQ(bst.height(), 1);
  EXPECT_TRUE(bst.contains(0));
}

TEST(BinarySearchTreeTest, Remove) {
  BinarySearchTree<int> bst;
  bst.insert(0);
  bst.remove(0);
  EXPECT_EQ(bst.size(), 0);
  EXPECT_EQ(bst.height(), 0);
  EXPECT_FALSE(bst.contains(0));
}

TEST(BinarySearchTreeTest, Contains) {
  BinarySearchTree<int> bst;
  bst.insert(0);
  EXPECT_TRUE(bst.contains(0));
  EXPECT_FALSE(bst.contains(1));
}

TEST(BinarySearchTreeTest, Clear) {
  BinarySearchTree<int> bst;
  for (int i = 0; i < 10; i++) {
    bst.insert(i);
  }
  bst.clear();
  EXPECT_EQ(bst.size(), 0);
  EXPECT_EQ(bst.height(), 0);
  EXPECT_TRUE(bst.empty());
}

TEST(BinarySearchTreeTest, Height) {
  BinarySearchTree<int> bst;
  for (int i = 0; i < 10; i++) {
    bst.insert(i);
  }
  EXPECT_EQ(bst.height(), 10);
}

TEST(BinarySearchTreeTest, Size) {
  BinarySearchTree<int> bst;
  for (int i = 0; i < 10; i++) {
    bst.insert(i);
  }
  EXPECT_EQ(bst.size(), 10);
}

TEST(BinarySearchTreeTest, Empty) {
  BinarySearchTree<int> bst;
  EXPECT_TRUE(bst.empty());
  bst.insert(0);
  EXPECT_FALSE(bst.empty());
}

TEST(BinarySearchTreeTest, InOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  In-order traversal: 2 3 4 5 6 7 8
  */
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(2);
  bst.insert(4);
  bst.insert(6);
  bst.insert(8);

  std::vector<int> expected = {2, 3, 4, 5, 6, 7, 8};
  std::vector<int> actual = bst.in_order_traversal();

  EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTreeTest, PreOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Pre-order traversal: 5 3 2 4 7 6 8
  */
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(2);
  bst.insert(4);
  bst.insert(6);
  bst.insert(8);

  std::vector<int> expected = {5, 3, 2, 4, 7, 6, 8};
  std::vector<int> actual = bst.pre_order_traversal();

  EXPECT_EQ(actual, expected);
}

TEST(BinarySearchTreeTest, PostOrderTraversal) {
  /*
  Tree structure:
          5
        /   \
       3     7
      / \   / \
     2   4 6   8

  Post-order traversal: 2 4 3 6 8 7 5
  */
  BinarySearchTree<int> bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(7);
  bst.insert(2);
  bst.insert(4);
  bst.insert(6);
  bst.insert(8);

  std::vector<int> expected = {2, 4, 3, 6, 8, 7, 5};
  std::vector<int> actual = bst.post_order_traversal();

  EXPECT_EQ(actual, expected);
}
