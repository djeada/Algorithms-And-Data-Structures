import unittest

from src.range_sum_of_bst import range_sum_of_bst, TreeNode


class TestRangeSumOfBst(unittest.TestCase):
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

        expected = 27
        actual = range_sum_of_bst(root, 4, 10)
        self.assertEqual(actual, expected)

    def test_empty_tree(self):
        root = None
        expected = 0
        actual = range_sum_of_bst(root, 4, 10)
        self.assertEqual(actual, expected)

    def test_single_node_tree(self):
        root = TreeNode(1)
        expected = 0
        actual = range_sum_of_bst(root, 4, 10)
        self.assertEqual(actual, expected)

    def test_right_skewed_tree(self):
        # Tree:
        #     8
        #      \
        #       10
        #        \
        #         11

        root = TreeNode(8)
        root.right = TreeNode(10)
        root.right.right = TreeNode(11)

        expected = 29
        actual = range_sum_of_bst(root, 8, 11)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
