#include "all_construct.h"
#include "gtest/gtest.h"
#include <algorithm>

bool equal(std::vector<std::vector<std::string>> &v1,
           std::vector<std::vector<std::string>> &v2) {
  auto _equal = [](std::vector<std::string> &_v1,
                   std::vector<std::string> &_v2) {
    std::sort(_v1.begin(), _v1.end());
    std::sort(_v2.begin(), _v2.end());
    return _v1 == _v2;
  };

  if (v1.size() != v2.size())
    return false;

  if (v1.empty())
    return true;

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  for (int i = 0; i < v1.size(); i++) {
    if (!_equal(v1[i], v2[i]))
      return false;
  }

  return true;
}

TEST(AllConstructTest, TestNegativeBasic1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = allConstructBasic(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestNegativeBasic2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = allConstructBasic(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestPositiveBasic1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  std::vector<std::vector<std::string>> expectedResult = {{"a", "b", "c"}};
  auto result = allConstructBasic(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}

TEST(AllConstructTest, TestPositiveBasic2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  std::vector<std::vector<std::string>> expectedResult = {{"abc", "def"}};
  auto result = allConstructBasic(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}

TEST(AllConstructTest, TestNegativeMemo1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = allConstructMemo(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestNegativeMemo2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = allConstructMemo(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestPositiveMemo1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  std::vector<std::vector<std::string>> expectedResult = {{"a", "b", "c"}};
  auto result = allConstructMemo(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}

TEST(AllConstructTest, TestPositiveMemo2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  std::vector<std::vector<std::string>> expectedResult = {{"abc", "def"}};
  auto result = allConstructMemo(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}

TEST(AllConstructTest, TestNegativeTable1) {
  std::vector<std::string> wordBank = {"bo",  "rd", "ate", "t",
                                       "ska", "sk", "boar"};
  std::string target = "skateboard";
  auto result = allConstructTable(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestNegativeTable2) {
  std::vector<std::string> wordBank = {"mo", "ha", "cz"};
  std::string target = "mohach";
  auto result = allConstructTable(target, wordBank);

  ASSERT_TRUE(result.empty());
}

TEST(AllConstructTest, TestPositiveTable1) {
  std::vector<std::string> wordBank = {"a", "b", "c"};
  std::string target = "abc";
  std::vector<std::vector<std::string>> expectedResult = {{"a", "b", "c"}};
  auto result = allConstructTable(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}

TEST(AllConstructTest, TestPositiveTable2) {
  std::vector<std::string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
  std::string target = "abcdef";
  std::vector<std::vector<std::string>> expectedResult = {{"abc", "def"}};
  auto result = allConstructTable(target, wordBank);

  ASSERT_TRUE(equal(result, expectedResult));
}
