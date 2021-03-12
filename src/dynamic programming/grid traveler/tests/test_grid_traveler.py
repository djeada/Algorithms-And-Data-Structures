import unittest
import sys
sys.path.insert(0, '../src')

from grid_traveler import grid_traveler

class TestFib(unittest.TestCase):
	def test_with_1_and_1(self):
		m = 1
		n = 1
		result = 1
		self.assertEqual(grid_traveler(m, n), result)

	def test_with_2_and_3(self):
		m = 2
		n = 3
		result = 3
		self.assertEqual(grid_traveler(m, n), result)

	def test_with_3_and_3(self):
		m = 3
		n = 3
		result = 6
		self.assertEqual(grid_traveler(m, n), result)

	def test_with_18_and_18(self):
		m = 18
		n = 18
		result = 2333606220
		self.assertEqual(grid_traveler(m, n), result)

if __name__ == "__main__":
	unittest.main()
