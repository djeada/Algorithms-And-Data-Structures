import unittest
import sys
sys.path.insert(0, '../src')

from fib import fib

class TestFib(unittest.TestCase):
	def test_with_0(self):
		num = 0
		result = 0
		self.assertEqual(fib(num), result)

	def test_with_1(self):
		num = 1
		result = 1
		self.assertEqual(fib(num), result)

	def test_with_2(self):
		num = 2
		result = 1
		self.assertEqual(fib(num), result)

	def test_with_10(self):
		num = 10
		result = 55
		self.assertEqual(fib(num), result)

	def test_with_20(self):
		num = 20
		result = 6765
		self.assertEqual(fib(num), result)

if __name__ == "__main__":
	unittest.main()
