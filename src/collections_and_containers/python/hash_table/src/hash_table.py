import functools
from typing import Any, Callable, List, Tuple


class HashTable:
    def __init__(self, hash_function: Callable[[Any], int], size: int = 10):
        self.hash_function = hash_function
        self._num_elements = 0
        self._size = size
        self.load_factor = 0.7
        self.table = [None] * size

    def add(self, key: Any, value: Any):
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            self.table[index] = []
        # add should handle overwriting existing keys
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))
        self._num_elements += 1
        if self._num_elements / self._size > self.load_factor:
            self.grow()

    def get(self, key: Any) -> Any:
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            raise Exception("Key not found")
        for k, v in self.table[index]:
            if k == key:
                return v
        return None

    def remove(self, key: Any):
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            raise Exception("Key not found")
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                self._num_elements -= 1
                break
        if self._num_elements / self._size < (1 - self.load_factor) / 2:
            self.shrink()

    def size(self) -> int:
        return self._num_elements

    def clear(self):
        self.table = [None] * self._size
        self._num_elements = 0

    def contains(self, key: Any) -> bool:
        try:
            self.get(key)
            return True
        except Exception:
            return False

    def __getitem__(self, key: Any) -> Any:
        return self.get(key)

    def __setitem__(self, key: Any, value: Any):
        self.add(key, value)

    def grow(self):
        self._size = self._size * 2 + 1
        new_table = [None] * self._size
        for i in range(len(self.table)):
            if self.table[i] is None:
                continue
            for key, value in self.table[i]:
                index = self.hash_function(key) % self._size
                if new_table[index] is None:
                    new_table[index] = []
                new_table[index].append((key, value))
        self.table = new_table

    def shrink(self):
        self._size = (self._size - 1) // 2
        new_table = [None] * self._size
        for i in range(len(self.table)):
            if self.table[i] is None:
                continue
            for key, value in self.table[i]:
                index = self.hash_function(key) % self._size
                if new_table[index] is None:
                    new_table[index] = []
                new_table[index].append((key, value))
        self.table = new_table
