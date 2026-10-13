import random
import unittest


from src.how_sum import how_sum_basic, how_sum_memo, how_sum_table


class TestHowSumBasic(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_basic(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_basic(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))


class TestHowSumMemo(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_memo(target, numbers, {})

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_memo(target, numbers, {})

        self.assertTrue(any([result == elem for elem in expected]))


class TestHowSumTab(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_table(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_table(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_table(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_table(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))


class TestHowSumEdgeCases(unittest.TestCase):
    FUNCS = (how_sum_basic, how_sum_memo, how_sum_table)

    def test_negative_target(self):
        for f in self.FUNCS:
            self.assertIsNone(f(-1, [1, 2]), f.__name__)

    def test_zero_target(self):
        for f in self.FUNCS:
            self.assertEqual(f(0, []), [], f.__name__)

    def test_non_positive_numbers_are_ignored(self):
        for f in self.FUNCS:
            self.assertIsNone(f(5, [0, -1]), f.__name__)
            self.assertEqual(sum(f(5, [0, 5])), 5, f.__name__)

    def test_against_brute_force(self):
        rng = random.Random(11)
        for _ in range(200):
            target = rng.randint(0, 20)
            numbers = [rng.randint(1, 8) for _ in range(rng.randint(0, 4))]
            reachable = [True] + [False] * target
            for t in range(1, target + 1):
                reachable[t] = any(n <= t and reachable[t - n] for n in numbers)
            for f in self.FUNCS:
                result = f(target, numbers)
                if reachable[target]:
                    self.assertEqual(sum(result), target, (f.__name__, target, numbers))
                    self.assertTrue(all(n in numbers for n in result))
                else:
                    self.assertIsNone(result, (f.__name__, target, numbers))


if __name__ == "__main__":
    unittest.main()
