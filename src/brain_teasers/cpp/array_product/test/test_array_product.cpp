#include "array_product.h"
#include "gtest/gtest.h"

TEST(ArrayProductTest, BasicExample) {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> expected = {24, 12, 8, 6};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, ContainsZero) {
    std::vector<int> nums = {1, 2, 0, 4};
    std::vector<int> expected = {0, 0, 8, 0};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, TwoZeros) {
    std::vector<int> nums = {0, 2, 0, 4};
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, SingleElement) {
    std::vector<int> nums = {5};
    std::vector<int> expected = {1};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, TwoElements) {
    std::vector<int> nums = {3, 4};
    std::vector<int> expected = {4, 3};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, NegativeNumbers) {
    std::vector<int> nums = {-1, 2, -3, 4};
    std::vector<int> expected = {-24, 12, -8, 6};
    EXPECT_EQ(productExceptSelf(nums), expected);
}

TEST(ArrayProductTest, EmptyArray) {
    std::vector<int> nums = {};
    std::vector<int> expected = {};
    EXPECT_EQ(productExceptSelf(nums), expected);
}
