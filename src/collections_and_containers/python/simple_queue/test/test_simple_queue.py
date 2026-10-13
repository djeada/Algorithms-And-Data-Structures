from src.simple_queue import Queue
from unittest import TestCase
import unittest


class TestSimpleQueue(TestCase):
    def test_empty_queue(self):
        queue = Queue()
        self.assertTrue(queue.empty())

    def test_adding_multiple_elements(self):
        queue = Queue()
        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)
        self.assertEqual(queue.size(), 3)

        self.assertEqual(queue.dequeue(), 1)
        self.assertEqual(queue.dequeue(), 2)
        self.assertEqual(queue.dequeue(), 3)

        self.assertTrue(queue.empty())

        # adding the same elements in different order
        queue.enqueue(3)
        queue.enqueue(1)
        queue.enqueue(2)

        self.assertEqual(queue.dequeue(), 3)
        self.assertEqual(queue.dequeue(), 1)
        self.assertEqual(queue.dequeue(), 2)

    def test_front_and_back(self):
        queue = Queue()
        queue.enqueue(1)
        queue.enqueue(2)
        queue.enqueue(3)

        self.assertEqual(queue.front(), 1)
        self.assertEqual(queue.back(), 3)

    def test_front_when_empty(self):
        queue = Queue()
        self.assertRaises(IndexError, queue.front)

    def test_back_when_empty(self):
        queue = Queue()
        self.assertRaises(IndexError, queue.back)

    def test_dequeue_when_empty(self):
        queue = Queue()
        self.assertEqual(queue.dequeue(), None)


class TestSimpleQueueWrapAround(TestCase):
    def test_interleaved_operations_preserve_fifo_order(self):
        queue = Queue()
        expected = []
        counter = 0
        for round_ in range(50):
            for _ in range(7):
                queue.enqueue(counter)
                expected.append(counter)
                counter += 1
                self.assertEqual(queue.back(), counter - 1)
            for _ in range(3 + round_ % 3):
                self.assertEqual(queue.front(), expected[0])
                self.assertEqual(queue.dequeue(), expected.pop(0))
            self.assertEqual(queue.size(), len(expected))
        while expected:
            self.assertEqual(queue.dequeue(), expected.pop(0))
        self.assertTrue(queue.empty())

    def test_fill_exactly_to_capacity_after_dequeue(self):
        queue = Queue()
        for i in range(10):
            queue.enqueue(i)
        self.assertEqual(queue.dequeue(), 0)
        queue.enqueue(10)
        queue.enqueue(11)
        self.assertEqual([queue.dequeue() for _ in range(11)], list(range(1, 12)))

    def test_equality_ignores_internal_layout(self):
        a = Queue()
        b = Queue()
        for i in range(5):
            a.enqueue(i)
        a.dequeue()
        for i in range(1, 5):
            b.enqueue(i)
        self.assertEqual(a, b)


if __name__ == "__main__":
    unittest.main()
