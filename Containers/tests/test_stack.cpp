#include "gtest/gtest.h"
#include "stack.h"

TEST(example, addingSingleElement) {
	Containers::Stack<int> s;

	int value = 10;
	int expectedSize = 1;

	s.push(value);
	EXPECT_EQ(s.size(), expectedSize);
	EXPECT_EQ(s.peek(), value);

}
