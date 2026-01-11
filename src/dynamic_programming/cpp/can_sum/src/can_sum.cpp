#include "can_sum.h"
#include <functional>
#include <unordered_map>

bool canSumBasic(const unsigned int target,
                 const std::vector<unsigned int> &numbers) {

  if (target == 0)
    return true;

  for (const auto &num : numbers) {

    if (num > target)
      return false;

    auto remainder = target - num;

    if (canSumBasic(remainder, numbers))
      return true;
  }

  return false;
}

bool canSumMemo(const unsigned int target,
                const std::vector<unsigned int> &numbers) {

  std::function<bool(const unsigned int &, const std::vector<unsigned int> &,
                     std::unordered_map<unsigned int, bool> &)>
      _canSumMemo;
  _canSumMemo = [&](const unsigned int target,
                    const std::vector<unsigned int> &numbers,
                    std::unordered_map<unsigned int, bool> &memo) -> bool {
    if (target == 0)
      return true;

    if (memo.count(target))
      return memo[target];

    for (const auto &num : numbers) {

      if (num > target)
        return false;

      auto remainder = target - num;

      if (_canSumMemo(remainder, numbers, memo)) {
        memo[target] = true;
        return true;
      }
    }

    memo[target] = false;
    return false;
  };

  std::unordered_map<unsigned int, bool> memo;

  return _canSumMemo(target, numbers, memo);
}

bool canSumTable(const unsigned int target,
                 const std::vector<unsigned int> &numbers) {

  std::vector<bool> table(target + 1, false);
  table[0] = true;

  for (unsigned int i = 0; i < target; i++) {
    if (table[i]) {
      for (const auto &number : numbers) {
        if (i + number <= target)
          table[i + number] = true;
      }
    }
  }

  return table.back();
}
