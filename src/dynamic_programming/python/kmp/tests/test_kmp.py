import unittest


from src.kmp import search


class TestKMP(unittest.TestCase):
    def test_pattern_not_found(self):
        text = "Short text."
        pattern = "word"
        result = []
        self.assertEqual(search(text, pattern), result)

    def test_single_match(self):
        text = "The road is wide."
        pattern = "road"
        result = [4]
        self.assertEqual(search(text, pattern), result)

    def test_multiple_match(self):
        text = "One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin. "
        pattern = "or"
        result = [5, 22, 81, 106]
        self.assertEqual(search(text, pattern), result)


if __name__ == "__main__":
    unittest.main()
