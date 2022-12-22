#include "string_pattern.h"
#include "gtest/gtest.h"

TEST(TestStringPattern, TestPositive1) {
  std::string string = "basetestcasebase";
  std::string pattern = "ABCDA";
  EXPECT_TRUE(string_pattern(string, pattern));
}

TEST(TestStringPattern, TestPositive2) {
  std::string string = "basetestcasebase";
  std::string pattern = "A";
  EXPECT_TRUE(string_pattern(string, pattern));
}

TEST(TestStringPattern, TestPositive3) {
  std::string string = "basetestcasebase";
  std::string pattern = "ABA";
  EXPECT_TRUE(string_pattern(string, pattern));
}

TEST(TestStringPattern, TestNegative1) {
  std::string string = "basetestcasebase";
  std::string pattern = "AA";
  EXPECT_FALSE(string_pattern(string, pattern));
}

TEST(TestStringPattern, TestNegative2) {
  std::string string = "abcdefg";
  std::string pattern = "aa";
  EXPECT_FALSE(string_pattern(string, pattern));
}