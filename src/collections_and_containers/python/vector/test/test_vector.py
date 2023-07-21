from src.vector import Vector
from unittest import TestCase
import unittest


class TestVector(TestCase):
    def test_empty_vector(self):
        vector = Vector()
        self.assertTrue(vector.empty())

    def test_adding_multiple_elements(self):
        vector = Vector()
        vector.push_back(1)
        vector.push_back(2)
        vector.push_back(3)
        self.assertEqual(vector.size(), 3)

        self.assertEqual(vector.pop_back(), 3)
        self.assertEqual(vector.pop_back(), 2)
        self.assertEqual(vector.pop_back(), 1)

        self.assertTrue(vector.empty())

        # adding the same elements in different order
        vector.push_back(3)
        vector.push_back(1)
        vector.push_back(2)

        self.assertEqual(vector.pop_back(), 2)
        self.assertEqual(vector.pop_back(), 1)
        self.assertEqual(vector.pop_back(), 3)

    def test_front(self):
        vector = Vector()
        vector.push_back(1)
        vector.push_back(2)
        vector.push_back(3)

        self.assertEqual(vector.front(), 1)

    def test_front_when_empty(self):
        vector = Vector()
        self.assertRaises(IndexError, vector.front)

    def test_back(self):
        vector = Vector()
        vector.push_back(1)
        vector.push_back(2)
        vector.push_back(3)

        self.assertEqual(vector.back(), 3)

    def test_back_when_empty(self):
        vector = Vector()
        self.assertRaises(IndexError, vector.back)

    def test_pop_back_when_empty(self):
        vector = Vector()
        self.assertRaises(IndexError, vector.pop_back)

    def test_resize(self):
        vector = Vector()
        vector.push_back(1)
        vector.push_back(2)
        vector.push_back(3)
        vector.resize(2)
        self.assertEqual(vector.size(), 2)
        self.assertEqual(vector[0], 1)
        self.assertEqual(vector[1], 2)
        self.assertRaises(IndexError, vector.__getitem__, 2)

    def test_resize_when_empty(self):
        vector = Vector()
        vector.resize(2)
        self.assertEqual(vector.size(), 2)
        self.assertEqual(vector[0], None)
        self.assertEqual(vector[1], None)
        self.assertRaises(IndexError, vector.__getitem__, 2)

    def test_clear(self):
        vector = Vector()
        vector.push_back(1)
        vector.push_back(2)
        vector.push_back(3)
        vector.clear()
        self.assertTrue(vector.empty())
