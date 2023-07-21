import unittest


from src.how_sum import how_sum_basic, how_sum_memo, how_sum_table


class TestHowSumBasic(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_basic(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_basic(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))


class TestHowSumMemo(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_memo(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_memo(target, numbers, {})

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_memo(target, numbers, {})

        self.assertTrue(any([result == elem for elem in expected]))


class TestHowSumTab(unittest.TestCase):
    def test_negative_1(self):
        target = 5
        numbers = [10, 15, 20]

        self.assertIsNone(how_sum_table(target, numbers))

    def test_negative_2(self):
        target = 10
        numbers = [3, 6, 8, 9]

        self.assertIsNone(how_sum_table(target, numbers))

    def test_positive_1(self):
        target = 8
        numbers = [2, 2, 4, 5]
        expected = [[4, 2, 2], [2, 4, 2], [2, 2, 4], [2, 2, 2, 2], [4, 4]]
        result = how_sum_table(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))

    def test_positive_2(self):
        target = 9
        numbers = [3, 8, 6]
        expected = [[3, 3, 3], [3, 9]]
        result = how_sum_table(target, numbers)

        self.assertTrue(any([result == elem for elem in expected]))


if __name__ == "__main__":
    unittest.main()
