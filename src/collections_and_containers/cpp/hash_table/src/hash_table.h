#pragma once

#include <cstdlib>
#include <functional>
#include <memory>
#include <vector>

template <class Key, class Value> class HashTable {

public:
  HashTable(std::function<int(Key)> hash_function, int size = 10);
  ~HashTable();
  void add(Key key, Value value);
  Value get(Key key) const;
  void remove(Key key);
  bool contains(Key key) const;
  unsigned int size() const;
  bool empty() const;
  void clear();
  Value &operator[](Key key);
  const Value &operator[](Key key) const;

private:
  std::function<int(Key)> hash_function;
  int _num_elements;
  int _size;
  float load_factor;
  std::vector<std::shared_ptr<std::vector<std::pair<Key, Value>>>> table;
  void grow();
  void shrink();
  int hash_index(Key key) const;
};
