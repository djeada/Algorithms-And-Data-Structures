#include "heap.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <functional>
#include <random>
#include <vector>

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

TEST(HeapTest, RandomPushPopMatchesSortedOrder) {
  std::mt19937 gen(99);
  MinHeap<int> min_heap;
  MaxHeap<int> max_heap;
  std::vector<int> values;
  for (int i = 0; i < 500; i++) {
    int v = static_cast<int>(gen() % 100) - 50;
    values.push_back(v);
    min_heap.push(v);
    max_heap.push(v);
  }
  std::sort(values.begin(), values.end());
  for (size_t i = 0; i < values.size(); i++) {
    EXPECT_EQ(min_heap.pop(), values[i]);
    EXPECT_EQ(max_heap.pop(), values[values.size() - 1 - i]);
  }
  EXPECT_TRUE(min_heap.empty());
  EXPECT_THROW(min_heap.pop(), std::out_of_range);
  EXPECT_THROW(max_heap.peek(), std::out_of_range);
}

TEST(HeapTest, CopyIsIndependentAndClearWorks) {
  MinHeap<int> a;
  a.push(3);
  a.push(1);
  a.push(2);
  MinHeap<int> b = a;
  a.pop();
  a.clear();
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), 3u);
  EXPECT_EQ(b.peek(), 1);
  a = b;
  EXPECT_EQ(a.pop(), 1);
  EXPECT_EQ(b.size(), 3u);
}
