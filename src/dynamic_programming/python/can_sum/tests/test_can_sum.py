import random
import unittest


from src.can_sum import can_sum_basic, can_sum_memo, can_sum_table


class TestCanSumBasic(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_basic(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_basic(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_basic(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_basic(target, numbers))


class TestCanSumMemo(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_memo(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_memo(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_memo(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_memo(target, numbers))


class TestCanSumTab(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_table(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_table(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_table(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_table(target, numbers))


class TestCanSumEdgeCases(unittest.TestCase):
    FUNCS = (can_sum_basic, can_sum_memo, can_sum_table)

    def test_negative_target(self):
        for f in self.FUNCS:
            self.assertFalse(f(-3, [1, 2]), f.__name__)

    def test_zero_target_and_empty_numbers(self):
        for f in self.FUNCS:
            self.assertTrue(f(0, []), f.__name__)
            self.assertFalse(f(5, []), f.__name__)

    def test_non_positive_numbers_are_ignored(self):
        for f in self.FUNCS:
            self.assertFalse(f(7, [0, -2]), f.__name__)
            self.assertTrue(f(7, [0, -1, 7]), f.__name__)

    def test_against_brute_force(self):
        rng = random.Random(7)
        for _ in range(200):
            target = rng.randint(0, 25)
            numbers = [rng.randint(1, 9) for _ in range(rng.randint(0, 4))]
            reachable = [True] + [False] * target
            for t in range(1, target + 1):
                reachable[t] = any(n <= t and reachable[t - n] for n in numbers)
            for f in self.FUNCS:
                self.assertEqual(
                    f(target, numbers), reachable[target], (target, numbers)
                )


if __name__ == "__main__":
    unittest.main()
