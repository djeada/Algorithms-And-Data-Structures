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

        expected = [11, 10, 8, 5, 4, 3]
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


if __name__ == "__main__":
    unittest.main()
