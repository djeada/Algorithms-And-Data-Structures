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


if __name__ == "__main__":
    unittest.main()
