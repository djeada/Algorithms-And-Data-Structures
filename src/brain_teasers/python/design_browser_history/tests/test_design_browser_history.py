import unittest

from src.design_browser_history import BrowserHistory


class TestDesignBrowserHistory(unittest.TestCase):
    def test_1(self):
        browser_history = BrowserHistory("leetcode.com")
        browser_history.visit("google.com")
        browser_history.visit("facebook.com")
        browser_history.visit("youtube.com")
        self.assertEqual(browser_history.back(1), "facebook.com")
        self.assertEqual(browser_history.back(1), "google.com")
        self.assertEqual(browser_history.forward(1), "facebook.com")
        browser_history.visit("linkedin.com")
        self.assertEqual(browser_history.forward(2), "linkedin.com")
        self.assertEqual(browser_history.back(2), "google.com")
        self.assertEqual(browser_history.back(7), "leetcode.com")

    def test_2(self):
        browser_history = BrowserHistory("zav.com")
        browser_history.visit("kni.com")
        self.assertEqual(browser_history.back(10), "zav.com")
        self.assertEqual(browser_history.forward(10), "kni.com")

    def test_3(self):
        browser_history = BrowserHistory("a.com")
        browser_history.visit("b.com")
        browser_history.visit("c.com")
        browser_history.visit("d.com")
        browser_history.visit("e.com")
        browser_history.visit("f.com")
        self.assertEqual(browser_history.forward(1), "f.com")
        self.assertEqual(browser_history.back(1), "e.com")
        self.assertEqual(browser_history.back(1), "d.com")


if __name__ == "__main__":
    unittest.main()
