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

  auto longest_prefix_suffix = find_longest_prefix_suffix(pattern);
  std::vector<int> result;
  int j = 0;
  for (int i = 0; i < text.size(); i++) {
    if (text[i] == pattern[j]) {
      j += 1;
    } else {
      if (j != 0) {
        j = longest_prefix_suffix[j - 1];
      }
    }
    if (j == pattern.size()) {
      result.push_back(i - j + 1);
      j = longest_prefix_suffix[j - 1];
    }
  }
  return result;
}
