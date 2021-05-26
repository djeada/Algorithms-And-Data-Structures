#include "all_construct.h"
#include "gtest/gtest.h"
#include <algorithm>

bool equal(std::vector<std::vector<std::string>> &v1,
           std::vector<std::vector<std::string>> &v2) {
  auto _equal = [](std::vector<std::string> &v1, std::vector<std::string> &v2) {
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
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

