import unittest

from src.lowest_common_ancestor import lowest_common_ancestor, TreeNode


class TestLowestCommonAncestor(unittest.TestCase):
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

        expected = 4
        actual = lowest_common_ancestor(root, 3, 5)
        self.assertEqual(actual, expected)

    def test_empty_tree(self):
        root = None
        expected = None
        actual = lowest_common_ancestor(root, 3, 5)
        self.assertEqual(actual, expected)

    def test_single_node_tree(self):
        root = TreeNode(1)
        expected = 1
        actual = lowest_common_ancestor(root, 1, 1)
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

        expected = 10
        actual = lowest_common_ancestor(root, 10, 11)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
