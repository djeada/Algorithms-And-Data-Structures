#include "all_permutations.h"
#include <functional>

std::vector<std::vector<int>> all_permutations(std::vector<int> input_list) {
  std::vector<std::vector<int>> result;

  // Nested function to generate permutations
  std::function<void(std::vector<int>, std::vector<int>)> _all_permutations;
  _all_permutations = [&](std::vector<int> input_list,
                          std::vector<int> output_list) {
    if (output_list.size() == input_list.size()) {
      result.push_back(output_list);
      return;
    }

    for (const auto &element : input_list) {
      if (std::find(output_list.begin(), output_list.end(), element) ==
          output_list.end()) {
        output_list.push_back(element);
        _all_permutations(input_list, output_list);
        output_list.pop_back();
      }
    }
  };

  // Initialize result and call nested function
  _all_permutations(input_list, {});
  return result;
}
