#include "gtest/gtest.h"
#include "stack.h"

TEST(StackTest, AddingSingleElement) {
	Stack<int> s;

	int value = 10;
	int expectedSize = 1;

	s.push(value);
	EXPECT_EQ(s.size(), expectedSize);
	EXPECT_EQ(s.peek(), value);
}

TEST(StackTest, AddingMultipleElements) {
	Stack<char> s;

	char value1 = 'a';
	char value2 = 'b';
	char value3 = 'c';
	int expectedSize = 3;

	s.push(value1);
	s.push(value2);
	s.push(value3);
	EXPECT_EQ(s.pop(), value3);
	EXPECT_EQ(s.pop(), value2);
	EXPECT_EQ(s.pop(), value1);
}

TEST(StackTest, CopyConstructor) {
	Stack<int> original;

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	Stack<int> copied(original);
	
	//EXPECT_EQ(original.pop(), copied.pop());
	//EXPECT_EQ(original.pop(), copied.pop());
	//EXPECT_EQ(original.pop(), copied.pop());
}

