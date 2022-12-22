#include "all_combinations.h"
#include <functional>

std::vector<std::vector<int>> all_combinations(int n, int k) {
  std::vector<std::vector<int>> result;

  // Nested function to generate combinations
  std::function<void(std::vector<int>)> _all_combinations;
  _all_combinations = [&](std::vector<int> combination) {
    if (combination.size() == k) {
      result.push_back(combination);
      return;
    }

    for (int i = (combination.empty() ? 0 : combination.back() + 1); i <= n;
         ++i) {
      combination.push_back(i);
      _all_combinations(combination);
      combination.pop_back();
    }
  };

  // Initialize result and call nested function
  _all_combinations({});
  return result;
}
