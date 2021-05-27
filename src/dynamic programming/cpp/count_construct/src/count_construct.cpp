#include "count_construct.h"
#include <functional>
#include <unordered_map>

int countConstructBasic(const std::string &target,
                        const std::vector<std::string> &wordBank) {
  if (target.empty())
    return 1;

  int totalCount = 0;

  for (const auto &word : wordBank) {

    if (target.size() >= word.size() && target.substr(0, word.size()) == word) {
      auto suffix = target.substr(word.size());
      totalCount += countConstructBasic(suffix, wordBank);
    }
  }

  return totalCount;
}

int countConstructMemo(const std::string &target,
                       const std::vector<std::string> &wordBank) {

  std::function<int(const std::string &, const std::vector<std::string> &,
                    std::unordered_map<std::string, int> &)>
      _countConstructMemo;
  _countConstructMemo = [&](const std::string &target,
                            const std::vector<std::string> &wordBank,
                            std::unordered_map<std::string, int> &memo) -> int {
    if (target.empty())
      return 1;

    if (memo.count(target))
      return memo[target];

    int totalCount = 0;

    for (const auto &word : wordBank) {

      if (target.size() >= word.size() &&
          target.substr(0, word.size()) == word) {
        auto suffix = target.substr(word.size());
        totalCount += _countConstructMemo(suffix, wordBank, memo);
      }
    }

    memo[target] = totalCount;
    return totalCount;
  };

  std::unordered_map<std::string, int> memo;

  return _countConstructMemo(target, wordBank, memo);
}

int countConstructTable(const std::string &target,
                        const std::vector<std::string> &wordBank) {

  std::vector<int> table(target.size() + 1);
  table[0] = 1;

  for (int i = 0; i < target.size(); i++) {

    for (const auto &word : wordBank) {

      if (target.substr(i, word.size()) == word) {

        table[i + word.size()] += table[i];
      }
    }
  }

  return table.back();
}
