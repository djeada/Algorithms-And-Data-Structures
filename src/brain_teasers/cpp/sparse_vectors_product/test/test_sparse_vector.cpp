#include "sparse_vector.h"
#include "gtest/gtest.h"
#include <vector>

TEST(SparseVectorProductTest, BasicProduct) {
    std::unordered_map<int, int> vec1 = {{0, 1}, {2, 3}};
    std::unordered_map<int, int> vec2 = {{0, 2}, {2, 4}};
    
    EXPECT_EQ(sparseVectorProduct(vec1, vec2), 14);  // 1*2 + 3*4
}

TEST(SparseVectorProductTest, NoOverlap) {
    std::unordered_map<int, int> vec1 = {{0, 1}, {2, 3}};
    std::unordered_map<int, int> vec2 = {{1, 2}, {3, 4}};
    
    EXPECT_EQ(sparseVectorProduct(vec1, vec2), 0);
}

TEST(SparseVectorProductTest, EmptyVector) {
    std::unordered_map<int, int> vec1 = {{0, 1}};
    std::unordered_map<int, int> vec2 = {};
    
    EXPECT_EQ(sparseVectorProduct(vec1, vec2), 0);
}

TEST(SparseVectorClassTest, BasicDotProduct) {
    std::vector<int> nums1 = {1, 0, 0, 2, 3};
    std::vector<int> nums2 = {0, 3, 0, 4, 0};
    
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    
    EXPECT_EQ(v1.dotProduct(v2), 8);  // 2*4 = 8
}

TEST(SparseVectorClassTest, AllZeros) {
    std::vector<int> nums1 = {0, 0, 0};
    std::vector<int> nums2 = {1, 2, 3};
    
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    
    EXPECT_EQ(v1.dotProduct(v2), 0);
}

TEST(SparseVectorClassTest, SameVector) {
    std::vector<int> nums = {1, 0, 2, 0, 3};
    
    SparseVector v(nums);
    
    EXPECT_EQ(v.dotProduct(v), 14);  // 1 + 4 + 9
}
