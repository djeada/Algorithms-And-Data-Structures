import unittest

from src.bst_to_list import bst_to_double_linked_list, TreeNode


class TestBstToList(unittest.TestCase):
    def test_full_tree(self):
        # Tree:
        #     8
        #    / \
        #   4   10
        #  / \   \
        # 3   5   11

        root = TreeNode(8)
        root.left = TreeNode(4)
        root.right = TreeNode(10)
        root.left.left = TreeNode(3)
        root.left.right = TreeNode(5)
        root.right.right = TreeNode(11)

        expected = [3, 4, 5, 8, 10, 11]
        actual = bst_to_double_linked_list(root)
        self.assertEqual(list(actual), expected)

    def test_empty_tree(self):
        root = None
        expected = []
        actual = bst_to_double_linked_list(root)
        self.assertEqual(list(actual), expected)

    def test_single_node_tree(self):
        root = TreeNode(1)
        expected = [1]
        actual = bst_to_double_linked_list(root)
        self.assertEqual(list(actual), expected)

    def test_result_is_ascending_and_doubly_linked(self):
        root = TreeNode(2)
        root.left = TreeNode(1)
        root.right = TreeNode(3)
        result = bst_to_double_linked_list(root)
        self.assertEqual(result.to_list(), [1, 2, 3])
        self.assertEqual(result.head.value, 1)
        self.assertEqual(result.tail.value, 3)
        self.assertEqual(result.tail.prev.value, 2)
        self.assertEqual(result.head.next.prev.value, 1)


if __name__ == "__main__":
    unittest.main()
