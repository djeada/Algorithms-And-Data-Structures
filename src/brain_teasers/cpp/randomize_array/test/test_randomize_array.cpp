#include "randomize_array.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <set>

TEST(RandomizeArrayTest, PreservesElements) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> original = arr;
    
    shuffleArray(arr);
    
    // Should contain same elements
    std::sort(arr.begin(), arr.end());
    EXPECT_EQ(arr, original);
}

TEST(RandomizeArrayTest, PreservesSize) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    size_t originalSize = arr.size();
    
    shuffleArray(arr);
    
    EXPECT_EQ(arr.size(), originalSize);
}

TEST(RandomizeArrayTest, EmptyArray) {
    std::vector<int> arr = {};
    shuffleArray(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(RandomizeArrayTest, SingleElement) {
    std::vector<int> arr = {42};
    shuffleArray(arr);
    EXPECT_EQ(arr.size(), 1u);
    EXPECT_EQ(arr[0], 42);
}

TEST(RandomizeArrayTest, GetShuffledCopy) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> shuffled = getShuffledCopy(arr);
    
    // Original should be unchanged
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
    
    // Shuffled should have same elements
    std::sort(shuffled.begin(), shuffled.end());
    EXPECT_EQ(shuffled, arr);
}

TEST(RandomizeArrayTest, Randomness) {
    // Test that shuffling produces different results
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::set<std::vector<int>> results;
    
    for (int i = 0; i < 10; ++i) {
        std::vector<int> copy = arr;
        shuffleArray(copy);
        results.insert(copy);
    }
    
    // Should produce more than 1 unique result (very high probability)
    EXPECT_GT(results.size(), 1u);
}
