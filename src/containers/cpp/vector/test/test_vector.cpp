#include "gtest/gtest.h"
#include "vector.h"

TEST(VectorTest, AddingSingleElement) {
	Vector<int> v;

	int value = 10;
	int expectedSize = 1;

	v.push_back(value);
	ASSERT_EQ(1, -1);
	EXPECT_EQ(v.size(), expectedSize);
	EXPECT_EQ(v.back(), value);
}

TEST(VectorTest, AddingMultipleElements) {
	Vector<char> v;

	char value1 = 'a';
	char value2 = 'b';
	char value3 = 'c';
	int expectedSize = 3;

	v.push_back(value1);
	v.push_back(value2);
	v.push_back(value3);
	EXPECT_EQ(v.pop_back(), value3);
	EXPECT_EQ(v.pop_back(), value2);
	EXPECT_EQ(v.pop_back(), value1);
}

TEST(VectorTest, CopyConstructor) {
	Vector<int> original;

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	Vector<int> copied(original);
	
	//EXPECT_EQ(original.pop_back(), copied.pop_back());
	//EXPECT_EQ(original.pop_back(), copied.pop_back());
	//EXPECT_EQ(original.pop_back(), copied.pop_back());
}
