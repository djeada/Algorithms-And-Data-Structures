#include "heap_sort.h"

#include <cstddef>
#include <utility>
#include <vector>

namespace {

/**
 * @brief Sift the element at `root` down until the max-heap property holds
 *        for the heap occupying arr[0, size).
 */
template <typename T>
void sift_down(std::vector<T> &arr, std::size_t root, std::size_t size) {
  while (true) {
    std::size_t largest = root;
    const std::size_t left = 2 * root + 1;
    const std::size_t right = left + 1;

    if (left < size && arr[largest] < arr[left]) {
      largest = left;
    }
    if (right < size && arr[largest] < arr[right]) {
      largest = right;
    }
    if (largest == root) {
      return;
    }
    std::swap(arr[root], arr[largest]);
    root = largest;
  }
}

} // namespace

template <typename T> void heap_sort(std::vector<T> &arr) {
  const std::size_t n = arr.size();
  if (n < 2) {
    return;
  }

  // Build a max-heap in O(n).
  for (std::size_t i = n / 2; i-- > 0;) {
    sift_down(arr, i, n);
  }

  // Move the maximum to the end and restore the heap on the remainder.
  for (std::size_t end = n - 1; end > 0; --end) {
    std::swap(arr[0], arr[end]);
    sift_down(arr, 0, end);
  }
}

// Explicit template instantiations
template void heap_sort<int>(std::vector<int> &arr);
template void heap_sort<float>(std::vector<float> &arr);
template void heap_sort<double>(std::vector<double> &arr);
template void heap_sort<char>(std::vector<char> &arr);
