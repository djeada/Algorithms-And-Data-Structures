#include <vector>

template <class T> void _quick_sort(std::vector<T> &arr, int start, int end) {
  while (end > start) {
    int i = start;
    int j = end;

    while (i < j) {
      while (arr[i] < arr[start] && i < j)
        i++;
      while (arr[--j] > arr[start])
        ;
      if (i < j)
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[start], arr[j]);

    if (j - start > end - (j + 1)) {
      _quick_sort(arr, start, j - 1);
      start = j + 1;
    } else {
      _quick_sort(arr, j + 1, end);
      end = j - 1;
    }
  }
}

template <class T> void quick_sort(std::vector<T> &arr) {
  _quick_sort(arr, 0, arr.size());
}

template void quick_sort<int>(std::vector<int> &arr);
template void quick_sort<float>(std::vector<float> &arr);
template void quick_sort<double>(std::vector<double> &arr);
template void quick_sort<char>(std::vector<char> &arr);
