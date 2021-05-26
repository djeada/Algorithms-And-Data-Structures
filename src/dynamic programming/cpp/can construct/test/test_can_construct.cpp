#include "can_construct.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(CanConstructTest, TestNegativeBasic1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestNegativeBasic2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveBasic1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveBasic2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestNegativeMemo1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestNegativeMemo2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveMemo1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveMemo2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestNegativeTable1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestNegativeTable2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";

  ASSERT_FALSE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveTable1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}

TEST(CanConstructTest, TestPositiveTable2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";

  ASSERT_TRUE(canConstructBasic(target, wordBank));
}
