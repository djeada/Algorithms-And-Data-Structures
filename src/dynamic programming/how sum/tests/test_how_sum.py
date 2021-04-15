import unittest
import sys

sys.path.insert(0, "../src")

from how_sum import how_sum_basic, how_sum_memo, how_sum_table


class TestHowSumBasic(unittest.TestCase):
   def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = []
        self.assertEqual(how_sum_basic(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = []
        self.assertEqual(how_sum_basic(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [2, 2, 4]
        self.assertEqual(how_sum_basic(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(how_sum_basic(target, numbers), result)


class TestHowSumMemo(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = []
        self.assertEqual(how_sum_memo(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = []
        self.assertEqual(how_sum_memo(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [2, 2, 4]
        self.assertEqual(how_sum_memo(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(how_sum_memo(target, numbers), result)


class TestHowSumTab(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = []
        self.assertEqual(how_sum_table(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = []
        self.assertEqual(how_sum_table(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [2, 2, 4]
        self.assertEqual(how_sum_table(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(how_sum_table(target, numbers), result)


if __name__ == "__main__":
    unittest.main()
