#include "generating_words.h"
#include "gtest/gtest.h"

TEST(TestGeneratingWords, 3x3Board) {
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};

  std::unordered_set<std::string> word_dict = {"ABC", "ABCD", "CEG", "BEHI",
                                               "XXX"};
  std::set<std::string> expected = {"ABC", "CEG", "BEHI"};

  std::set<std::string> actual = generate_words(board, word_dict);

  EXPECT_EQ(expected, actual);
}

TEST(TestGeneratingWords, EmptyBoard) {
  std::vector<std::vector<char>> board = {};
  std::unordered_set<std::string> word_dict = {};
  std::set<std::string> expected = {};

  std::set<std::string> actual = generate_words(board, word_dict);

  EXPECT_EQ(expected, actual);
}

TEST(TestGeneratingWords, EmptyWordDict) {
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
  std::unordered_set<std::string> word_dict = {};
  std::set<std::string> expected = {};

  std::set<std::string> actual = generate_words(board, word_dict);

  EXPECT_EQ(expected, actual);
}