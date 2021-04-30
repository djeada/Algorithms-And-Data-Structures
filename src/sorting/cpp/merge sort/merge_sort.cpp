#include <vector>

template <typename T> void merge(std::vector<T> &arr, int start, int end) {
  int z, x, y, mid;
  vector<T> temp(end - start + 1);
  mid = (start + end) / 2;
  z = 0;
  x = start;
  y = mid + 1;

  while (x <= mid && y <= end) {
    if (arr[x] < arr[y]) {
      temp[z] = arr[x];
      ++x, ++z;
    } else {
      temp[z] = arr[y];
      ++y, ++z;
    }
  }

  while (x <= mid) {
    temp[z] = arr[x];
    ++x, ++z;
  }

  while (y <= end) {
    temp[z] = arr[y];
    ++y, ++z;
  }

  for (int i = start; i <= end; ++i)
    arr[i] = temp[i - start];
}

template <typename T> void merge_sort(std::vector<T> &arr, int start, int end) {

  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, end);
  }
}
