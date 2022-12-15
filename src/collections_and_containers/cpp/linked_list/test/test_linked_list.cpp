#include "linked_list.h"
#include "gtest/gtest.h"

TEST(LinkedListTest, EmptyLinkedList) {
  LinkedList<int> linked_list;
  ASSERT_TRUE(linked_list.empty());
}

TEST(LinkedListTest, Clear) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);
  EXPECT_EQ(linked_list.size(), 3);

  linked_list.clear();
  ASSERT_TRUE(linked_list.empty());
}

TEST(LinkedListTest, AddingMultipleElements) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  EXPECT_EQ(linked_list.size(), 3);
  EXPECT_EQ(linked_list.front(), 1);
  EXPECT_EQ(linked_list.back(), 3);
}

TEST(LinkedListTest, Front) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  EXPECT_EQ(linked_list.front(), 1);
}

TEST(LinkedListTest, Back) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  EXPECT_EQ(linked_list.back(), 3);
}

TEST(LinkedListTest, PopFront) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  linked_list.pop_front();
  EXPECT_EQ(linked_list.front(), 2);

  linked_list.pop_front();
  EXPECT_EQ(linked_list.front(), 3);

  linked_list.pop_front();
  ASSERT_TRUE(linked_list.empty());
}

TEST(LinkedListTest, PopBack) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  linked_list.pop_back();
  EXPECT_EQ(linked_list.back(), 2);

  linked_list.pop_back();
  EXPECT_EQ(linked_list.back(), 1);

  linked_list.pop_back();
  ASSERT_TRUE(linked_list.empty());
}

TEST(LinkedListTest, Remove) {
  LinkedList<int> linked_list;
  linked_list.push_back(1);
  linked_list.push_back(2);
  linked_list.push_back(3);

  linked_list.remove(2);
  EXPECT_EQ(linked_list.size(), 2);
  EXPECT_EQ(linked_list.front(), 1);
  EXPECT_EQ(linked_list.back(), 3);

  linked_list.remove(1);
  EXPECT_EQ(linked_list.size(), 1);
  EXPECT_EQ(linked_list.front(), 3);
  EXPECT_EQ(linked_list.back(), 3);
}
