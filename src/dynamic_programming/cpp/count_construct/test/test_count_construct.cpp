#include "count_construct.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(CountConstructTest, TestNegativeBasic1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = 0;

  EXPECT_EQ(result, countConstructBasic(target, wordBank));
}

TEST(CountConstructTest, TestNegativeBasic2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = 0;

  EXPECT_EQ(result, countConstructBasic(target, wordBank));
}

TEST(CountConstructTest, TestPositiveBasic1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  auto result = 1;

  EXPECT_EQ(result, countConstructBasic(target, wordBank));
}

TEST(CountConstructTest, TestPositiveBasic2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  auto result = 1;

  EXPECT_EQ(result, countConstructBasic(target, wordBank));
}

TEST(CountConstructTest, TestNegativeMemo1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = 0;

  EXPECT_EQ(result, countConstructMemo(target, wordBank));
}

TEST(CountConstructTest, TestNegativeMemo2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = 0;

  EXPECT_EQ(result, countConstructMemo(target, wordBank));
}

TEST(CountConstructTest, TestPositiveMemo1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  auto result = 1;

  EXPECT_EQ(result, countConstructMemo(target, wordBank));
}

TEST(CountConstructTest, TestPositiveMemo2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  auto result = 1;

  EXPECT_EQ(result, countConstructMemo(target, wordBank));
}

TEST(CountConstructTest, TestNegativeTable1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = 0;

  EXPECT_EQ(result, countConstructTable(target, wordBank));
}

TEST(CountConstructTest, TestNegativeTable2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = 0;

  EXPECT_EQ(result, countConstructTable(target, wordBank));
}

TEST(CountConstructTest, TestPositiveTable1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  auto result = 1;

  EXPECT_EQ(result, countConstructTable(target, wordBank));
}

TEST(CountConstructTest, TestPositiveTable2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  auto result = 1;

  EXPECT_EQ(result, countConstructTable(target, wordBank));
}

TEST(CountConstructEdgeCases, EmptyWordIsIgnored) {
  std::vector<std::string> bank = {"", "a", "b"};
  ASSERT_EQ(countConstructBasic("ab", bank), 1);
  ASSERT_EQ(countConstructMemo("ab", bank), 1);
  ASSERT_EQ(countConstructTable("ab", bank), 1);
}

TEST(CountConstructEdgeCases, OverlappingWords) {
  std::vector<std::string> bank = {"a", "aa"};
  ASSERT_EQ(countConstructBasic("aaaa", bank), 5);
  ASSERT_EQ(countConstructMemo("aaaa", bank), 5);
  ASSERT_EQ(countConstructTable("aaaa", bank), 5);
}

TEST(CountConstructEdgeCases, EmptyTarget) {
  std::vector<std::string> bank = {"a"};
  ASSERT_EQ(countConstructBasic("", bank), 1);
  ASSERT_EQ(countConstructMemo("", bank), 1);
  ASSERT_EQ(countConstructTable("", bank), 1);
}
