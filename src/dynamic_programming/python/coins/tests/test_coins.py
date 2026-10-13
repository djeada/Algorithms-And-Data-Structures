import unittest


from src.coins import coin_change_basic, coin_change_memo, coin_change_tab


class TestCoinChangeBasic(unittest.TestCase):
    def test_with_1(self):
        coins = [1, 3, 5]
        amount = 1
        result = 1
        self.assertEqual(coin_change_basic(amount, coins), result)

    def test_with_7(self):
        coins = [1, 3, 5]
        amount = 7
        result = 3
        self.assertEqual(coin_change_basic(amount, coins), result)

    def test_with_10(self):
        coins = [1, 3, 5]
        amount = 10
        result = 2
        self.assertEqual(coin_change_basic(amount, coins), result)

    def test_with_12(self):
        coins = [1, 3, 5]
        amount = 12
        result = 4
        self.assertEqual(coin_change_basic(amount, coins), result)


class TestCoinChangeMemo(unittest.TestCase):
    def test_with_1(self):
        coins = [1, 3, 5]
        amount = 1
        result = 1
        self.assertEqual(coin_change_memo(amount, coins), result)

    def test_with_7(self):
        coins = [1, 3, 5]
        amount = 7
        result = 3
        self.assertEqual(coin_change_memo(amount, coins), result)

    def test_with_10(self):
        coins = [1, 3, 5]
        amount = 10
        result = 2
        self.assertEqual(coin_change_memo(amount, coins), result)

    def test_with_12(self):
        coins = [1, 3, 5]
        amount = 12
        result = 4
        self.assertEqual(coin_change_memo(amount, coins), result)


class TestCoinChangeTab(unittest.TestCase):
    def test_with_1(self):
        coins = [1, 3, 5]
        amount = 1
        result = 1
        self.assertEqual(coin_change_tab(amount, coins), result)

    def test_with_7(self):
        coins = [1, 3, 5]
        amount = 7
        result = 3
        self.assertEqual(coin_change_tab(amount, coins), result)

    def test_with_10(self):
        coins = [1, 3, 5]
        amount = 10
        result = 2
        self.assertEqual(coin_change_tab(amount, coins), result)

    def test_with_12(self):
        coins = [1, 3, 5]
        amount = 12
        result = 4
        self.assertEqual(coin_change_tab(amount, coins), result)


class TestCoinChangeEdgeCases(unittest.TestCase):
    FUNCS = (coin_change_basic, coin_change_memo, coin_change_tab)

    def test_negative_amount_is_impossible(self):
        for f in self.FUNCS:
            self.assertEqual(f(-5, [1, 2]), float("inf"), f.__name__)

    def test_impossible_amount(self):
        for f in self.FUNCS:
            self.assertEqual(f(3, [2]), float("inf"), f.__name__)
            self.assertEqual(f(3, []), float("inf"), f.__name__)

    def test_zero_amount(self):
        for f in self.FUNCS:
            self.assertEqual(f(0, []), 0, f.__name__)

    def test_non_positive_coins_are_ignored(self):
        for f in self.FUNCS:
            self.assertEqual(f(4, [0, -1, 2]), 2, f.__name__)

    def test_greedy_fails(self):
        for f in self.FUNCS:
            self.assertEqual(f(6, [1, 3, 4]), 2, f.__name__)


if __name__ == "__main__":
    unittest.main()
