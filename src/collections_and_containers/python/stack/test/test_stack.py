from src.stack import Stack
from unittest import TestCase
import unittest


class TestStack(TestCase):
    def test_empty_stack(self):
        stack = Stack()
        self.assertTrue(stack.empty())

    def test_adding_multiple_elements(self):
        stack = Stack()
        stack.push(1)
        stack.push(2)
        stack.push(3)
        self.assertEqual(stack.size(), 3)

        self.assertEqual(stack.pop(), 3)
        self.assertEqual(stack.pop(), 2)
        self.assertEqual(stack.pop(), 1)

        self.assertTrue(stack.empty())

        # adding the same elements in different order
        stack.push(3)
        stack.push(1)
        stack.push(2)

        self.assertEqual(stack.pop(), 2)
        self.assertEqual(stack.pop(), 1)
        self.assertEqual(stack.pop(), 3)

    def test_top(self):
        stack = Stack()
        stack.push(1)
        stack.push(2)
        stack.push(3)

        self.assertEqual(stack.top(), 3)

    def test_top_when_empty(self):
        stack = Stack()
        self.assertRaises(IndexError, stack.top)

    def test_pop_when_empty(self):
        stack = Stack()
        self.assertRaises(IndexError, stack.pop)

    def test_push_when_full(self):
        stack = Stack(2)
        stack.push(1)
        stack.push(2)
        self.assertRaises(IndexError, stack.push, 3)


if __name__ == "__main__":
    unittest.main()
