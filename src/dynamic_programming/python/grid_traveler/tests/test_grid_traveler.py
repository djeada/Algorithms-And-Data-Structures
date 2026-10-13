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


class TestGridTravelerEdgeCases(unittest.TestCase):
    FUNCS = (grid_traveller_basic, grid_traveller_memo, grid_traveller_table)

    def test_non_positive_dimensions(self):
        for f in self.FUNCS:
            self.assertEqual(f(-1, 3), 0, f.__name__)
            self.assertEqual(f(3, -2), 0, f.__name__)
            self.assertEqual(f(0, 3), 0, f.__name__)
            self.assertEqual(f(-1, -1), 0, f.__name__)

    def test_single_row_or_column(self):
        for f in self.FUNCS:
            self.assertEqual(f(1, 9), 1, f.__name__)
            self.assertEqual(f(9, 1), 1, f.__name__)

    def test_large_grid_does_not_overflow(self):
        self.assertEqual(grid_traveller_memo(18, 18), 2333606220)
        self.assertEqual(grid_traveller_table(18, 18), 2333606220)


if __name__ == "__main__":
    unittest.main()
