#include "valid_parentheses.h"
#include "gtest/gtest.h"

TEST(ValidParenthesesTest, AlreadyValid) {
    EXPECT_EQ(minDeletionsToMakeValid("()"), 0);
    EXPECT_EQ(minDeletionsToMakeValid("(())"), 0);
    EXPECT_EQ(minDeletionsToMakeValid("()()"), 0);
}

TEST(ValidParenthesesTest, ExtraClosing) {
    EXPECT_EQ(minDeletionsToMakeValid("())"), 1);
    EXPECT_EQ(minDeletionsToMakeValid("()))"), 2);
}

TEST(ValidParenthesesTest, ExtraOpening) {
    EXPECT_EQ(minDeletionsToMakeValid("(()"), 1);
    EXPECT_EQ(minDeletionsToMakeValid("((("), 3);
}

TEST(ValidParenthesesTest, Mixed) {
    EXPECT_EQ(minDeletionsToMakeValid(")("), 2);
    EXPECT_EQ(minDeletionsToMakeValid(")()("), 2);
    EXPECT_EQ(minDeletionsToMakeValid("(()))(("), 3);
}

TEST(ValidParenthesesTest, Empty) {
    EXPECT_EQ(minDeletionsToMakeValid(""), 0);
}

TEST(ValidParenthesesTest, NoParentheses) {
    EXPECT_EQ(minDeletionsToMakeValid("abc"), 0);
}

TEST(ValidParenthesesTest, Complex) {
    EXPECT_EQ(minDeletionsToMakeValid("())(()"), 2);
    EXPECT_EQ(minDeletionsToMakeValid("((())())"), 0);
}
