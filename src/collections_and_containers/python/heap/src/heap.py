import abc


class Heap(abc.ABC):
    def __init__(self, comp: callable):
        self.data = []
        self.comp = comp

    def __copy__(self):
        new_heap = self.__class__(self.comp)
        new_heap.data = self.data[:]
        return new_heap

    def push(self, val):
        self.data.append(val)
        self._bubble_up(self.size() - 1)

    def pop(self):
        if self.empty():
            raise IndexError("Cannot pop from an empty heap")
        self._swap(0, self.size() - 1)
        val = self.data.pop()
        self._bubble_down(0)
        return val

    def peek(self):
        if self.empty():
            raise IndexError("Cannot peek at an empty heap")
        return self.data[0]

    def size(self):
        return len(self.data)

    def empty(self):
        return self.size() == 0

    def is_max_heap(self):
        return self.comp(2, 1)

    def is_min_heap(self):
        return self.comp(1, 2)

    def _bubble_up(self, index):
        if index == 0:
            return
        parent = self._parent(index)
        if self.comp(self.data[index], self.data[parent]):
            self._swap(index, parent)
            self._bubble_up(parent)

    def _bubble_down(self, index):
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

    def _parent(self, index):
        return (index - 1) // 2

    def _left(self, index):
        return 2 * index + 1

    def _right(self, index):
        return 2 * index + 2

    def _swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            return self.data == other.data
        return False

    def __str__(self):
        return str(self.data)


class MinHeap(Heap):
    def __init__(self):
        super().__init__(comp=lambda x, y: x < y)


class MaxHeap(Heap):
    def __init__(self):
        super().__init__(comp=lambda x, y: x > y)
