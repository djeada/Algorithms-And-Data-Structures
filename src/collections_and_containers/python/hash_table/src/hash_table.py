"""Hash table implementation with separate chaining."""

from __future__ import annotations

from typing import Any, Callable


class HashTable:
    """A hash table using separate chaining for collision resolution."""

    def __init__(self, hash_function: Callable[[Any], int], size: int = 10) -> None:
        self.hash_function = hash_function
        self._num_elements = 0
        self._size = size
        self.load_factor = 0.7
        self.table: list[list[tuple[Any, Any]] | None] = [None] * size

    def add(self, key: Any, value: Any) -> None:
        """Add or update a key-value pair."""
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            self.table[index] = []
        # Handle overwriting existing keys
        for i, (k, _) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))
        self._num_elements += 1
        if self._num_elements / self._size > self.load_factor:
            self.grow()

    def get(self, key: Any) -> Any:
        """Get the value for a key."""
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            raise KeyError("Key not found")
        for k, v in self.table[index]:
            if k == key:
                return v
        return None

    def remove(self, key: Any) -> None:
        """Remove a key-value pair."""
        index = self.hash_function(key) % self._size
        if self.table[index] is None:
            raise KeyError("Key not found")
        for i, (k, _) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                self._num_elements -= 1
                break
        if self._num_elements / self._size < (1 - self.load_factor) / 2:
            self.shrink()

    def size(self) -> int:
        """Return the number of elements in the hash table."""
        return self._num_elements

    def clear(self) -> None:
        """Remove all elements from the hash table."""
        self.table = [None] * self._size
        self._num_elements = 0

    def contains(self, key: Any) -> bool:
        """Check if the hash table contains a key."""
        try:
            self.get(key)
            return True
        except KeyError:
            return False

    def __getitem__(self, key: Any) -> Any:
        return self.get(key)

    def __setitem__(self, key: Any, value: Any) -> None:
        self.add(key, value)

    def grow(self) -> None:
        """Double the capacity of the hash table."""
        self._size = self._size * 2 + 1
        new_table: list[list[tuple[Any, Any]] | None] = [None] * self._size
        for bucket in self.table:
            if bucket is None:
                continue
            for key, value in bucket:
                index = self.hash_function(key) % self._size
                if new_table[index] is None:
                    new_table[index] = []
                new_table[index].append((key, value))
        self.table = new_table

    def shrink(self) -> None:
        """Halve the capacity of the hash table."""
        self._size = (self._size - 1) // 2
        new_table: list[list[tuple[Any, Any]] | None] = [None] * self._size
        for bucket in self.table:
            if bucket is None:
                continue
            for key, value in bucket:
                index = self.hash_function(key) % self._size
                if new_table[index] is None:
                    new_table[index] = []
                new_table[index].append((key, value))
        self.table = new_table
