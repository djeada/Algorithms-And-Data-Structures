import unittest

import os
import sys
file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from fib import fib_basic, fib_memo, fib_tab


class TestFibBasic(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 0
        self.assertEqual(fib_basic(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(fib_basic(num), result)

    def test_with_2(self):
        num = 2
        result = 1
        self.assertEqual(fib_basic(num), result)

    def test_with_10(self):
        num = 10
        result = 55
        self.assertEqual(fib_basic(num), result)

    def test_with_20(self):
        num = 20
        result = 6765
        self.assertEqual(fib_basic(num), result)


class TestFibMemo(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 0
        self.assertEqual(fib_memo(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(fib_memo(num), result)

    def test_with_2(self):
        num = 2
        result = 1
        self.assertEqual(fib_memo(num), result)

    def test_with_10(self):
        num = 10
        result = 55
        self.assertEqual(fib_memo(num), result)

    def test_with_20(self):
        num = 20
        result = 6765
        self.assertEqual(fib_memo(num), result)


class TestFibTab(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 0
        self.assertEqual(fib_tab(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(fib_tab(num), result)

    def test_with_2(self):
        num = 2
        result = 1
        self.assertEqual(fib_tab(num), result)

    def test_with_10(self):
        num = 10
        result = 55
        self.assertEqual(fib_tab(num), result)

    def test_with_20(self):
        num = 20
        result = 6765
        self.assertEqual(fib_tab(num), result)


if __name__ == "__main__":
    unittest.main()
