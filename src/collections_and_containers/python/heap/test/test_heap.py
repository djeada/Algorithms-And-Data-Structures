import random
from src.heap import Heap, MaxHeap, MinHeap
from unittest import TestCase
import unittest


class TestMaxHeap(unittest.TestCase):
    def test_empty_heap(self):
        heap = MaxHeap()
        self.assertTrue(heap.empty())

    def test_adding_multiple_elements(self):
        heap = MaxHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)
        self.assertEqual(heap.size(), 3)

        self.assertEqual(heap.pop(), 3)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 1)

        self.assertTrue(heap.empty())

        # adding the same elements in different order
        heap.push(3)
        heap.push(1)
        heap.push(2)

        self.assertEqual(heap.pop(), 3)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 1)

    def test_peek_vs_pop(self):
        # show the difference between peek and pop
        heap = MaxHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)

        self.assertEqual(heap.peek(), 3)
        self.assertEqual(heap.peek(), 3)
        self.assertEqual(heap.size(), 3)

        self.assertEqual(heap.pop(), 3)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 1)
        self.assertTrue(heap.empty())

    def test_peek_when_empty(self):
        heap = MaxHeap()
        self.assertRaises(IndexError, heap.peek)

    def test_pop_when_empty(self):
        heap = MaxHeap()
        self.assertRaises(IndexError, heap.pop)

    def test_is_max_heap(self):
        heap = MaxHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)

        self.assertTrue(heap.is_max_heap())


class TestMinHeap(unittest.TestCase):
    def test_empty_heap(self):
        heap = MinHeap()
        self.assertTrue(heap.empty())

    def test_adding_multiple_elements(self):
        heap = MinHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)
        self.assertEqual(heap.size(), 3)

        self.assertEqual(heap.pop(), 1)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 3)

        self.assertTrue(heap.empty())

        # adding the same elements in different order
        heap.push(3)
        heap.push(1)
        heap.push(2)

        self.assertEqual(heap.pop(), 1)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 3)

    def test_peek_vs_pop(self):
        # show the difference between peek and pop
        heap = MinHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)

        self.assertEqual(heap.peek(), 1)
        self.assertEqual(heap.peek(), 1)
        self.assertEqual(heap.size(), 3)

        self.assertEqual(heap.pop(), 1)
        self.assertEqual(heap.pop(), 2)
        self.assertEqual(heap.pop(), 3)
        self.assertTrue(heap.empty())

    def test_peek_when_empty(self):
        heap = MinHeap()
        self.assertRaises(IndexError, heap.peek)

    def test_pop_when_empty(self):
        heap = MinHeap()
        self.assertRaises(IndexError, heap.pop)

    def test_is_min_heap(self):
        heap = MinHeap()
        heap.push(1)
        heap.push(2)
        heap.push(3)

        self.assertTrue(heap.is_min_heap())


class TestHeapRandomized(TestCase):
    def test_pop_order_matches_sorted(self):
        rng = random.Random(5)
        values = [rng.randrange(-50, 50) for _ in range(500)]
        min_heap, max_heap = MinHeap(), MaxHeap()
        for v in values:
            min_heap.push(v)
            max_heap.push(v)
        self.assertEqual([min_heap.pop() for _ in values], sorted(values))
        self.assertEqual([max_heap.pop() for _ in values], sorted(values, reverse=True))
        self.assertRaises(IndexError, min_heap.pop)
        self.assertRaises(IndexError, max_heap.peek)


if __name__ == "__main__":
    unittest.main()
