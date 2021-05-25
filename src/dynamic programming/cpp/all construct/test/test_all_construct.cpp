#include "all_construct.h"
#include "gtest/gtest.h"
#include <algorithm>

bool equal(std::vector<T>& v1, std::vector<T>& v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}

bool equal(std::vector<T>& v1, std::vector<T>& v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}


TEST(AllConstructTest, TestNegativeBasic1) {
  std::vector<std::string> wordBank = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
  std::string target = "skateboard";
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, SingleElement) {
  std::vector<int> arr{1};
  std::vector<int> result{1};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, IncreasingOrder) {
  std::vector<int> arr{5, 4, 3, 2, 1};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, DecreasingOrder) {
  std::vector<int> arr{1, 2, 3, 4, 5};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}

TEST(HeapSortTest, RandomOrder) {
  std::vector<int> arr{2, 5, 1, 4, 3};
  std::vector<int> result{1, 2, 3, 4, 5};
  heap_sort(arr);
  EXPECT_EQ(result, arr);
}
