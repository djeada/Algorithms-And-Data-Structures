#include "kmp.h"
#include "gtest/gtest.h"
#include <algorithm>

/*
    def test_pattern_not_found(self):
        text = "Short text."
        pattern = "word"
        result = []
        self.assertEqual(search(text, pattern), result)

    def test_single_match(self):
        text = "The road is wide."
        pattern = "road"
        result = [4]
        self.assertEqual(search(text, pattern), result)

    def test_multiple_match(self):
        text = "One morning, when Gregor Samsa woke from troubled dreams, he
   found himself transformed in his bed into a horrible vermin. " pattern = "or"
        result = [5, 22, 81, 106]
        self.assertEqual(search(text, pattern), result)*/

TEST(TestKmp, TestPatternNotFound) {
  std::string text = "Short text.";
  std::string pattern = "word";

  std::vector<int> expected;

  auto actual = search(text, pattern);

  ASSERT_EQ(expected, actual);
}

TEST(TestKmp, TestSingleMatch) {
  std::string text = "The road is wide.";
  std::string pattern = "road";

  std::vector<int> expected = {4};

  auto actual = search(text, pattern);

  ASSERT_EQ(expected, actual);
}

TEST(TestKmp, TestMultipleMatch) {
  std::string text =
      "One morning, when Gregor Samsa woke from troubled dreams, he found "
      "himself transformed in his bed into a horrible vermin. ";

  std::string pattern = "or";

  std::vector<int> expected = {5, 22, 81, 106};

  auto actual = search(text, pattern);

  ASSERT_EQ(expected, actual);
}

#include <random>

TEST(TestKmpEdgeCases, FallbackNeedsMoreThanOneStep) {
  std::vector<int> expected = {4};
  ASSERT_EQ(search("aaabaaaab", "aaaab"), expected);
}

TEST(TestKmpEdgeCases, OverlappingMatches) {
  std::vector<int> expected = {0, 1, 2};
  ASSERT_EQ(search("aaaa", "aa"), expected);
}

TEST(TestKmpEdgeCases, EmptyPattern) {
  std::vector<int> expected = {0, 1, 2, 3};
  ASSERT_EQ(search("abc", ""), expected);
  std::vector<int> expectedEmpty = {0};
  ASSERT_EQ(search("", ""), expectedEmpty);
}

TEST(TestKmpEdgeCases, EmptyTextAndLongPattern) {
  ASSERT_TRUE(search("", "a").empty());
  ASSERT_TRUE(search("ab", "abc").empty());
}

TEST(TestKmpEdgeCases, AgainstBruteForce) {
  std::mt19937 rng(1234);
  for (int iter = 0; iter < 500; ++iter) {
    std::string text, pattern;
    for (size_t i = 0, n = rng() % 21; i < n; ++i)
      text += "ab"[rng() % 2];
    for (size_t i = 0, n = rng() % 6 + 1; i < n; ++i)
      pattern += "ab"[rng() % 2];
    std::vector<int> expected;
    for (size_t i = 0; i + pattern.size() <= text.size(); ++i)
      if (text.compare(i, pattern.size(), pattern) == 0)
        expected.push_back(static_cast<int>(i));
    ASSERT_EQ(search(text, pattern), expected);
  }
}
