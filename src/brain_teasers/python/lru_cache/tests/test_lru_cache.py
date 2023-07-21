import unittest

from src.lru_cache import LRUCache


class TestLRUCache(unittest.TestCase):
    def test_1(self):
        input_capacity = 2
        lrucache = LRUCache(input_capacity)
        lrucache.put(1, 1)
        lrucache.put(2, 2)
        self.assertEqual(lrucache.get(1), 1)
        lrucache.put(3, 3)
        self.assertEqual(lrucache.get(2), -1)

    def test_2(self):
        input_capacity = 2
        lrucache = LRUCache(input_capacity)
        lrucache.put(2, 1)
        lrucache.put(2, 2)
        self.assertEqual(lrucache.get(2), 2)
        lrucache.put(1, 1)
        lrucache.put(4, 1)
        self.assertEqual(lrucache.get(2), -1)


if __name__ == "__main__":
    unittest.main()
