#include "minimax.h"
#include "gtest/gtest.h"

TEST(TestMinimax, TestEmptyBoard) {
  std::vector<std::vector<int>> board = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
  };
  int player = -1;
  std::pair<int, int> expected = {0, 0};
  std::pair<int, int> actual = find_best_move(board, player);

  EXPECT_EQ(expected, actual);
}

TEST(TestMinimax, TestTwoMovesAlreadyMade) {
  std::vector<std::vector<int>> board = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  int player = -1;

  std::pair<int, int> expected = {0, 1};
  std::pair<int, int> actual = find_best_move(board, player);

  EXPECT_EQ(expected, actual);
}

TEST(TestMinimax, TestDraw) {
  std::vector<std::vector<int>> board = {{-1, 1, -1}, {1, -1, 1}, {-1, 1, -1}};
  int player = -1;

  std::pair<int, int> expected = {-1, -1};
  std::pair<int, int> actual = find_best_move(board, player);

  EXPECT_EQ(expected, actual);
}

TEST(TestMinimax, TestPlayerAWins) {
  std::vector<std::vector<int>> board = {{-1, 1, -1}, {1, 1, 0}, {-1, 0, -1}};
  int player = -1;
  std::pair<int, int> expected = {1, 2};
  std::pair<int, int> actual = find_best_move(board, player);

  EXPECT_EQ(expected, actual);
}
