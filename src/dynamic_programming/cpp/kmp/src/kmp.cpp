#include "kmp.h"
#include <functional>

std::vector<int> search(const std::string &text, const std::string &pattern) {

  std::function<std::vector<int>(const std::string &)>
      find_longest_prefix_suffix = [&](const std::string &word) {
        std::vector<int> result(word.size());
        int i = 1;
        int j = 0;
        while (i < word.size()) {
          if (word[i] == word[j]) {
            j += 1;
            result[i] = j;
            i += 1;
          } else {
            if (j != 0) {
              j = result[j - 1];
            } else {
              result[i] = 0;
              i += 1;
            }
          }
        }
        return result;
      };

  std::vector<int> result;
  if (pattern.empty()) {
    // The empty pattern matches at every position (like std::string::find).
    for (size_t i = 0; i <= text.size(); i++) {
      result.push_back(static_cast<int>(i));
    }
    return result;
  }

  auto longest_prefix_suffix = find_longest_prefix_suffix(pattern);
  int j = 0;
  for (int i = 0; i < static_cast<int>(text.size()); i++) {
    while (j != 0 && text[i] != pattern[j]) {
      j = longest_prefix_suffix[j - 1];
    }
    if (text[i] == pattern[j]) {
      j += 1;
    }
    if (j == pattern.size()) {
      result.push_back(i - j + 1);
      j = longest_prefix_suffix[j - 1];
    }
  }
  return result;
}
