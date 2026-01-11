"""Heap data structure implementations (min-heap and max-heap)."""

from __future__ import annotations

import abc
from typing import Any, Callable


class Heap(abc.ABC):
    """Abstract base class for heap data structures."""

    def __init__(self, comp: Callable[[Any, Any], bool]) -> None:
        self.data: list[Any] = []
        self.comp = comp

    def __copy__(self) -> Heap:
        new_heap = self.__class__.__new__(self.__class__)
        new_heap.comp = self.comp
        new_heap.data = self.data[:]
        return new_heap

    def push(self, val: Any) -> None:
        """Add an element to the heap."""
        self.data.append(val)
        self._bubble_up(self.size() - 1)

    def pop(self) -> Any:
        """Remove and return the top element."""
        if self.empty():
            raise IndexError("Cannot pop from an empty heap")
        self._swap(0, self.size() - 1)
        val = self.data.pop()
        self._bubble_down(0)
        return val

    def peek(self) -> Any:
        """Return the top element without removing it."""
        if self.empty():
            raise IndexError("Cannot peek at an empty heap")
        return self.data[0]

    def size(self) -> int:
        """Return the number of elements in the heap."""
        return len(self.data)

    def empty(self) -> bool:
        """Check if the heap is empty."""
        return self.size() == 0

    def is_max_heap(self) -> bool:
        """Check if this is a max-heap."""
        return self.comp(2, 1)

    def is_min_heap(self) -> bool:
        """Check if this is a min-heap."""
        return self.comp(1, 2)

    def _bubble_up(self, index: int) -> None:
        if index == 0:
            return
        parent = self._parent(index)
        if self.comp(self.data[index], self.data[parent]):
            self._swap(index, parent)
            self._bubble_up(parent)

    def _bubble_down(self, index: int) -> None:
        left = self._left(index)
        right = self._right(index)
        smallest = index
        if left < self.size() and self.comp(self.data[left], self.data[smallest]):
            smallest = left
        if right < self.size() and self.comp(self.data[right], self.data[smallest]):
            smallest = right
        if smallest != index:
            self._swap(index, smallest)
            self._bubble_down(smallest)

    def _parent(self, index: int) -> int:
        return (index - 1) // 2

    def _left(self, index: int) -> int:
        return 2 * index + 1

    def _right(self, index: int) -> int:
        return 2 * index + 2

    def _swap(self, i: int, j: int) -> None:
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def __eq__(self, other: object) -> bool:
        if isinstance(other, self.__class__):
            return self.data == other.data
        return False

    def __str__(self) -> str:
        return str(self.data)


class MinHeap(Heap):
    """A min-heap where the smallest element is at the top."""

    def __init__(self) -> None:
        super().__init__(comp=lambda x, y: x < y)


class MaxHeap(Heap):
    """A max-heap where the largest element is at the top."""

    def __init__(self) -> None:
        super().__init__(comp=lambda x, y: x > y)
