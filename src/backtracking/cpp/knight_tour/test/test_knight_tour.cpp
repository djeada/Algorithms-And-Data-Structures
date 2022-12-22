#include "knight_tour.h"
#include "gtest/gtest.h"
/*
    def test_1(self):
        n = 1
        expected = [[[1]]]
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_2(self):
        n = 2
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_3(self):
        n = 3
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_4(self):
        n = 4
        expected = list()
        actual = knight_tour(n)

        self.assertListEqual(actual, expected)

    def test_5(self):
        n = 5
        expected_element = [
            [1, 14, 19, 8, 25],
            [6, 9, 2, 13, 18],
            [15, 20, 7, 24, 3],
            [10, 5, 22, 17, 12],
            [21, 16, 11, 4, 23],
        ]
        excepted_length = 304
        actual = knight_tour(n)

        self.assertTrue(expected_element in actual)
        self.assertEqual(len(actual), excepted_length)

*/

TEST(TestKnightTour, TestN1) {
  int n = 1;
  std::vector<std::vector<std::vector<int>>> expected = {
      {{1}},
  };
  auto actual = knight_tour(n);

  EXPECT_EQ(expected, actual);
}

TEST(TestKnightTour, TestN2) {
  int n = 2;
  std::vector<std::vector<std::vector<int>>> expected = {};
  auto actual = knight_tour(n);

  EXPECT_EQ(expected, actual);
}

TEST(TestKnightTour, TestN3) {
  int n = 3;
  std::vector<std::vector<std::vector<int>>> expected = {};

  auto actual = knight_tour(n);
  EXPECT_EQ(expected, actual);
}

TEST(TestKnightTour, TestN4) {
  int n = 4;
  std::vector<std::vector<std::vector<int>>> expected = {};

  auto actual = knight_tour(n);

  EXPECT_EQ(expected, actual);
}

TEST(TestKnightTour, TestN5) {
  int n = 5;
  std::vector<std::vector<int>> expected_element = {
      {1, 14, 19, 8, 25},  {6, 9, 2, 13, 18},   {15, 20, 7, 24, 3},
      {10, 5, 22, 17, 12}, {21, 16, 11, 4, 23},
  };
  int excepted_length = 304;

  auto actual = knight_tour(n);

  EXPECT_EQ(actual.size(), excepted_length);
  EXPECT_TRUE(std::find(actual.begin(), actual.end(), expected_element) !=
              actual.end());
}