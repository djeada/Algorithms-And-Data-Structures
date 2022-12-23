#include "all_construct.h"
#include <functional>
#include <unordered_map>

std::vector<std::vector<std::string>>
allConstructBasic(const std::string &target,
                  const std::vector<std::string> &wordBank) {
  if (target.empty())
    return {{}};

  std::vector<std::vector<std::string>> result;

  for (const auto &word : wordBank) {

    if (target.size() >= word.size() && target.substr(0, word.size()) == word) {
      auto suffix = target.substr(word.size());
      auto suffixWays = allConstructBasic(suffix, wordBank);

      std::vector<std::string> targetWays;

      for (const auto &way : suffixWays) {

        for (const auto &s : way)
          targetWays.push_back(s);

        targetWays.push_back(word);
      }

      if (!targetWays.empty())
        result.push_back(targetWays);
    }
  }

  return result;
}

std::vector<std::vector<std::string>>
allConstructMemo(const std::string &target,
                 const std::vector<std::string> &wordBank) {

  std::function<std::vector<std::vector<std::string>>(
      const std::string &, const std::vector<std::string> &,
      std::unordered_map<std::string, std::vector<std::vector<std::string>>> &)>
      _allConstructMemo;
  _allConstructMemo =
      [&](const std::string &target, const std::vector<std::string> &wordBank,
          std::unordered_map<std::string, std::vector<std::vector<std::string>>>
              &memo) -> std::vector<std::vector<std::string>> {
    if (target.empty())
      return {{}};

    if (memo.count(target))
      return memo[target];

    std::vector<std::vector<std::string>> result;

    for (const auto &word : wordBank) {

      if (target.size() >= word.size() &&
          target.substr(0, word.size()) == word) {
        auto suffix = target.substr(word.size());
        auto suffixWays = _allConstructMemo(suffix, wordBank, memo);

        std::vector<std::string> targetWays;

        for (const auto &way : suffixWays) {

          for (const auto &s : way)
            targetWays.push_back(s);

          targetWays.push_back(word);
        }

        if (!targetWays.empty())
          result.push_back(targetWays);
      }
    }

    memo[target] = result;
    return result;
  };

  std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;

  return _allConstructMemo(target, wordBank, memo);
}

std::vector<std::vector<std::string>>
allConstructTable(const std::string &target,
                  const std::vector<std::string> &wordBank) {

  std::vector<std::vector<std::vector<std::string>>> table(target.size() + 1);
  table[0] = {{}};

  for (int i = 0; i < target.size(); i++) {

    for (const auto &word : wordBank) {

      if (target.substr(i, word.size()) == word) {

        std::vector<std::vector<std::string>> newCombinations;

        for (auto combination : table[i]) {
          std::vector<std::string> temp = {word};
          combination.insert(combination.end(), temp.begin(), temp.end());
          newCombinations.push_back(combination);
        }

        table[i + word.size()].insert(table[i + word.size()].end(),
                                      newCombinations.begin(),
                                      newCombinations.end());
      }
    }
  }

  return table.back();
}
