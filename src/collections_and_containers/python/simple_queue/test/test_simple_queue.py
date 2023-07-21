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


if __name__ == "__main__":
    unittest.main()
