#include "generating_words.h"

#include <functional>
#include <unordered_map>

std::set<std::string>
generate_words(const std::vector<std::vector<char>> &board,
               const std::unordered_set<std::string> &word_dict) {
  if (board.empty()) {
    return {};
  }

  std::set<std::string> generated_words;

  // Nested function to yield valid neighbors
  std::function<std::vector<std::pair<int, int>>(int, int)> neighbors;
  neighbors = [&](int x, int y) {
    std::vector<std::pair<int, int>> result;
    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {
        if (dx == 0 && dy == 0) {
          continue;
        }
        if (0 <= x + dx && x + dx < board.size() && 0 <= y + dy &&
            y + dy < board[0].size()) {
          result.push_back({x + dx, y + dy});
        }
      }
    }
    return result;
  };

  // Nested function to convert pair to string key
  auto pair_to_key = [](const std::pair<int, int> &pair) {
    return std::to_string(pair.first) + ", " + std::to_string(pair.second);
  };

  // DFS implementation
  std::function<void(int, int, std::string,
                     std::unordered_map<std::string, bool>)>
      generate_words;
  generate_words = [&](int i, int j, std::string word,
                       std::unordered_map<std::string, bool> used) {
    used[pair_to_key({i, j})] = true;
    word += board[i][j];

    if (word_dict.count(word) && !generated_words.count(word)) {
      generated_words.insert(word);
    }

    for (const auto &pair : neighbors(i, j)) {
      const auto key = pair_to_key(pair);
      if (!used.count(key) || !used[key]) {
        generate_words(pair.first, pair.second, word, used);
      }
    }

    used[pair_to_key({i, j})] = false;
  };

  // Initialize result and call nested function
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      generate_words(i, j, "", {});
    }
  }

  return generated_words;
}