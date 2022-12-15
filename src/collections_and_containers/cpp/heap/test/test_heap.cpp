#include "heap.h"
#include "gtest/gtest.h"

TEST(MaxHeapTest, EmptyHeap) {
  MaxHeap<int> heap;
  ASSERT_TRUE(heap.empty());
}

TEST(MaxHeapTest, AddingMultipleElements) {
  MaxHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);
  EXPECT_EQ(heap.size(), 3);

  EXPECT_EQ(heap.pop(), 3);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 1);

  ASSERT_TRUE(heap.empty());

  // adding the same elements in different order
  heap.push(3);
  heap.push(1);
  heap.push(2);

  EXPECT_EQ(heap.pop(), 3);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 1);
}

TEST(MaxHeapTest, PeekVsPop) {

  // show the difference between peek and pop
  MaxHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  EXPECT_EQ(heap.peek(), 3);
  EXPECT_EQ(heap.peek(), 3);
  EXPECT_EQ(heap.size(), 3);

  EXPECT_EQ(heap.pop(), 3);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 1);
  ASSERT_TRUE(heap.empty());
}

TEST(MaxHeapTest, PeekWhenEmpty) {
  MaxHeap<int> heap;
  ASSERT_THROW(heap.peek(), std::out_of_range);
}

TEST(MaxHeapTest, PopWhenEmpty) {
  MaxHeap<int> heap;
  ASSERT_THROW(heap.pop(), std::out_of_range);
}

TEST(MaxHeapTest, CopyConstructor) {
  MaxHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  MaxHeap<int> heap2(heap);

  EXPECT_EQ(heap2.pop(), 3);
  EXPECT_EQ(heap2.pop(), 2);
  EXPECT_EQ(heap2.pop(), 1);
}

TEST(MaxHeapTest, AssignmentOperator) {
  MaxHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  MaxHeap<int> heap2 = heap;

  EXPECT_EQ(heap2.pop(), 3);
  EXPECT_EQ(heap2.pop(), 2);
  EXPECT_EQ(heap2.pop(), 1);
}

TEST(MaxHeapTest, isMaxHeap) {
  MaxHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  EXPECT_TRUE(heap.isMaxHeap());
}

TEST(MinHeapTest, EmptyHeap) {
  MinHeap<int> heap;
  ASSERT_TRUE(heap.empty());
}

TEST(MinHeapTest, AddingMultipleElements) {
  MinHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  EXPECT_EQ(heap.size(), 3);

  EXPECT_EQ(heap.pop(), 1);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 3);

  ASSERT_TRUE(heap.empty());

  // adding the same elements in different order

  heap.push(3);
  heap.push(1);
  heap.push(2);

  EXPECT_EQ(heap.pop(), 1);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 3);

  ASSERT_TRUE(heap.empty());
}

TEST(MinHeapTest, PeekVsPop) {

  // show the difference between peek and pop
  MinHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  EXPECT_EQ(heap.peek(), 1);
  EXPECT_EQ(heap.peek(), 1);
  EXPECT_EQ(heap.size(), 3);

  EXPECT_EQ(heap.pop(), 1);
  EXPECT_EQ(heap.pop(), 2);
  EXPECT_EQ(heap.pop(), 3);
  ASSERT_TRUE(heap.empty());
}

TEST(MinHeapTest, PeekWhenEmpty) {
  MinHeap<int> heap;
  ASSERT_THROW(heap.peek(), std::out_of_range);
}

TEST(MinHeapTest, PopWhenEmpty) {
  MinHeap<int> heap;
  ASSERT_THROW(heap.pop(), std::out_of_range);
}

TEST(MinHeapTest, CopyConstructor) {
  MinHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  MinHeap<int> heap2(heap);

  EXPECT_EQ(heap2.pop(), 1);
  EXPECT_EQ(heap2.pop(), 2);
  EXPECT_EQ(heap2.pop(), 3);
}

TEST(MinHeapTest, AssignmentOperator) {
  MinHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  MinHeap<int> heap2 = heap;

  EXPECT_EQ(heap2.pop(), 1);
  EXPECT_EQ(heap2.pop(), 2);
  EXPECT_EQ(heap2.pop(), 3);
}

TEST(MinHeapTest, IsMinHeap) {
  MinHeap<int> heap;
  heap.push(1);
  heap.push(2);
  heap.push(3);

  ASSERT_TRUE(heap.isMinHeap());
}
