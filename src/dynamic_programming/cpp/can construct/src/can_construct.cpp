#include "can_construct.h"
#include <functional>
#include <unordered_map>

bool canConstructBasic(const std::string &target,
                       const std::vector<std::string> &wordBank) {

  if (target.empty())
    return true;

  for (const auto &word : wordBank) {

    if (target.size() >= word.size() && target.substr(0, word.size()) == word) {
      auto remainder = target.substr(word.size());

      if (canConstructBasic(remainder, wordBank))
        return true;
    }
  }

  return false;
}

bool canConstructMemo(const std::string &target,
                      const std::vector<std::string> &wordBank) {

  std::function<bool(const std::string &, const std::vector<std::string> &,
                     std::unordered_map<std::string, bool> &)>
      _canConstructMemo;
  _canConstructMemo = [&](const std::string &target,
                          const std::vector<std::string> &wordBank,
                          std::unordered_map<std::string, bool> &memo) -> bool {
    if (target.empty())
      return true;

    if (memo.count(target))
      return memo[target];

    for (const auto &word : wordBank) {

      if (target.size() >= word.size() &&
          target.substr(0, word.size()) == word) {
        auto remainder = target.substr(word.size());

        if (_canConstructMemo(remainder, wordBank, memo)) {
          memo[target] = true;
          return true;
        }
      }
    }

    memo[target] = false;
    return false;
  };

  std::unordered_map<std::string, bool> memo;

  return _canConstructMemo(target, wordBank, memo);
}

bool canConstructTable(const std::string &target,
                       const std::vector<std::string> &wordBank) {

  std::vector<bool> table(target.size() + 1, false);
  table[0] = true;

  for (int i = 0; i < target.size(); i++) {

    if (table[i]) {
      for (const auto &word : wordBank) {

        if (target.substr(i, word.size()) == word) {

          table[i + word.size()] = true;
        }
      }
    }
  }

  return table.back();
}
