#include "vector.h"
#include "gtest/gtest.h"

TEST(VectorTest, EmptyVector) {
  Vector<int> vector;
  ASSERT_TRUE(vector.empty());
}

TEST(VectorTest, Clear) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);
  EXPECT_EQ(vector.size(), 3);

  vector.clear();
  ASSERT_TRUE(vector.empty());
}

TEST(VectorTest, AddingMultipleElements) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  EXPECT_EQ(vector.size(), 3);
  EXPECT_EQ(vector.front(), 1);
  EXPECT_EQ(vector.back(), 3);
}

TEST(VectorTest, Front) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  EXPECT_EQ(vector.front(), 1);
}

TEST(VectorTest, Back) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  EXPECT_EQ(vector.back(), 3);
}

TEST(VectorTest, Resize) {
  Vector<int> vector;
  vector.resize(1111);
  EXPECT_EQ(vector.size(), 1111);
}

TEST(VectorTest, Indexing) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  EXPECT_EQ(vector[0], 1);
  EXPECT_EQ(vector[1], 2);
  EXPECT_EQ(vector[2], 3);
}

TEST(VectorTest, CopyConstructor) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  Vector<int> vector2(vector);
  EXPECT_EQ(vector2.size(), 3);
  EXPECT_EQ(vector2[0], 1);
  EXPECT_EQ(vector2[1], 2);
  EXPECT_EQ(vector2[2], 3);
}

TEST(VectorTest, AssignmentOperator) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  Vector<int> vector2;
  vector2 = vector;
  EXPECT_EQ(vector2.size(), 3);
  EXPECT_EQ(vector2[0], 1);
  EXPECT_EQ(vector2[1], 2);
  EXPECT_EQ(vector2[2], 3);
}

TEST(VectorTest, Iterator) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  Vector<int>::iterator it = vector.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(it, vector.end());
}

TEST(VectorTest, AcessingIllegalIndex) {
  Vector<int> vector;
  vector.push_back(1);
  vector.push_back(2);
  vector.push_back(3);

  ASSERT_THROW(vector[3], std::out_of_range);
  ASSERT_THROW(vector[-1], std::out_of_range);
}