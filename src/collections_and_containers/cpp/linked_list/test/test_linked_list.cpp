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

TEST(LinkedListTest, ClearAndDestroyVeryLongListDoesNotOverflowStack) {
  {
    LinkedList<int> linked_list;
    for (int i = 0; i < 1000000; i++) {
      linked_list.push_back(i);
    }
    EXPECT_EQ(linked_list.size(), 1000000);
    linked_list.clear();
    EXPECT_TRUE(linked_list.empty());
    for (int i = 0; i < 1000000; i++) {
      linked_list.push_front(i);
    }
    // Destructor releases the long chain here.
  }
}

TEST(LinkedListTest, PushBackAfterClearAndPopAll) {
  LinkedList<int> l;
  l.push_back(1);
  l.push_back(2);
  l.pop_back();
  l.pop_back();
  EXPECT_TRUE(l.empty());
  l.push_back(3);
  EXPECT_EQ(l.front(), 3);
  EXPECT_EQ(l.back(), 3);
  l.clear();
  l.push_back(4);
  l.push_back(5);
  EXPECT_EQ(l.back(), 5);
  l.remove(5);
  EXPECT_EQ(l.back(), 4);
  l.push_back(6);
  EXPECT_EQ(l.back(), 6);
  EXPECT_EQ(l.size(), 2);
}

TEST(LinkedListTest, CopyIsDeep) {
  LinkedList<int> a;
  a.push_back(1);
  a.push_back(2);
  LinkedList<int> b(a);
  a.pop_front();
  a.push_back(9);
  EXPECT_EQ(b.size(), 2);
  EXPECT_EQ(b.front(), 1);
  EXPECT_EQ(b.back(), 2);
  LinkedList<int> c;
  c.push_back(7);
  c = b;
  b.clear();
  EXPECT_EQ(c.size(), 2);
  EXPECT_EQ(c.back(), 2);
}
