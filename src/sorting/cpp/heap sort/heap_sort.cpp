#include <vector>

template <class T> void heapify(vector<T> &t, int cur, int offset) {

  auto parent = [](int i) { return i >> 1; };

  auto left_child = [](int i) { return i << 1; };

  auto right_child = [](int i) { return (i << 1) + 1; };

  if (cur + offset > t.size())
    return;

  heapify(t, left_child(cur), offset);
  heapify(t, right_child(cur), offset);

  if (cur > 1 && t[cur + offset - 1] < t[parent(cur) + offset - 1])
    swap(t[cur + offset - 1], t[parent(cur) + offset - 1]);
}

template <class T> void heap_sort(vector<T> &t) {
  for (int i = 0; i < t.size(); ++i) {
    heapify<T>(t, 1, i);
  }
}
