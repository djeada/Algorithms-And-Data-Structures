#include "subheap.h"
#include "gtest/gtest.h"

TEST(BinaryHeapTest, CreatingFromArray) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BinaryHeap<int> subheap(arr);
  EXPECT_EQ(subheap.size(), 10);
  EXPECT_EQ(subheap.peek(), 1);
  for (int i = 0; i < subheap.size(); i++) {
    auto arrayRepresentation = subheap.arrayRepresentation()[i];
    EXPECT_EQ(arrayRepresentation, arr[i]);
  }
}

TEST(BinaryHeapTest, IsBinaryHeap) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_TRUE(BinaryHeap<int>::is_binary_heap(arr));

  std::vector<int> arr2 = {6, 2, 1, 4, 5, 3, 7, 8, 9, 10};
  EXPECT_FALSE(BinaryHeap<int>::is_binary_heap(arr2));
}

TEST(BinaryHeapTest, BinaryHeap) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BinaryHeap<int> subheap(arr);
  BinaryHeap<int> subheap2 = subheap.subHeap(0, 3);
  EXPECT_EQ(subheap2.size(), 4);
  EXPECT_EQ(subheap2.peek(), 1);
  for (int i = 0; i < subheap2.size(); i++) {
    auto arrayRepresentation = subheap2.arrayRepresentation()[i];
    EXPECT_EQ(arrayRepresentation, arr[i]);
  }
}

TEST(BinaryHeapTest, Assignment) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BinaryHeap<int> subheap(arr);
  BinaryHeap<int> subheap2 = subheap;
  EXPECT_EQ(subheap2.size(), 10);
  EXPECT_EQ(subheap2.peek(), 1);
  for (int i = 0; i < subheap2.size(); i++) {
    auto arrayRepresentation = subheap2.arrayRepresentation()[i];
    EXPECT_EQ(arrayRepresentation, arr[i]);
  }
}
