import unittest
import sys

sys.path.insert(0, "../src")

from best_sum import best_sum_basic, best_sum_memo, best_sum_table


class TestBesSumBasic(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = None
        self.assertEqual(best_sum_basic(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = None
        self.assertEqual(best_sum_basic(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [4, 4]
        self.assertEqual(best_sum_basic(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(sorted(best_sum_basic(target, numbers)), sorted(result))


class TestBestSumMemo(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = None
        self.assertEqual(best_sum_memo(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = None
        self.assertEqual(best_sum_memo(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [4, 4]
        self.assertEqual(best_sum_memo(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(sorted(best_sum_memo(target, numbers)), sorted(result))


class TestBestSumTab(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]
        result = None
        self.assertEqual(best_sum_table(target, numbers), result)

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]
        result = None
        self.assertEqual(best_sum_table(target, numbers), result)

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        result = [4, 4]
        self.assertEqual(best_sum_table(target, numbers), result)

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        result = [3, 6]
        self.assertEqual(sorted(best_sum_table(target, numbers)), sorted(result))


if __name__ == "__main__":
    unittest.main()
