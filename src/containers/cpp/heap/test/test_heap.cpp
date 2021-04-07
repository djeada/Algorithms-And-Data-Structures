#include "heap.h"
#include "gtest/gtest.h"

TEST(MaxHeapTest, EmptyHeap)
{
    MaxHeap<int> heap;
    ASSERT_TRUE(heap.empty());
}

TEST(MaxHeapTest, AddingSingleElement)
{
    MaxHeap<int> heap;
    heap.push(10);
    EXPECT_EQ(heap.peek(), 10);
    EXPECT_EQ(heap.size(), 1);
}

TEST(MaxHeapTest, AddingMultipleElements)
{
    MaxHeap<int> heap;
    heap.push(1);
    heap.push(2);
    heap.push(3);
    EXPECT_EQ(heap.peek(), 3);
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_EQ(heap.size(), 2);
    EXPECT_EQ(heap.pop(), 2);
    EXPECT_EQ(heap.size(), 1);
    EXPECT_EQ(heap.pop(), 1);
    ASSERT_TRUE(heap.empty());
}

TEST(MinHeapTest, EmptyHeap)
{
    MinHeap<int> heap;
    ASSERT_TRUE(heap.empty());
}

TEST(MinHeapTest, AddingSingleElement)
{
    MinHeap<int> heap;
    heap.push(10);
    EXPECT_EQ(heap.peek(), 10);
    EXPECT_EQ(heap.size(), 1);
}

TEST(MinHeapTest, AddingMultipleElements)
{
    MinHeap<int> heap;
    heap.push(1);
    heap.push(2);
    heap.push(3);
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 1);
    EXPECT_EQ(heap.size(), 2);
    EXPECT_EQ(heap.pop(), 2);
    EXPECT_EQ(heap.size(), 1);
    EXPECT_EQ(heap.pop(), 3);
    ASSERT_TRUE(heap.empty());
}
