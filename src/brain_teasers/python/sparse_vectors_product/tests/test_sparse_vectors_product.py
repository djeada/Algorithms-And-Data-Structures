import unittest

from src.sparse_vectors_product import sparse_vectors_product


class TestSparseVectorsProduct(unittest.TestCase):
    def test_sparse_vectors_product(self):
        input_v1 = {1: 1, 2: 2, 3: 3}
        input_v2 = {1: 1, 2: 2, 3: 3}
        expected = 14
        actual = sparse_vectors_product(input_v1, input_v2)
        self.assertEqual(actual, expected)

    def test_empty_vectors(self):
        input_v1 = {}
        input_v2 = {}
        expected = 0
        actual = sparse_vectors_product(input_v1, input_v2)
        self.assertEqual(actual, expected)

    def test_one_empty_vector(self):
        input_v1 = {}
        input_v2 = {1: 1, 2: 2, 3: 3}
        expected = 0
        actual = sparse_vectors_product(input_v1, input_v2)
        self.assertEqual(actual, expected)

    def test_no_common_indices(self):
        input_v1 = {1: 1, 2: 2, 3: 3}
        input_v2 = {4: 4, 5: 5, 6: 6}
        expected = 0
        actual = sparse_vectors_product(input_v1, input_v2)
        self.assertEqual(actual, expected)


if __name__ == "__main__":
    unittest.main()
