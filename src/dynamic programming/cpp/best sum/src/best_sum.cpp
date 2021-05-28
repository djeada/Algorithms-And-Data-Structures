#include "best_sum.h"
#include <algorithm>
#include <functional>
#include <unordered_map>

std::vector<unsigned int>
bestSumBasic(const unsigned int target,
             const std::vector<unsigned int> &numbers) {

  std::function<std::vector<std::vector<unsigned int>>(
      const unsigned int, const std::vector<unsigned int> &)>
      _bestSumBasic;
  _bestSumBasic = [&](const unsigned int target,
                      const std::vector<unsigned int> &numbers)
      -> std::vector<std::vector<unsigned int>> {
    if (target == 0)
      return {{}};

    std::vector<unsigned int> shortestCombination;

    for (const auto &num : numbers) {

      if (num > target)
        continue;

      auto remainder = target - num;
      auto combination = _bestSumBasic(remainder, numbers);

      if (!combination.empty()) {

        combination[0].push_back(num);

        if (shortestCombination.empty() ||
            combination[0].size() < shortestCombination.size())
          shortestCombination = combination[0];
      }
    }

    if (!shortestCombination.empty())
      return {shortestCombination};

    return {};
  };

  auto result = _bestSumBasic(target, numbers);

  if (!result.empty())
    return result.front();

  return {};
}

std::vector<unsigned int>
bestSumMemo(const unsigned int target,
            const std::vector<unsigned int> &numbers) {

  std::function<std::vector<std::vector<unsigned int>>(
      const unsigned int, const std::vector<unsigned int> &,
      std::unordered_map<unsigned int, std::vector<std::vector<unsigned int>>>
          &)>
      _bestSumMemo;
  _bestSumMemo =
      [&](const unsigned int target, const std::vector<unsigned int> &numbers,
          std::unordered_map<unsigned int,
                             std::vector<std::vector<unsigned int>>> &memo)
      -> std::vector<std::vector<unsigned int>> {
    if (target == 0)
      return {{}};

    if (memo.count(target))
      return memo[target];

    std::vector<unsigned int> shortestCombination;

    for (const auto &num : numbers) {

      if (num > target)
        continue;

      auto remainder = target - num;
      auto combination = _bestSumMemo(remainder, numbers, memo);

      if (!combination.empty()) {

        combination[0].push_back(num);

        if (shortestCombination.empty() ||
            combination[0].size() < shortestCombination.size())
          shortestCombination = combination[0];
      }
    }

    if (!shortestCombination.empty()) {
      memo[target] = {shortestCombination};
      return {shortestCombination};
    }

    memo[target] = {};
    return {};
  };

  std::unordered_map<unsigned int, std::vector<std::vector<unsigned int>>> memo;

  auto result = _bestSumMemo(target, numbers, memo);

  if (!result.empty())
    return result.front();

  return {};
}

std::vector<unsigned int> bestSumTable(const unsigned int target,
                                       std::vector<unsigned int> numbers) {

  std::vector<std::vector<std::vector<unsigned int>>> table(target + 1);
  table[0] = {{}};

  for (int i = 0; i < target; i++) {

    if (!table[i].empty()) {

      auto it = numbers.begin();
      while (it != numbers.end()) {

        if (i + *it <= target)
          it++;

        else
          it = numbers.erase(it);
      }

      for (const auto &number : numbers) {
        if (i + number > 0 && i + number <= target) {
          table[i + number] = table[i];
          table[i + number][0].push_back(number);
        }
      }
    }
  }

  std::vector<unsigned int> shortestCombination;

  for (auto combination : table) {
    if (!combination.empty()) {
    if (shortestCombination.empty() ||
        combination.front().size() < shortestCombination.size())
      shortestCombination = combination.front();
}

  }

  // if (!table.back().empty())
  //    return table.back().front();

  return shortestCombination;
}
