from src.hash_table import HashTable
from unittest import TestCase
import unittest


class TestHashTable(TestCase):
    def test_add(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        self.assertEqual(hash_table.size(), 3)

    def test_contains(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        self.assertTrue(hash_table.contains(1))
        self.assertTrue(hash_table.contains(2))
        self.assertTrue(hash_table.contains(3))
        self.assertFalse(hash_table.contains(4))

    def test_remove(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        hash_table.remove(1)
        self.assertEqual(hash_table.size(), 2)
        hash_table.remove(2)
        self.assertEqual(hash_table.size(), 1)
        hash_table.remove(3)
        self.assertEqual(hash_table.size(), 0)

    def test_remove_exception(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        self.assertRaises(Exception, hash_table.remove, 4)

    def test_access_operator(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        self.assertEqual(hash_table[1], 1)
        self.assertEqual(hash_table[2], 4)
        self.assertEqual(hash_table[3], 9)

        hash_table[1] = 2
        hash_table[2] = 5
        hash_table[3] = 10

        self.assertEqual(hash_table[1], 2)
        self.assertEqual(hash_table[2], 5)
        self.assertEqual(hash_table[3], 10)

    def test_access_operator_exception(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        self.assertRaises(Exception, lambda: hash_table[4])

    def test_clear(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        hash_table.add(2, 4)
        hash_table.add(3, 9)
        hash_table.clear()
        self.assertEqual(hash_table.size(), 0)

    def test_string_key(self):
        hash_table = HashTable(lambda key: sum(ord(c) for c in key))
        hash_table.add("a", 1)
        hash_table.add("b", 4)
        hash_table.add("c", 9)
        self.assertEqual(hash_table["a"], 1)
        self.assertEqual(hash_table["b"], 4)
        self.assertEqual(hash_table["c"], 9)

        hash_table["a"] = 2
        hash_table["b"] = 5
        hash_table["c"] = 10

        self.assertEqual(hash_table["a"], 2)
        self.assertEqual(hash_table["b"], 5)
        self.assertEqual(hash_table["c"], 10)


class TestHashTableRegressions(TestCase):
    def test_contains_missing_key_in_occupied_bucket(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        # 11 % 10 == 1: same bucket as key 1, but absent.
        self.assertFalse(hash_table.contains(11))
        self.assertRaises(KeyError, lambda: hash_table[11])

    def test_remove_missing_key_in_occupied_bucket(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, 1)
        self.assertRaises(KeyError, hash_table.remove, 11)
        self.assertEqual(hash_table.size(), 1)

    def test_none_value_is_stored(self):
        hash_table = HashTable(lambda key: key)
        hash_table.add(1, None)
        self.assertTrue(hash_table.contains(1))

    def test_grow_and_shrink_down_to_empty(self):
        hash_table = HashTable(lambda key: key * 7 - 100)
        for i in range(500):
            hash_table.add(i, i)
        for i in range(500):
            self.assertEqual(hash_table[i], i)
        for i in range(500):
            hash_table.remove(i)
        self.assertEqual(hash_table.size(), 0)
        hash_table.add(3, 3)
        self.assertEqual(hash_table[3], 3)

    def test_tiny_table(self):
        hash_table = HashTable(lambda key: key, size=1)
        for i in range(20):
            hash_table.add(i, i)
        for i in range(20):
            hash_table.remove(i)
        hash_table.add(1, 1)
        self.assertEqual(hash_table.size(), 1)


if __name__ == "__main__":
    unittest.main()
