import random
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


class TestBestSumEdgeCases(unittest.TestCase):
    FUNCS = (
        find_shortest_combination_sum_basic,
        find_shortest_combination_sum_memo,
        find_shortest_combination_sum_table,
    )

    def test_negative_target(self):
        for f in self.FUNCS:
            self.assertIsNone(f(-4, [1, 2]), f.__name__)

    def test_zero_target(self):
        for f in self.FUNCS:
            self.assertEqual(f(0, [1]), [], f.__name__)

    def test_non_positive_numbers_are_ignored(self):
        for f in self.FUNCS:
            self.assertIsNone(f(5, [0, -1]), f.__name__)
            self.assertEqual(f(5, [0, 5, 1]), [5], f.__name__)

    def test_against_brute_force(self):
        rng = random.Random(21)
        for _ in range(150):
            target = rng.randint(0, 20)
            numbers = [rng.randint(1, 8) for _ in range(rng.randint(0, 4))]
            best = [0] + [None] * target
            for t in range(1, target + 1):
                options = [
                    best[t - n] + 1
                    for n in numbers
                    if n <= t and best[t - n] is not None
                ]
                best[t] = min(options) if options else None
            for f in self.FUNCS:
                result = f(target, numbers)
                if best[target] is None:
                    self.assertIsNone(result, (f.__name__, target, numbers))
                else:
                    self.assertEqual(
                        len(result), best[target], (f.__name__, target, numbers)
                    )
                    self.assertEqual(sum(result), target)


if __name__ == "__main__":
    unittest.main()
