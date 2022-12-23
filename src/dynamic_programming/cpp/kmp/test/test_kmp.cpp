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
