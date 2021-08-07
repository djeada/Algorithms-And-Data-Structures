#include "selection_sort.h"
#include <algorithm>
#include <vector>

template <class T> void selection_sort(std::vector<T> &arr) {
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    auto const selection = std::min_element(it, arr.end());
    std::iter_swap(selection, it);
  }
}

template void selection_sort<int>(std::vector<int> &arr);
template void selection_sort<float>(std::vector<float> &arr);
template void selection_sort<double>(std::vector<double> &arr);
template void selection_sort<char>(std::vector<char> &arr);
