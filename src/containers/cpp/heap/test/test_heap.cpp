#include "heap.h"
#include "gtest/gtest.h"

TEST(HeapTest, EmptyHeap)
{
    MaxHeap<int> heap;
    ASSERT_TRUE(heap.empty());
}

TEST(HeapTest, AddingSingleElement)
{
    MaxHeap<int> heap;
    heap.push(10);
    EXPECT_EQ(heap.peek(), 10);
    EXPECT_EQ(heap.size(), 1);
}

TEST(HeapTest, AddingMultipleElements)
{
    MaxHeap<int> heap;
    heap.push(1);
    heap.push(2);
    heap.push(3);
    //EXPECT_EQ(heap.peek(), 3);
    EXPECT_EQ(heap.size(), 3);
    //EXPECT_EQ(heap.pop(), 0);
}
