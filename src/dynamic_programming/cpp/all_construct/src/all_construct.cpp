#include "all_construct.h"
#include <functional>
#include <unordered_map>

std::vector<std::vector<std::string>>
allConstructBasic(const std::string &target,
                  const std::vector<std::string> &word_bank) {

  std::function<std::vector<std::vector<std::string>>(const std::string &)>
      recurse = [&](const std::string &target)
      -> std::vector<std::vector<std::string>> {
    if (target.empty()) {
      return {{}};
    }

    std::vector<std::vector<std::string>> result;
    for (const auto &word : word_bank) {
      if (target.find(word) == 0) {
        auto suffix_ways = recurse(target.substr(word.size()));
        for (auto &way : suffix_ways) {
          way.push_back(word);
        }
        result.insert(result.end(), suffix_ways.begin(), suffix_ways.end());
      }
    }

    return result;
  };

  return recurse(target);
}

std::vector<std::vector<std::string>>
allConstructMemo(const std::string &target,
                 const std::vector<std::string> &word_bank) {
  std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;

  std::function<std::vector<std::vector<std::string>>(const std::string &)>
      recurse = [&](const std::string &target)
      -> std::vector<std::vector<std::string>> {
    if (target.empty()) {
      return {{}};
    }

    if (memo.count(target) > 0) {
      return memo[target];
    }

    std::vector<std::vector<std::string>> result;
    for (const auto &word : word_bank) {
      if (target.find(word) == 0) {
        auto suffix_ways = recurse(target.substr(word.size()));
        for (auto &way : suffix_ways) {
          way.push_back(word);
        }
        result.insert(result.end(), suffix_ways.begin(), suffix_ways.end());
      }
    }

    memo[target] = result;
    return result;
  };

  return recurse(target);
}

std::vector<std::vector<std::string>>
allConstructTable(const std::string &target,
                  const std::vector<std::string> &word_bank) {
  std::vector<std::vector<std::vector<std::string>>> table(target.size() + 1);
  table[0] = {{}};

  for (size_t i = 0; i <= target.size(); ++i) {
    for (const auto &word : word_bank) {
      if (target.substr(i, word.size()) == word) {
        auto new_combination = table[i];
        for (auto &combination : new_combination) {
          combination.push_back(word);
        }
        table[i + word.size()].insert(table[i + word.size()].end(),
                                      new_combination.begin(),
                                      new_combination.end());
      }
    }
  }

  return table[target.size()];
}