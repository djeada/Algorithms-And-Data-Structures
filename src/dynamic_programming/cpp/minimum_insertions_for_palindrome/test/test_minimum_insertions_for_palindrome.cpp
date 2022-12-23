#include "minimum_insertions_for_palindrome.h"
#include "gtest/gtest.h"
#include <algorithm>

/*
class TestMinimumInsertionsForPalindromeBasic(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_basic(s), result)


class TestMinimumInsertionsForPalindromeMemo(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_memo(s), result)


class TestMinimumInsertionsForPalindromeTab(unittest.TestCase):
    def test_1(self):
        s = "ab"
        result = 1
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_2(self):
        s = "aa"
        result = 0
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_3(self):
        s = "abcd"
        result = 3
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_4(self):
        s = "abcda"
        result = 2
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

    def test_5(self):
        s = "abcde"
        result = 4
        self.assertEqual(minimum_insertions_for_palindrome_tab(s), result)

*/

TEST(TestMinimumInsertionsForPalindromeBasic, TestWith1) {
  std::string s = "ab";
  int result = 1;
  EXPECT_EQ(minimum_insertions_for_palindrome_basic(s), result);
}

TEST(TestMinimumInsertionsForPalindromeBasic, TestWith2) {
  std::string s = "aa";
  int result = 0;
  EXPECT_EQ(minimum_insertions_for_palindrome_basic(s), result);
}

TEST(TestMinimumInsertionsForPalindromeBasic, TestWith3) {
  std::string s = "abcd";
  int result = 3;
  EXPECT_EQ(minimum_insertions_for_palindrome_basic(s), result);
}

TEST(TestMinimumInsertionsForPalindromeBasic, TestWith4) {
  std::string s = "abcda";
  int result = 2;
  EXPECT_EQ(minimum_insertions_for_palindrome_basic(s), result);
}

TEST(TestMinimumInsertionsForPalindromeBasic, TestWith5) {
  std::string s = "abcde";
  int result = 4;
  EXPECT_EQ(minimum_insertions_for_palindrome_basic(s), result);
}

TEST(TestMinimumInsertionsForPalindromeMemo, TestWith1) {
  std::string s = "ab";
  int result = 1;
  EXPECT_EQ(minimum_insertions_for_palindrome_memo(s), result);
}

TEST(TestMinimumInsertionsForPalindromeMemo, TestWith2) {
  std::string s = "aa";
  int result = 0;
  EXPECT_EQ(minimum_insertions_for_palindrome_memo(s), result);
}

TEST(TestMinimumInsertionsForPalindromeMemo, TestWith3) {
  std::string s = "abcd";
  int result = 3;
  EXPECT_EQ(minimum_insertions_for_palindrome_memo(s), result);
}

TEST(TestMinimumInsertionsForPalindromeMemo, TestWith4) {
  std::string s = "abcda";
  int result = 2;
  EXPECT_EQ(minimum_insertions_for_palindrome_memo(s), result);
}

TEST(TestMinimumInsertionsForPalindromeMemo, TestWith5) {
  std::string s = "abcde";
  int result = 4;
  EXPECT_EQ(minimum_insertions_for_palindrome_memo(s), result);
}

TEST(TestMinimumInsertionsForPalindromeTab, TestWith1) {
  std::string s = "ab";
  int result = 1;
  EXPECT_EQ(minimum_insertions_for_palindrome_tab(s), result);
}

TEST(TestMinimumInsertionsForPalindromeTab, TestWith2) {
  std::string s = "aa";
  int result = 0;
  EXPECT_EQ(minimum_insertions_for_palindrome_tab(s), result);
}

TEST(TestMinimumInsertionsForPalindromeTab, TestWith3) {
  std::string s = "abcd";
  int result = 3;
  EXPECT_EQ(minimum_insertions_for_palindrome_tab(s), result);
}

TEST(TestMinimumInsertionsForPalindromeTab, TestWith4) {
  std::string s = "abcda";
  int result = 2;
  EXPECT_EQ(minimum_insertions_for_palindrome_tab(s), result);
}

TEST(TestMinimumInsertionsForPalindromeTab, TestWith5) {
  std::string s = "abcde";
  int result = 4;
  EXPECT_EQ(minimum_insertions_for_palindrome_tab(s), result);
}
