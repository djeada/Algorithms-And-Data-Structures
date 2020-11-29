#include "gtest/gtest.h"
#include "queue.h"

TEST(QueueTest, AddingSingleElement) {
	Queue<int> q;

	int value = 10;
	int expectedSize = 1;

	q.enqueue(value);
	EXPECT_EQ(q.size(), expectedSize);
	EXPECT_EQ(q.peek(), value);
}

TEST(QueueTest, AddingMultipleElements) {
	Queue<char> q;

	char value1 = 'a';
	char value2 = 'b';
	char value3 = 'c';
	int expectedSize = 3;

	q.enqueue(value1);
	q.enqueue(value2);
	q.enqueue(value3);
	EXPECT_EQ(q.dequeue(), value1);
	EXPECT_EQ(q.dequeue(), value2);
	EXPECT_EQ(q.dequeue(), value3);
}

TEST(QueueTest, CopyConstructor) {
	Queue<int> original;

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	Queue<int> copied(original);
	
	//EXPECT_EQ(original.dequeue(), copied.dequeue());
	//EXPECT_EQ(original.dequeue(), copied.dequeue());
	//EXPECT_EQ(original.dequeue(), copied.dequeue());
}

