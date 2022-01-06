import unittest

import os
import sys

file_dir = os.path.dirname(os.path.dirname(__file__))
sys.path.append(file_dir + "/src")

from climb import climb_basic, climb_memo


class TestClimbBasic(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 1
        self.assertEqual(climb_basic(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(climb_basic(num), result)

    def test_with_2(self):
        num = 2
        result = 2
        self.assertEqual(climb_basic(num), result)

    def test_with_10(self):
        num = 10
        result = 274
        self.assertEqual(climb_basic(num), result)

    def test_with_20(self):
        num = 20
        result = 121415
        self.assertEqual(climb_basic(num), result)


class TestClimbMemo(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 1
        self.assertEqual(climb_memo(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(climb_memo(num), result)

    def test_with_2(self):
        num = 2
        result = 2
        self.assertEqual(climb_memo(num), result)

    def test_with_10(self):
        num = 10
        result = 274
        self.assertEqual(climb_memo(num), result)

    def test_with_20(self):
        num = 20
        result = 121415
        self.assertEqual(climb_memo(num), result)


if __name__ == "__main__":
    unittest.main()
