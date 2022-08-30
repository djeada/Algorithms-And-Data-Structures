
/*
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that
row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the
matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including
zero moves).        */

#include <iostream>
#include <queue>
#include <vector>

int scoreOfMatrix(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int score = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        score += 1 << (n - j - 1);
      }
    }
  }
  return score;
}

void toggleRow(std::vector<std::vector<int>> &grid, int row) {
  int n = grid[0].size();
  for (int j = 0; j < n; j++) {
    grid[row][j] = 1 - grid[row][j];
  }
}

void toggleColumn(std::vector<std::vector<int>> &grid, int column) {
  int m = grid.size();
  for (int i = 0; i < m; i++) {
    grid[i][column] = 1 - grid[i][column];
  }
}

int highgestScore(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int max = scoreOfMatrix(grid);

  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {

      toggleRow(grid, i);
      auto score = scoreOfMatrix(grid);
      if (score > max)
        max = score;
      else
        toggleRow(grid, i);

      toggleColumn(grid, j);
      score = scoreOfMatrix(grid);
      if (score > max)
        max = score;
      else
        toggleColumn(grid, j);
    }
  }

  return max;
}

void test1() {
  /*
  Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
  Output: 39
  */
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  auto result = highgestScore(grid);
  std::cout << result << std::endl;
}

void test2() {
  /*
  Input: grid = [[1,0,0],[0,1,0],[0,0,1]]
  Output: 3
  */
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  auto result = highgestScore(grid);
  std::cout << result << std::endl;
}

void test3() {
  /*
  Input: grid = [[1,1,1,1,1,1,1,1,1]]
  Output: 1
  */
  std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 1, 1}};
  auto result = highgestScore(grid);
  std::cout << result << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
