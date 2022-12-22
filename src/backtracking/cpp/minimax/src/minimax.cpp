#include "minimax.h"
#include <algorithm>
#include <cfloat>
#include <iostream>
#include <utility>
#include <vector>

bool is_player_winning(const std::vector<std::vector<int>> &board, int player) {
  // check all rows
  for (int row = 0; row < board.size(); ++row) {
    if (std::all_of(board[row].begin(), board[row].end(),
                    [&](int x) { return x == player; })) {
      return true;
    }
  }

  // check all columns
  for (int col = 0; col < board[0].size(); ++col) {
    bool win = true;
    for (int row = 0; row < board.size(); ++row) {
      if (board[row][col] != player) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // check both diagonals
  bool diagonal1_win = true;
  bool diagonal2_win = true;
  for (int i = 0; i < board.size(); ++i) {
    if (board[i][i] != player) {
      diagonal1_win = false;
    }
    if (board[i][board.size() - 1 - i] != player) {
      diagonal2_win = false;
    }
  }
  return diagonal1_win || diagonal2_win;
}

int final_score(const std::vector<std::vector<int>> &board) {
  // check for a win by player A
  if (is_player_winning(board, -1)) {
    return 1;
  }

  // check for a win by player B
  if (is_player_winning(board, 1)) {
    return -1;
  }

  // no winner, return 0
  return 0;
}

bool game_over(const std::vector<std::vector<int>> &board) {
  if (is_player_winning(board, -1) || is_player_winning(board, 1)) {
    return true;
  }

  for (int row = 0; row < board.size(); ++row) {
    for (int col = 0; col < board[0].size(); ++col) {
      if (board[row][col] == 0) {
        return false;
      }
    }
  }

  return true;
}

int minimax(std::vector<std::vector<int>> &board, int player) {
  // base case: the game has ended, return the score
  if (game_over(board)) {
    return final_score(board);
  }

  // initialize the best score
  int best_score = (player == 1) ? FLT_MIN : FLT_MAX;

  // try all possible moves
  for (int row = 0; row < board.size(); ++row) {
    for (int col = 0; col < board[0].size(); ++col) {
      if (board[row][col] == 0) {
        // make the move
        board[row][col] = player;
        // evaluate the resulting game state
        int score = minimax(board, -player);
        // undo the move
        board[row][col] = 0;

        // update the best score
        if (player == 1) {
          best_score = std::max(best_score, score);
        } else {
          best_score = std::min(best_score, score);
        }
      }
    }
  }

  // return the best score
  return best_score;
}

std::pair<int, int> find_best_move(std::vector<std::vector<int>> &board,
                                   int player) {
  // initialize the best score and the best move
  int best_score = (player == -1) ? FLT_MIN : FLT_MAX;
  std::pair<int, int> best_move = {-1, -1};

  // try all possible moves
  for (int row = 0; row < board.size(); ++row) {
    for (int col = 0; col < board[0].size(); ++col) {
      if (board[row][col] == 0) {
        // make the move
        board[row][col] = player;
        // evaluate the resulting game state
        int score = minimax(board, -player);
        // undo the move
        board[row][col] = 0;

        // update the best score and the best move
        if (player == -1) {
          if (score > best_score) {
            best_score = score;
            best_move = {row, col};
          }
        } else {
          if (score < best_score) {
            best_score = score;
            best_move = {row, col};
          }
        }
      }
    }
  }

  // return the best move
  return best_move;
}
