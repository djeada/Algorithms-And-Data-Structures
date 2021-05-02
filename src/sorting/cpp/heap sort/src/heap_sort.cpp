#include <vector>

template <typename T> void heapify(std::vector<T> &arr, int curr, int offset) {

  auto parent = [](int i) { return i >> 1; };

  auto left_child = [](int i) { return i << 1; };

  auto right_child = [](int i) { return (i << 1) + 1; };

  if (curr + offset > arr.size())
    return;

  heapify(arr, left_child(curr), offset);
  heapify(arr, right_child(curr), offset);

  if (curr > 1 && arr[curr + offset - 1] < arr[parent(curr) + offset - 1])
    std::swap(arr[curr + offset - 1], arr[parent(curr) + offset - 1]);
}

template <typename T> void heap_sort(std::vector<T> &arr) {

  for (int i = 0; i < arr.size(); i++)
    heapify<T>(arr, 1, i);
}

template void heap_sort<int>(std::vector<int> &arr);
template void heap_sort<float>(std::vector<float> &arr);
template void heap_sort<double>(std::vector<double> &arr);
template void heap_sort<char>(std::vector<char> &arr);
