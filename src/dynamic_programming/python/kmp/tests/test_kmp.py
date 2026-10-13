import random
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


class TestKMPEdgeCases(unittest.TestCase):
    def test_fallback_needs_more_than_one_step(self):
        # After the mismatch at the final "b" the match state must fall back
        # more than once before the current character can be compared.
        self.assertEqual(search("aaabaaaab", "aaaab"), [4])

    def test_overlapping_matches(self):
        self.assertEqual(search("aaaa", "aa"), [0, 1, 2])

    def test_empty_pattern_matches_everywhere(self):
        self.assertEqual(search("abc", ""), [0, 1, 2, 3])
        self.assertEqual(search("", ""), [0])

    def test_empty_text(self):
        self.assertEqual(search("", "a"), [])

    def test_pattern_longer_than_text(self):
        self.assertEqual(search("ab", "abc"), [])

    def test_against_brute_force(self):
        rng = random.Random(1234)
        for _ in range(500):
            text = "".join(rng.choice("ab") for _ in range(rng.randint(0, 20)))
            pattern = "".join(rng.choice("ab") for _ in range(rng.randint(1, 6)))
            expected = [
                i
                for i in range(len(text) - len(pattern) + 1)
                if text.startswith(pattern, i)
            ]
            self.assertEqual(search(text, pattern), expected, (text, pattern))


if __name__ == "__main__":
    unittest.main()
