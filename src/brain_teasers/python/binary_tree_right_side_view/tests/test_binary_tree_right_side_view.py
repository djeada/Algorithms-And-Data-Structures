import unittest

from src.binary_tree_right_side_view import TreeNode, right_side_view


class TestBinaryTreeRightSideView(unittest.TestCase):
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

        expected = [8, 10, 11]
        actual = right_side_view(root)
        self.assertEqual(actual, expected)

    def test_empty_tree(self):
        root = None
        expected = []
        actual = right_side_view(root)
        self.assertEqual(actual, expected)

    def test_single_node_tree(self):
        root = TreeNode(1)
        expected = [1]
        actual = right_side_view(root)
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

        expected = [8, 10, 11]
        actual = right_side_view(root)
        self.assertEqual(actual, expected)

    def test_left_skewed_tree(self):
        # Tree:
        #     8
        #    /
        #   4
        #  /
        # 3

        root = TreeNode(8)
        root.left = TreeNode(4)
        root.left.left = TreeNode(3)

        expected = [8, 4, 3]
        actual = right_side_view(root)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
