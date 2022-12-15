#include "queue.h"
#include "gtest/gtest.h"

TEST(QueueTest, EmptyQueue) {
  Queue<int> queue;
  ASSERT_TRUE(queue.isEmpty());
}

TEST(QueueTest, AddingMultipleElements) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  EXPECT_EQ(queue.size(), 3);

  EXPECT_EQ(queue.dequeue(), 1);
  EXPECT_EQ(queue.dequeue(), 2);
  EXPECT_EQ(queue.dequeue(), 3);

  ASSERT_TRUE(queue.isEmpty());

  // adding the same elements in different order
  queue.enqueue(3);
  queue.enqueue(1);
  queue.enqueue(2);

  EXPECT_EQ(queue.dequeue(), 3);
  EXPECT_EQ(queue.dequeue(), 1);
  EXPECT_EQ(queue.dequeue(), 2);
}

TEST(QueueTest, FrontAndBack) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  EXPECT_EQ(queue.front(), 1);
  EXPECT_EQ(queue.back(), 3);
}

TEST(QueueTest, FrontWhenEmpty) {
  Queue<int> queue;
  ASSERT_THROW(queue.front(), std::out_of_range);
}

TEST(QueueTest, BackWhenEmpty) {
  Queue<int> queue;
  ASSERT_THROW(queue.back(), std::out_of_range);
}

TEST(QueueTest, CopyConstructor) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  Queue<int> queue2(queue);

  EXPECT_EQ(queue2.dequeue(), 1);
  EXPECT_EQ(queue2.dequeue(), 2);
  EXPECT_EQ(queue2.dequeue(), 3);
}

TEST(QueueTest, AssignmentOperator) {
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  Queue<int> queue2;
  queue2 = queue;

  EXPECT_EQ(queue2.dequeue(), 1);
  EXPECT_EQ(queue2.dequeue(), 2);
  EXPECT_EQ(queue2.dequeue(), 3);
}
