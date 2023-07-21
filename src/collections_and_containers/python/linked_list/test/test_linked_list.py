from src.linked_list import LinkedList
from unittest import TestCase
import unittest


class TestLinkedList(TestCase):
    def test_empty_linked_list(self):
        linked_list = LinkedList()
        self.assertTrue(linked_list.empty())

    def test_clear(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)
        self.assertEqual(linked_list.size(), 3)

        linked_list.clear()
        self.assertTrue(linked_list.empty())

    def test_adding_multiple_elements(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        self.assertEqual(linked_list.size(), 3)
        self.assertEqual(linked_list.front(), 1)
        self.assertEqual(linked_list.back(), 3)

    def test_front(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        self.assertEqual(linked_list.front(), 1)

    def test_back(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        self.assertEqual(linked_list.back(), 3)

    def test_pop_front(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        linked_list.pop_front()
        self.assertEqual(linked_list.front(), 2)

        linked_list.pop_front()
        self.assertEqual(linked_list.front(), 3)

        linked_list.pop_front()
        self.assertTrue(linked_list.empty())

    def test_pop_back(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        linked_list.pop_back()
        self.assertEqual(linked_list.back(), 2)

        linked_list.pop_back()
        self.assertEqual(linked_list.back(), 1)

        linked_list.pop_back()
        self.assertTrue(linked_list.empty())

    def test_remove(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)

        linked_list.remove(2)
        self.assertEqual(linked_list.size(), 2)
        self.assertEqual(linked_list.front(), 1)
        self.assertEqual(linked_list.back(), 3)

        linked_list.remove(1)
        self.assertEqual(linked_list.size(), 1)
        self.assertEqual(linked_list.front(), 3)
        self.assertEqual(linked_list.back(), 3)

    def test_remove_from_empty_list(self):
        linked_list = LinkedList()
        linked_list.remove(1)
        self.assertTrue(linked_list.empty())

    def test_remove_non_existing_element(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)
        linked_list.push_back(3)
        linked_list.remove(4)
        self.assertEqual(linked_list.size(), 3)
        self.assertEqual(linked_list.front(), 1)
        self.assertEqual(linked_list.back(), 3)


if __name__ == "__main__":
    unittest.main()
