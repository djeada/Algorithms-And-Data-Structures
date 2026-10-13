import random
from src.binary_search_tree import BinarySearchTree
from unittest import TestCase
import unittest


class TestBinarySearchTree(TestCase):
    def test_default_constructor(self):
        bst = BinarySearchTree()
        self.assertEqual(bst.size(), 0)
        self.assertEqual(bst.height(), 0)
        self.assertTrue(bst.empty())

    def test_assignment_operator(self):
        bst = BinarySearchTree()
        for i in range(10):
            bst.insert(i)

        bst2 = BinarySearchTree()
        bst2 = bst
        self.assertEqual(bst2.size(), 10)
        self.assertEqual(bst2.height(), 10)

        for i in range(10):
            self.assertTrue(bst2.contains(i))

    def test_insert(self):
        bst = BinarySearchTree()
        bst.insert(0)
        self.assertEqual(bst.size(), 1)
        self.assertEqual(bst.height(), 1)
        self.assertTrue(bst.contains(0))

    def test_remove(self):
        bst = BinarySearchTree()

        # single element
        bst.insert(0)
        bst.remove(0)
        self.assertEqual(bst.size(), 0)
        self.assertEqual(bst.height(), 0)
        self.assertFalse(bst.contains(0))

        # 3 elements
        #       5
        #      / \
        #     3   8
        #
        # After removing 8:
        #       5
        #      /
        #     3
        bst.insert(5)
        bst.insert(3)
        bst.insert(8)
        bst.remove(8)

        self.assertEqual(bst.size(), 2)
        self.assertEqual(bst.height(), 2)
        self.assertFalse(bst.contains(8))
        self.assertTrue(bst.contains(5))
        self.assertTrue(bst.contains(3))

        # 4 elements
        #       5
        #      / \
        #     3   8
        #        /
        #       7
        #
        # After removing 8:
        #       5
        #      / \
        #     3   7

        bst.insert(8)
        bst.insert(7)
        bst.remove(8)

        self.assertEqual(bst.size(), 3)
        self.assertEqual(bst.height(), 2)
        self.assertFalse(bst.contains(8))
        self.assertTrue(bst.contains(5))
        self.assertTrue(bst.contains(3))
        self.assertTrue(bst.contains(7))

    def test_contains(self):
        bst = BinarySearchTree()
        bst.insert(0)
        self.assertTrue(bst.contains(0))
        self.assertFalse(bst.contains(1))

    def test_clear(self):
        bst = BinarySearchTree()
        for i in range(10):
            bst.insert(i)
        bst.clear()
        self.assertEqual(bst.size(), 0)
        self.assertEqual(bst.height(), 0)
        self.assertTrue(bst.empty())

    def test_height(self):
        bst = BinarySearchTree()
        for i in range(10):
            bst.insert(i)
        self.assertEqual(bst.height(), 10)

    def test_size(self):
        bst = BinarySearchTree()
        for i in range(10):
            bst.insert(i)
        self.assertEqual(bst.size(), 10)

    def test_empty(self):
        bst = BinarySearchTree()
        self.assertTrue(bst.empty())
        bst.insert(0)
        self.assertFalse(bst.empty())

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
        bst = BinarySearchTree()
        bst.insert(5)
        bst.insert(3)
        bst.insert(7)
        bst.insert(2)
        bst.insert(4)
        bst.insert(6)
        bst.insert(8)

        expected = [2, 3, 4, 5, 6, 7, 8]
        actual = bst.in_order_traversal()

        self.assertEqual(actual, expected)

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
        bst = BinarySearchTree()
        bst.insert(5)
        bst.insert(3)
        bst.insert(7)
        bst.insert(2)
        bst.insert(4)
        bst.insert(6)
        bst.insert(8)

        expected = [5, 3, 2, 4, 7, 6, 8]
        actual = bst.pre_order_traversal()

        self.assertEqual(actual, expected)

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
        bst = BinarySearchTree()
        bst.insert(5)
        bst.insert(3)
        bst.insert(7)
        bst.insert(2)
        bst.insert(4)
        bst.insert(6)
        bst.insert(8)

        expected = [2, 4, 3, 6, 8, 7, 5]
        actual = bst.post_order_traversal()

        self.assertEqual(actual, expected)


class TestBinarySearchTreeRemoval(TestCase):
    def test_remove_root_with_only_right_child(self):
        bst = BinarySearchTree()
        bst.insert(1)
        bst.insert(2)
        bst.insert(3)
        bst.remove(1)
        self.assertEqual(bst.in_order_traversal(), [2, 3])
        self.assertFalse(bst.contains(1))
        self.assertEqual(bst.size(), 2)

    def test_remove_root_with_only_left_child(self):
        bst = BinarySearchTree()
        bst.insert(3)
        bst.insert(2)
        bst.insert(1)
        bst.remove(3)
        self.assertEqual(bst.in_order_traversal(), [1, 2])
        self.assertEqual(bst.size(), 2)

    def test_remove_from_empty_or_missing_value_is_noop(self):
        bst = BinarySearchTree()
        bst.remove(1)
        self.assertEqual(bst.size(), 0)
        bst.insert(5)
        bst.remove(7)
        self.assertEqual(bst.size(), 1)
        self.assertEqual(bst.in_order_traversal(), [5])

    def test_random_operations_match_set(self):
        rng = random.Random(1)
        for _ in range(30):
            bst = BinarySearchTree()
            ref = set()
            for _ in range(200):
                v = rng.randrange(60)
                if rng.random() < 0.5:
                    if v not in ref:
                        bst.insert(v)
                        ref.add(v)
                else:
                    bst.remove(v)
                    ref.discard(v)
                self.assertEqual(bst.in_order_traversal(), sorted(ref))
                self.assertEqual(bst.size(), len(ref))


if __name__ == "__main__":
    unittest.main()
