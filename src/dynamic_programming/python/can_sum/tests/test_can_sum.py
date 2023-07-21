import unittest


from src.can_sum import can_sum_basic, can_sum_memo, can_sum_table


class TestCanSumBasic(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_basic(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_basic(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_basic(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_basic(target, numbers))


class TestCanSumMemo(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_memo(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_memo(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_memo(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_memo(target, numbers))


class TestCanSumTab(unittest.TestCase):
    def test_negative(self):
        numbers = [2, 2, 4]
        target = 7
        self.assertFalse(can_sum_table(target, numbers))

        numbers = [3, 5, 9, 10]
        target = 1
        self.assertFalse(can_sum_table(target, numbers))

    def test_positive(self):
        numbers = [3, 3, 8, 9, 11]
        target = 20
        self.assertTrue(can_sum_table(target, numbers))

        numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        target = 25
        self.assertTrue(can_sum_table(target, numbers))


if __name__ == "__main__":
    unittest.main()
