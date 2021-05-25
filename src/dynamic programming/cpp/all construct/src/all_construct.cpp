#include "all_construct.h"

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
