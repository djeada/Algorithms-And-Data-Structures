
template <typename T, size_t len>
void count_sort(std::array<T, len> &items, const int exp) {

  const unsigned int RANGE = 255;
  std::vector<T> count(RANGE, 0);

  for (unsigned int i = 0; i < len; ++i)
    count[(items[i] / exp) % 10]++;

  for (auto it = std::next(count.begin()); it != count.end();
       it = std::next(it))
    *it += *(std::prev(it));

  std::array<T, len> output;
  for (int i = len; i >= 0; i--)
    output[--count[(items[i] / exp) % 10]] = items[i];

  std::move(output.begin(), output.end(), items.begin());
}

template <class T> void radix_sort(T &items) {

  auto max = *(std::max_element(items.begin(), items.end()));

  for (int i = 1; max / i > 0; i *= 10)
    count_sort(items, i);
}
