import unittest
import sys

sys.path.insert(0, "../src")

from can_sum import can_sum_basic, can_sum_memo, can_sum_table


class TestCanSumBasic(unittest.TestCase):
    def test_negative_1(self):
        numbers = [2, 2, 4]
        target = 7
        result = False
        self.assertEqual(can_sum_basic(target, numbers), result)

    def test_negative_2(self):
        numbers = [3, 5, 9, 10]
        target = 1
        result = False
        self.assertEqual(can_sum_basic(target, numbers), result)

    def test_positive_1(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        result = True
        self.assertEqual(can_sum_basic(target, numbers), result)

    def test_positive_2(self):
        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        result = True
        self.assertEqual(can_sum_basic(target, numbers), result)


class TestCanSumMemo(unittest.TestCase):
    def test_negative_1(self):
        numbers = [2, 2, 4]
        target = 7
        result = False
        self.assertEqual(can_sum_memo(target, numbers), result)

    def test_negative_2(self):
        numbers = [3, 5, 9, 10]
        target = 1
        result = False
        self.assertEqual(can_sum_memo(target, numbers), result)

    def test_positive_1(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        result = True
        self.assertEqual(can_sum_memo(target, numbers), result)

    def test_positive_2(self):
        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        result = True
        self.assertEqual(can_sum_memo(target, numbers), result)


class TestCanSumTab(unittest.TestCase):
    def test_negative_1(self):
        numbers = [2, 2, 4]
        target = 7
        result = False
        self.assertEqual(can_sum_table(target, numbers), result)

    def test_negative_2(self):
        numbers = [3, 5, 9, 10]
        target = 1
        result = False
        self.assertEqual(can_sum_table(target, numbers), result)

    def test_positive_1(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        result = True
        self.assertEqual(can_sum_table(target, numbers), result)

    def test_positive_2(self):
        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        result = True
        self.assertEqual(can_sum_table(target, numbers), result)


if __name__ == "__main__":
    unittest.main()
