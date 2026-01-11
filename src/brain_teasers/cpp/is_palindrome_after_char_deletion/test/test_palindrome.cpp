#include "palindrome.h"
#include "gtest/gtest.h"

TEST(PalindromeTest, AlreadyPalindrome) {
    EXPECT_TRUE(isPalindromeAfterDeletion("aba"));
    EXPECT_TRUE(isPalindromeAfterDeletion("aa"));
    EXPECT_TRUE(isPalindromeAfterDeletion("a"));
    EXPECT_TRUE(isPalindromeAfterDeletion("racecar"));
}

TEST(PalindromeTest, CanBecomePalindrome) {
    EXPECT_TRUE(isPalindromeAfterDeletion("abca"));
    EXPECT_TRUE(isPalindromeAfterDeletion("deeee"));
    EXPECT_TRUE(isPalindromeAfterDeletion("cbbcc"));
}

TEST(PalindromeTest, CannotBecomePalindrome) {
    EXPECT_FALSE(isPalindromeAfterDeletion("abcd"));
    EXPECT_FALSE(isPalindromeAfterDeletion("abcdef"));
}

TEST(PalindromeTest, Empty) {
    EXPECT_TRUE(isPalindromeAfterDeletion(""));
}

TEST(PalindromeTest, SingleChar) {
    EXPECT_TRUE(isPalindromeAfterDeletion("x"));
}

TEST(PalindromeTest, TwoChars) {
    EXPECT_TRUE(isPalindromeAfterDeletion("ab"));
    EXPECT_TRUE(isPalindromeAfterDeletion("aa"));
}

TEST(PalindromeTest, DeleteFromMiddle) {
    EXPECT_TRUE(isPalindromeAfterDeletion("abba"));
    EXPECT_TRUE(isPalindromeAfterDeletion("abbxa"));
}
