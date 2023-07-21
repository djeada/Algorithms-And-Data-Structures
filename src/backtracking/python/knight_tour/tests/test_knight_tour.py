from src.knight_tour import knight_tour
import unittest


class TestKnightTour(unittest.TestCase):
    def test_1(self):
        n = 1
        expected = [[[1]]]
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_2(self):
        n = 2
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_3(self):
        n = 3
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_4(self):
        n = 4
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_5(self):
        n = 5
        expected_element = [
            [1, 14, 19, 8, 25],
            [6, 9, 2, 13, 18],
            [15, 20, 7, 24, 3],
            [10, 5, 22, 17, 12],
            [21, 16, 11, 4, 23],
        ]
        excepted_length = 304
        actual = knight_tour(n)

        self.assertTrue(expected_element in actual)
        self.assertEqual(len(actual), excepted_length)


if __name__ == "__main__":
    unittest.main()
