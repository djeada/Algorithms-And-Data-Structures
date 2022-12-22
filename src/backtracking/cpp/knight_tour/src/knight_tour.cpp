#include "knight_tour.h"
#include <algorithm>
#include <array>

#include <unordered_map>
#include <utility>

struct PairHash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};

std::vector<std::vector<int>>
transform_tour(const std::vector<std::pair<int, int>> &tour, int n) {
  // create a map from squares to move numbers
  std::unordered_map<std::pair<int, int>, int, PairHash> move_map;
  for (int i = 0; i < tour.size(); ++i) {
    move_map[tour[i]] = i + 1;
  }

  // create a list of moves by looking up the move numbers in the map
  std::vector<std::vector<int>> moves;
  for (int row = 0; row < n; ++row) {
    std::vector<int> row_moves;
    for (int col = 0; col < n; ++col) {
      row_moves.push_back(move_map[{row, col}]);
    }
    moves.push_back(row_moves);
  }
  return moves;
}

void find_tours(std::vector<std::vector<int>> &board, int row, int col,
                int move_count, std::vector<std::pair<int, int>> &tour,
                std::vector<std::vector<std::pair<int, int>>> &tours) {
  // base case: all squares on the board have been visited
  if (move_count == board.size() * board[0].size()) {
    tours.push_back(tour);
    return;
  }

  // try all possible moves from the current position
  static const std::array<std::pair<int, int>, 8> possible_moves = {{
      {2, 1},
      {2, -1},
      {-2, 1},
      {-2, -1},
      {1, 2},
      {1, -2},
      {-1, 2},
      {-1, -2},
  }};
  for (const auto &[row_offset, col_offset] : possible_moves) {
    int new_row = row + row_offset;
    int new_col = col + col_offset;
    if (new_row >= 0 && new_row < board.size() && new_col >= 0 &&
        new_col < board[0].size() && board[new_row][new_col] == -1) {
      board[new_row][new_col] = move_count;
      tour.emplace_back(new_row, new_col);
      find_tours(board, new_row, new_col, move_count + 1, tour, tours);
      tour.pop_back();
      board[new_row][new_col] = -1;
    }
  }
}

std::vector<std::vector<std::vector<int>>> knight_tour(int n) {
  // initialize the board and the tours list
  std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));
  board[0][0] = 0;
  std::vector<std::pair<int, int>> tour = {{0, 0}};
  std::vector<std::vector<std::pair<int, int>>> tours;
  find_tours(board, 0, 0, 1, tour, tours);

  // transform the tours into a list of move lists
  std::vector<std::vector<std::vector<int>>> tours_list;
  for (const auto &tour : tours) {
    tours_list.push_back(transform_tour(tour, n));
  }
  return tours_list;
}