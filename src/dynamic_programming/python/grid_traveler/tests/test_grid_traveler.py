import unittest

from src.grid_traveler import (
    grid_traveller_basic,
    grid_traveller_memo,
    grid_traveller_table,
)


class TestTravelerBasic(unittest.TestCase):
    def test_with_1_and_1(self):
        m = 1
        n = 1
        result = 1
        self.assertEqual(grid_traveller_basic(m, n), result)

    def test_with_2_and_3(self):
        m = 2
        n = 3
        result = 3
        self.assertEqual(grid_traveller_basic(m, n), result)

    def test_with_3_and_3(self):
        m = 3
        n = 3
        result = 6
        self.assertEqual(grid_traveller_basic(m, n), result)

    def test_with_10_and_10(self):
        m = 10
        n = 10
        result = 48620
        self.assertEqual(grid_traveller_basic(m, n), result)


class TestTravelerMemo(unittest.TestCase):
    def test_with_1_and_1(self):
        m = 1
        n = 1
        result = 1
        self.assertEqual(grid_traveller_memo(m, n), result)

    def test_with_2_and_3(self):
        m = 2
        n = 3
        result = 3
        self.assertEqual(grid_traveller_memo(m, n), result)

    def test_with_3_and_3(self):
        m = 3
        n = 3
        result = 6
        self.assertEqual(grid_traveller_memo(m, n), result)

    def test_with_10_and_10(self):
        m = 10
        n = 10
        result = 48620
        self.assertEqual(grid_traveller_memo(m, n, dict()), result)


class TestTravelerTable(unittest.TestCase):
    def test_with_1_and_1(self):
        m = 1
        n = 1
        result = 1
        self.assertEqual(grid_traveller_table(m, n), result)

    def test_with_2_and_3(self):
        m = 2
        n = 3
        result = 3
        self.assertEqual(grid_traveller_table(m, n), result)

    def test_with_3_and_3(self):
        m = 3
        n = 3
        result = 6
        self.assertEqual(grid_traveller_table(m, n), result)

    def test_with_10_and_10(self):
        m = 10
        n = 10
        result = 48620
        self.assertEqual(grid_traveller_table(m, n), result)


if __name__ == "__main__":
    unittest.main()
