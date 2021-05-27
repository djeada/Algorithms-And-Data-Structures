#include "how_sum.h"
#include <functional>
#include <unordered_map>

std::vector<unsigned int>
howSumBasic(const unsigned int target,
            const std::vector<unsigned int> &numbers) {

  std::function<std::vector<std::vector<unsigned int>>(
      const unsigned int, const std::vector<unsigned int> &)>
      _howSumBasic;
  _howSumBasic = [&](const unsigned int target,
                     const std::vector<unsigned int> &numbers)
      -> std::vector<std::vector<unsigned int>> {
    if (target == 0)
      return {{}};

    for (const auto &num : numbers) {

      if (num > target)
        return {};

      auto remainder = target - num;
      if (remainder >= 0) {
        auto combination = _howSumBasic(remainder, numbers);

        if (!combination.empty()) {
          combination[0].push_back(num);
          return combination;
        }
      }
    }

    return {};
  };

  auto result = _howSumBasic(target, numbers);

  if (!result.empty())
    return result.front();

  return {};
}

std::vector<unsigned int> howSumMemo(const unsigned int target,
                                     const std::vector<unsigned int> &numbers) {

  std::function<std::vector<std::vector<unsigned int>>(
      const unsigned int, const std::vector<unsigned int> &,
      std::unordered_map<unsigned int, std::vector<std::vector<unsigned int>>>
          &)>
      _howSumMemo;
  _howSumMemo =
      [&](const unsigned int target, const std::vector<unsigned int> &numbers,
          std::unordered_map<unsigned int,
                             std::vector<std::vector<unsigned int>>> &memo)
      -> std::vector<std::vector<unsigned int>> {
    if (target == 0)
      return {{}};

    if (memo.count(target))
      return memo[target];

    for (const auto &num : numbers) {

      if (num > target)
        return {};

      auto remainder = target - num;
      if (remainder >= 0) {
        auto combination = _howSumMemo(remainder, numbers, memo);

        if (!combination.empty()) {
          combination[0].push_back(num);
          memo[target] = combination;
          return combination;
        }
      }
    }

    memo[target] = {};
    return {};
  };

  std::unordered_map<unsigned int, std::vector<std::vector<unsigned int>>> memo;

  auto result = _howSumMemo(target, numbers, memo);

  if (!result.empty())
    return result.front();

  return {};
}

std::vector<unsigned int> howSumTable(const unsigned int target,
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

  if (!table.back().empty())
    return table.back().front();

  return {};
}
