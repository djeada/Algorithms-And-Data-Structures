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


if __name__ == "__main__":
    unittest.main()
