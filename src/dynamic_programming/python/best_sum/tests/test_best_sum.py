import unittest

from src.best_sum import (
    find_shortest_combination_sum_basic,
    find_shortest_combination_sum_memo,
    find_shortest_combination_sum_table,
)


class TestFindShortestCombinationSum(unittest.TestCase):
    def test_negative_target(self):
        numbers = [10, 15, 20]
        target = -1
        result = find_shortest_combination_sum_basic(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible(self):
        numbers = [10, 15, 20]
        target = 5
        result = find_shortest_combination_sum_basic(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible_2(self):
        numbers = [3, 6, 8, 9]
        target = 10
        result = find_shortest_combination_sum_basic(target, numbers)
        self.assertEqual(result, None)

    def test_single_combination_possible(self):
        numbers = [2, 2, 4, 5]
        target = 8
        result = find_shortest_combination_sum_basic(target, numbers)
        self.assertCountEqual(result, [4, 4])

    def test_multiple_combinations_possible(self):
        numbers = [3, 8, 6]
        target = 9
        result = find_shortest_combination_sum_basic(target, numbers)
        self.assertCountEqual(result, [3, 6])


class TestBestSumMemo(unittest.TestCase):
    def test_negative_target(self):
        numbers = [10, 15, 20]
        target = -1
        result = find_shortest_combination_sum_memo(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible(self):
        numbers = [10, 15, 20]
        target = 5
        result = find_shortest_combination_sum_memo(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible_2(self):
        numbers = [3, 6, 8, 9]
        target = 10
        result = find_shortest_combination_sum_memo(target, numbers)
        self.assertEqual(result, None)

    def test_single_combination_possible(self):
        numbers = [2, 2, 4, 5]
        target = 8
        result = find_shortest_combination_sum_memo(target, numbers)
        self.assertCountEqual(result, [4, 4])

    def test_multiple_combinations_possible(self):
        numbers = [3, 8, 6]
        target = 9
        result = find_shortest_combination_sum_memo(target, numbers)
        self.assertCountEqual(result, [3, 6])


class TestBestSumTab(unittest.TestCase):
    def test_negative_target(self):
        numbers = [10, 15, 20]
        target = -1
        result = find_shortest_combination_sum_table(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible(self):
        numbers = [10, 15, 20]
        target = 5
        result = find_shortest_combination_sum_table(target, numbers)
        self.assertEqual(result, None)

    def test_no_combination_possible_2(self):
        numbers = [3, 6, 8, 9]
        target = 10
        result = find_shortest_combination_sum_table(target, numbers)
        self.assertEqual(result, None)

    def test_single_combination_possible(self):
        numbers = [2, 2, 4, 5]
        target = 8
        result = find_shortest_combination_sum_table(target, numbers)
        self.assertCountEqual(result, [4, 4])

    def test_multiple_combinations_possible(self):
        numbers = [3, 8, 6]
        target = 9
        result = find_shortest_combination_sum_table(target, numbers)
        self.assertCountEqual(result, [3, 6])


if __name__ == "__main__":
    unittest.main()
