
template <class T> void quicksort(std::vector<T> &array, int hi, int lo = 0) {
  while (hi > lo) {
    int i = lo;
    int j = hi;

    while (i < j) {
      while (array[i] < array[lo] && i < j)
        i++;
      while (array[--j] > array[lo])
        ;
      if (i < j)
        swap(array[i], array[j]);
    }
    swap(array[lo], array[j]);

    if (j - lo > hi - (j + 1)) {
      quicksort(array, j - 1, lo);
      lo = j + 1;
    } else {
      quicksort(array, hi, j + 1);
      hi = j - 1;
    }
  }
}
