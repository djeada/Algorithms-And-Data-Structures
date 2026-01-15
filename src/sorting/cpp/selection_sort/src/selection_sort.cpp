#include "selection_sort.h"

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
void selection_sort(std::vector<T> &arr) {
  for (auto it = std::begin(arr); it != std::end(arr); ++it) {
    auto const min_elem = std::min_element(it, std::end(arr));
    std::iter_swap(min_elem, it);
  }
}

// Explicit template instantiations
template void selection_sort<int>(std::vector<int> &arr);
template void selection_sort<float>(std::vector<float> &arr);
template void selection_sort<double>(std::vector<double> &arr);
template void selection_sort<char>(std::vector<char> &arr);
