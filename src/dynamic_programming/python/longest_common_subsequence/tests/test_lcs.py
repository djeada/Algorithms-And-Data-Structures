import unittest


from src.lcs import lcs_basic, lcs_memo, lcs_tab


class TestLCSBasic(unittest.TestCase):
    def test_1(self):
        a = "ABCBDAB"
        b = "BDCABA"
        result = 4
        self.assertEqual(lcs_basic(a, b), result)

    def test_2(self):
        a = "TUPAKSHAKUR"
        b = "SHAKURTUPAK"
        result = 6
        self.assertEqual(lcs_basic(a, b), result)

    def test_3(self):
        a = "FOOBAR"
        b = "BARFOO"
        result = 3
        self.assertEqual(lcs_basic(a, b), result)

    def test_4(self):
        a = "FOOBAR"
        b = "BARFOOFOO"
        result = 3
        self.assertEqual(lcs_basic(a, b), result)

    def test_5(self):
        a = "FOOBAR"
        b = "FOOBAR"
        result = 6
        self.assertEqual(lcs_basic(a, b), result)


class TestLCSMemo(unittest.TestCase):
    def test_1(self):
        a = "ABCBDAB"
        b = "BDCABA"
        result = 4
        self.assertEqual(lcs_memo(a, b), result)

    def test_2(self):
        a = "TUPAKSHAKUR"
        b = "SHAKURTUPAK"
        result = 6
        self.assertEqual(lcs_memo(a, b), result)

    def test_3(self):
        a = "FOOBAR"
        b = "BARFOO"
        result = 3
        self.assertEqual(lcs_memo(a, b), result)

    def test_4(self):
        a = "FOOBAR"
        b = "BARFOOFOO"
        result = 3
        self.assertEqual(lcs_memo(a, b), result)

    def test_5(self):
        a = "FOOBAR"
        b = "FOOBAR"
        result = 6
        self.assertEqual(lcs_memo(a, b), result)


class TestLCSTab(unittest.TestCase):
    def test_1(self):
        a = "ABCBDAB"
        b = "BDCABA"
        result = 4
        self.assertEqual(lcs_tab(a, b), result)

    def test_2(self):
        a = "TUPAKSHAKUR"
        b = "SHAKURTUPAK"
        result = 6
        self.assertEqual(lcs_tab(a, b), result)

    def test_3(self):
        a = "FOOBAR"
        b = "BARFOO"
        result = 3
        self.assertEqual(lcs_tab(a, b), result)

    def test_4(self):
        a = "FOOBAR"
        b = "BARFOOFOO"
        result = 3
        self.assertEqual(lcs_tab(a, b), result)

    def test_5(self):
        a = "FOOBAR"
        b = "FOOBAR"
        result = 6
        self.assertEqual(lcs_tab(a, b), result)


if __name__ == "__main__":
    unittest.main()
