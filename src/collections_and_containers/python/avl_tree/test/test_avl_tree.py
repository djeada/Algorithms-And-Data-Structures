import random
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
        r"""
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
        r"""
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
        r"""
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


class TestAvlTreeInvariants(TestCase):
    def _check(self, node):
        """Return the height of node, asserting AVL and cached balance factors."""
        if node is None:
            return 0
        left = self._check(node.left)
        right = self._check(node.right)
        self.assertLessEqual(abs(left - right), 1)
        return 1 + max(left, right)

    def test_remove_two_children_removes_exactly_one_value(self):
        tree = AvlTree()
        for v in [5, 3, 8, 1, 4, 7, 9]:
            tree.insert(v)
        tree.remove(5)
        self.assertEqual(tree.in_order_traversal(), [1, 3, 4, 7, 8, 9])
        self.assertEqual(tree.size(), 6)
        self.assertFalse(tree.contains(5))

    def test_remove_missing_value_is_noop(self):
        tree = AvlTree()
        tree.insert(1)
        tree.remove(2)
        self.assertEqual(tree.size(), 1)
        self.assertEqual(tree.in_order_traversal(), [1])

    def test_balanced_after_sequential_operations(self):
        tree = AvlTree()
        for i in range(200):
            tree.insert(i)
            self._check(tree.root)
        for i in range(0, 200, 3):
            tree.remove(i)
            self._check(tree.root)
        self.assertEqual(tree.in_order_traversal(), [i for i in range(200) if i % 3])

    def test_random_operations_stay_balanced(self):
        rng = random.Random(7)
        for _ in range(20):
            tree = AvlTree()
            ref = set()
            for _ in range(200):
                v = rng.randrange(60)
                if rng.random() < 0.5:
                    if v not in ref:
                        tree.insert(v)
                        ref.add(v)
                else:
                    tree.remove(v)
                    ref.discard(v)
                self._check(tree.root)
                self.assertEqual(tree.size(), len(ref))
                self.assertEqual(tree.in_order_traversal(), sorted(ref))


if __name__ == "__main__":
    unittest.main()
