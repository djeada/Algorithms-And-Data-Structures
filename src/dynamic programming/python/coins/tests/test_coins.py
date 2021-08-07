import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from coins import coin_change_basic, coin_change_memo, coin_change_tab


class TestCoinChangeBasic(unittest.TestCase):
    def test_negative(self):
        num = 0
        coins = [3, 2, 1]
        result = 0
        self.assertEqual(coin_change_basic(num, coins), result)

    def test_positivie(self):
        num = 25
        coins = [5, 10]
        result = 3
        self.assertEqual(coin_change_basic(num, coins), result)


class TestCoinChangeMemo(unittest.TestCase):
    def test_negative(self):
        num = 0
        coins = [3, 2, 1]
        result = 0
        self.assertEqual(coin_change_memo(num, coins), result)

    def test_positivie(self):
        num = 67
        coins = [1, 5, 10, 25]
        result = 6
        self.assertEqual(coin_change_memo(num, coins), result)


class TestCoinChangeTab(unittest.TestCase):
    def test_negative(self):
        num = 0
        coins = [3, 2, 1]
        result = 0
        self.assertEqual(coin_change_tab(num, coins), result)

    def test_positivie(self):
        num = 67
        coins = [1, 5, 10, 25]
        result = 6
        self.assertEqual(coin_change_tab(num, coins), result)


if __name__ == "__main__":
    unittest.main()
