#include "all_permutations.h"
#include <cstddef>
#include <functional>

std::vector<std::vector<int>> all_permutations(std::vector<int> input_list) {
  std::vector<std::vector<int>> result;

  // Nested function to generate permutations
  // Track used positions (not values) so duplicate elements are handled.
  std::vector<bool> used(input_list.size(), false);
  std::vector<int> output_list;
  std::function<void()> _all_permutations;
  _all_permutations = [&]() {
    if (output_list.size() == input_list.size()) {
      result.push_back(output_list);
      return;
    }

    for (std::size_t i = 0; i < input_list.size(); ++i) {
      if (!used[i]) {
        used[i] = true;
        output_list.push_back(input_list[i]);
        _all_permutations();
        output_list.pop_back();
        used[i] = false;
      }
    }
  };

  _all_permutations();
  return result;
}
