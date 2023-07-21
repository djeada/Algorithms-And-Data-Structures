from src.avl_tree import AvlTree
from unittest import TestCase
import unittest


class TestAvlTree(TestCase):
    def test_default_constructor(self):
        tree = AvlTree()
        self.assertEqual(tree.size(), 0)
        self.assertEqual(tree.height(), 0)
        self.assertTrue(tree.empty())

    def test_insert(self):
        tree = AvlTree()
        for i in range(10):
            tree.insert(i)
        self.assertEqual(tree.size(), 10)
        self.assertEqual(tree.height(), 4)
        self.assertFalse(tree.empty())

    def test_remove(self):
        tree = AvlTree()
        for i in range(10):
            tree.insert(i)
        for i in range(10):
            tree.remove(i)
        self.assertEqual(tree.size(), 0)
        self.assertEqual(tree.height(), 0)
        self.assertTrue(tree.empty())

    def test_contains(self):
        tree = AvlTree()
        for i in range(10):
            tree.insert(i)
        for i in range(10):
            self.assertTrue(tree.contains(i))
        for i in range(10, 20):
            self.assertFalse(tree.contains(i))

    def test_clear(self):
        tree = AvlTree()
        for i in range(10):
            tree.insert(i)
        tree.clear()
        self.assertEqual(tree.size(), 0)
        self.assertEqual(tree.height(), 0)
        self.assertTrue(tree.empty())

    def test_in_order_traversal(self):
        """
        Tree structure:
                5
              /   \
             3     7
            / \   / \
           2   4 6   8

        In-order traversal: 2 3 4 5 6 7 8
        """
        tree = AvlTree()
        tree.insert(5)
        tree.insert(3)
        tree.insert(7)
        tree.insert(2)
        tree.insert(4)
        tree.insert(6)
        tree.insert(8)
        expected = [2, 3, 4, 5, 6, 7, 8]
        actual = tree.in_order_traversal()
        self.assertEqual(expected, actual)

    def test_pre_order_traversal(self):
        """
        Tree structure:
                5
              /   \
             3     7
            / \   / \
           2   4 6   8

        Pre-order traversal: 5 3 2 4 7 6 8
        """
        tree = AvlTree()
        tree.insert(5)
        tree.insert(3)
        tree.insert(7)
        tree.insert(2)
        tree.insert(4)
        tree.insert(6)
        tree.insert(8)
        expected = [5, 3, 2, 4, 7, 6, 8]
        actual = tree.pre_order_traversal()
        self.assertEqual(expected, actual)

    def test_post_order_traversal(self):
        """
        Tree structure:
                5
              /   \
             3     7
            / \   / \
           2   4 6   8

        Post-order traversal: 2 4 3 6 8 7 5
        """
        tree = AvlTree()
        tree.insert(5)
        tree.insert(3)
        tree.insert(7)
        tree.insert(2)
        tree.insert(4)
        tree.insert(6)
        tree.insert(8)

        expected = [2, 4, 3, 6, 8, 7, 5]
        actual = tree.post_order_traversal()
        self.assertEqual(expected, actual)

    def test_is_tree_always_balanced(self):
        tree = AvlTree()
        for i in range(100):
            tree.insert(i)
        self.assertEqual(tree.size(), 100)
        self.assertEqual(tree.height(), 7)
        self.assertFalse(tree.empty())


if __name__ == "__main__":
    unittest.main()
