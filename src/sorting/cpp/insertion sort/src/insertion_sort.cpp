#include <algorithm>
#include <vector>

template <typename T> void insertion_sort(std::vector<T> &arr) {

  for (auto i = begin(arr); i != end(arr); ++i)
    std::rotate(std::upper_bound(begin(arr), i, *i), i, std::next(i));
}

template void insertion_sort<int>(std::vector<int> &arr);
template void insertion_sort<float>(std::vector<float> &arr);
template void insertion_sort<double>(std::vector<double> &arr);
template void insertion_sort<char>(std::vector<char> &arr);
