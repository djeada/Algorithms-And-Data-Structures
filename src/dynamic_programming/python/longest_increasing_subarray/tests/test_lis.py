import unittest

from ..src.lis import lis_basic, lis_memo, lis_tab


class TestLisBasic(unittest.TestCase):
    def test_1(self):
        a = [13, 1, 15, 13, 6, 11, 10, 20, 7]
        result = 4
        self.assertEqual(lis_basic(a), result)

    def test_2(self):
        a = [0, 9, 7, 14, 6, 8]
        result = 3
        self.assertEqual(lis_basic(a), result)

    def test_3(self):
        a = [3, 10, 2, 1, 20]
        result = 3
        self.assertEqual(lis_basic(a), result)

    def test_4(self):
        a = [50, 3, 10, 7, 40, 80]
        result = 4
        self.assertEqual(lis_basic(a), result)


class TestLisMemo(unittest.TestCase):
    def test_1(self):
        a = [13, 1, 15, 13, 6, 11, 10, 20, 7]
        result = 4
        self.assertEqual(lis_memo(a), result)

    @unittest.skip("Not implemented yet")
    def test_2(self):
        a = [0, 9, 7, 14, 6, 8]
        result = 3
        self.assertEqual(lis_memo(a), result)

    @unittest.skip("Not implemented yet")
    def test_3(self):
        a = [3, 10, 2, 1, 20]
        result = 3
        self.assertEqual(lis_memo(a), result)

    def test_4(self):
        a = [50, 3, 10, 7, 40, 80]
        result = 4
        self.assertEqual(lis_memo(a), result)


class TestLisTab(unittest.TestCase):
    def test_1(self):
        a = [13, 1, 15, 13, 6, 11, 10, 20, 7]
        result = 4
        self.assertEqual(lis_tab(a), result)

    def test_2(self):
        a = [0, 9, 7, 14, 6, 8]
        result = 3
        self.assertEqual(lis_tab(a), result)

    def test_3(self):
        a = [3, 10, 2, 1, 20]
        result = 3
        self.assertEqual(lis_tab(a), result)

    def test_4(self):
        a = [50, 3, 10, 7, 40, 80]
        result = 4
        self.assertEqual(lis_tab(a), result)


if __name__ == "__main__":
    unittest.main()
