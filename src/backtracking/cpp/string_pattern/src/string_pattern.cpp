#include "string_pattern.h"

#include <functional>
#include <unordered_map>

bool string_pattern(const std::string &string, const std::string &pattern) {
  std::unordered_map<char, std::string> mapping;

  // dfs function
  std::function<bool(int, int)> dfs = [&](int i, int j) {
    // base case: we have reached the end of both the string and the pattern
    if (i == string.size() && j == pattern.size()) {
      return true;
    }

    // base case: we have reached the end of either the string or the pattern
    if (i == string.size() || j == pattern.size()) {
      return false;
    }

    // get the current pattern character
    char curr = pattern[j];

    // check if the current pattern character is mapped to a string
    if (mapping.count(curr) > 0) {
      // get the mapped string
      std::string s = mapping[curr];
      // check if the string starts at the current position in the input string
      if (string.substr(i, s.size()) != s) {
        return false;
      }
      // continue the search with the next character in the pattern and the next
      // position in the string
      return dfs(i + s.size(), j + 1);
    }

    // try all possible strings for the current pattern character
    for (int k = 0; i + k < string.size(); ++k) {
      // map the current pattern character to the current string
      mapping[curr] = string.substr(i, k + 1);
      // continue the search with the next character in the pattern and the next
      // position in the string
      if (dfs(i + k + 1, j + 1)) {
        return true;
      }
      // remove the mapping
      mapping.erase(curr);
    }

    return false;
  };

  return dfs(0, 0);
}
