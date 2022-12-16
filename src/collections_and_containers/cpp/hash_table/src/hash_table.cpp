#include "hash_table.h"
#include <stdexcept>

template <class Key, class Value>
HashTable<Key, Value>::HashTable(std::function<int(Key)> hash_function,
                                 int size) {
  this->hash_function = hash_function;
  this->_num_elements = 0;
  this->_size = size;
  this->load_factor = 0.75;
  this->table =
      std::vector<std::shared_ptr<std::vector<std::pair<Key, Value>>>>(size);
}

template <class Key, class Value> HashTable<Key, Value>::~HashTable() {
  this->table.clear();
}

template <class Key, class Value>
void HashTable<Key, Value>::add(Key key, Value value) {
  int index = this->hash_function(key) % this->_size;
  if (this->table[index] == nullptr) {
    this->table[index] = std::make_shared<std::vector<std::pair<Key, Value>>>();
  }
  this->table[index]->push_back(std::make_pair(key, value));
  this->_num_elements++;
  if (this->_num_elements / this->_size > this->load_factor) {
    this->grow();
  }
}

template <class Key, class Value> Value HashTable<Key, Value>::get(Key key) {
  int index = this->hash_function(key) % this->_size;
  if (this->table[index] == nullptr) {
    throw std::invalid_argument("Key not found");
  }
  for (auto it = this->table[index]->begin(); it != this->table[index]->end();
       it++) {
    if (it->first == key) {
      return it->second;
    }
  }
  throw std::invalid_argument("Key not found");
}

template <class Key, class Value> void HashTable<Key, Value>::remove(Key key) {
  int index = this->hash_function(key) % this->_size;
  if (this->table[index] == nullptr) {
    throw std::invalid_argument("Key not found");
  }
  for (auto it = this->table[index]->begin(); it != this->table[index]->end();
       it++) {
    if (it->first == key) {
      this->table[index]->erase(it);
      this->_num_elements--;
      if (this->_num_elements / this->_size < this->load_factor / 2) {
        this->shrink();
      }
      return;
    }
  }
  throw std::invalid_argument("Key not found");
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(Key key) {
  int index = this->hash_function(key) % this->_size;
  if (this->table[index] == nullptr) {
    return false;
  }
  for (auto it = this->table[index]->begin(); it != this->table[index]->end();
       it++) {
    if (it->first == key) {
      return true;
    }
  }
  return false;
}

template <class Key, class Value>
unsigned int HashTable<Key, Value>::size() const {
  return this->_num_elements;
}

template <class Key, class Value> void HashTable<Key, Value>::clear() {
  this->table.clear();
  this->_num_elements = 0;
  this->_size = 0;
}

template <class Key, class Value>
Value &HashTable<Key, Value>::operator[](Key key) {
  int index = this->hash_function(key) % this->_size;
  if (this->table[index] == nullptr) {
    throw std::invalid_argument("Key not found");
  }
  for (auto it = this->table[index]->begin(); it != this->table[index]->end();
       it++) {
    if (it->first == key) {
      return it->second;
    }
  }
  throw std::invalid_argument("Key not found");
}

template <class Key, class Value> void HashTable<Key, Value>::grow() {
  int new_size = this->_size * 2;
  std::vector<std::shared_ptr<std::vector<std::pair<Key, Value>>>> new_table(
      new_size);
  for (int i = 0; i < this->_size; i++) {
    if (this->table[i] != nullptr) {
      for (auto it = this->table[i]->begin(); it != this->table[i]->end();
           it++) {
        int index = this->hash_function(it->first) % new_size;
        if (new_table[index] == nullptr) {
          new_table[index] =
              std::make_shared<std::vector<std::pair<Key, Value>>>();
        }
        new_table[index]->push_back(std::make_pair(it->first, it->second));
      }
    }
  }
  this->table = new_table;
  this->_size = new_size;
}

template <class Key, class Value> void HashTable<Key, Value>::shrink() {
  int new_size = this->_size / 2;
  std::vector<std::shared_ptr<std::vector<std::pair<Key, Value>>>> new_table(
      new_size);
  for (int i = 0; i < this->_size; i++) {
    if (this->table[i] != nullptr) {
      for (auto it = this->table[i]->begin(); it != this->table[i]->end();
           it++) {
        int index = this->hash_function(it->first) % new_size;
        if (new_table[index] == nullptr) {
          new_table[index] =
              std::make_shared<std::vector<std::pair<Key, Value>>>();
        }
        new_table[index]->push_back(std::make_pair(it->first, it->second));
      }
    }
  }
  this->table = new_table;
  this->_size = new_size;
}

template class HashTable<std::string, int>;
template class HashTable<int, int>;
template class HashTable<std::string, std::string>;