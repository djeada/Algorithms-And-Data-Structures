#include "insertion_sort.h"

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T> &arr) {
  for (auto it = std::begin(arr); it != std::end(arr); ++it) {
    std::rotate(std::upper_bound(std::begin(arr), it, *it), it, std::next(it));
  }
}

// Explicit template instantiations
template void insertion_sort<int>(std::vector<int> &arr);
template void insertion_sort<float>(std::vector<float> &arr);
template void insertion_sort<double>(std::vector<double> &arr);
template void insertion_sort<char>(std::vector<char> &arr);
