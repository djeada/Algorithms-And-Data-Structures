import unittest

from ..src.climb import (
    count_ways_to_climb_basic,
    count_ways_to_climb_memo,
    count_ways_to_climb_table,
)


class TestClimbBasic(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 1
        self.assertEqual(count_ways_to_climb_basic(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(count_ways_to_climb_basic(num), result)

    def test_with_2(self):
        num = 2
        result = 2
        self.assertEqual(count_ways_to_climb_basic(num), result)

    def test_with_10(self):
        num = 10
        result = 274
        self.assertEqual(count_ways_to_climb_basic(num), result)

    def test_with_20(self):
        num = 20
        result = 121415
        self.assertEqual(count_ways_to_climb_basic(num), result)


class TestClimbMemo(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 1
        self.assertEqual(count_ways_to_climb_memo(num), result)

    def test_with_1(self):
        num = 1
        result = 1
        self.assertEqual(count_ways_to_climb_memo(num), result)

    def test_with_2(self):
        num = 2
        result = 2
        self.assertEqual(count_ways_to_climb_memo(num), result)

    def test_with_10(self):
        num = 10
        result = 274
        self.assertEqual(count_ways_to_climb_memo(num), result)

    def test_with_20(self):
        num = 20
        result = 121415
        self.assertEqual(count_ways_to_climb_memo(num), result)


class TestClimbTable(unittest.TestCase):
    def test_with_0(self):
        num = 0
        result = 1
        self.assertEqual(count_ways_to_climb_table(num), result)

    def test_with_1(self):
        num = 1
        result = 2
        self.assertEqual(count_ways_to_climb_table(num), result)

    def test_with_2(self):
        num = 2
        result = 2
        self.assertEqual(count_ways_to_climb_table(num), result)

    def test_with_10(self):
        num = 10
        result = 274
        self.assertEqual(count_ways_to_climb_table(num), result)

    def test_with_20(self):
        num = 20
        result = 121415
        self.assertEqual(count_ways_to_climb_table(num), result)


if __name__ == "__main__":
    unittest.main()
