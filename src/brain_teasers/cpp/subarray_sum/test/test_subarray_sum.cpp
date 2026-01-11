#include "subarray_sum.h"
#include "gtest/gtest.h"

TEST(SubarraySumTest, BasicSum) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    EXPECT_EQ(subarraySum(arr, 0, 2), 6);   // 1+2+3
    EXPECT_EQ(subarraySum(arr, 1, 3), 9);   // 2+3+4
    EXPECT_EQ(subarraySum(arr, 0, 4), 15);  // all elements
}

TEST(SubarraySumTest, SingleElement) {
    std::vector<int> arr = {5};
    EXPECT_EQ(subarraySum(arr, 0, 0), 5);
}

TEST(SubarraySumTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_EQ(subarraySum(arr, 0, 0), 0);
}

TEST(SubarraySumTest, InvalidRange) {
    std::vector<int> arr = {1, 2, 3};
    EXPECT_EQ(subarraySum(arr, -1, 1), 0);
    EXPECT_EQ(subarraySum(arr, 0, 5), 0);
    EXPECT_EQ(subarraySum(arr, 2, 1), 0);
}

TEST(PrefixSumTest, BasicQueries) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    PrefixSum ps(arr);
    
    EXPECT_EQ(ps.rangeSum(0, 2), 6);   // 1+2+3
    EXPECT_EQ(ps.rangeSum(1, 3), 9);   // 2+3+4
    EXPECT_EQ(ps.rangeSum(0, 4), 15);  // all elements
}

TEST(PrefixSumTest, SingleElement) {
    std::vector<int> arr = {5};
    PrefixSum ps(arr);
    EXPECT_EQ(ps.rangeSum(0, 0), 5);
}

TEST(PrefixSumTest, NegativeNumbers) {
    std::vector<int> arr = {-1, 2, -3, 4};
    PrefixSum ps(arr);
    EXPECT_EQ(ps.rangeSum(0, 3), 2);   // -1+2-3+4
    EXPECT_EQ(ps.rangeSum(1, 2), -1);  // 2-3
}
