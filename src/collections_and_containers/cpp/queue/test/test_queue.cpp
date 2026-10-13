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

TEST(QueueTest, WrapAroundAndExpandKeepOrder) {
  Queue<int> queue;
  int next_in = 0, next_out = 0;
  // Keep head away from 0 so the buffer wraps before it expands.
  for (int i = 0; i < 10; i++)
    queue.enqueue(next_in++);
  for (int i = 0; i < 10; i++)
    EXPECT_EQ(queue.dequeue(), next_out++);
  for (int i = 0; i < 12; i++)
    queue.enqueue(next_in++);
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(queue.dequeue(), next_out++);
  for (int i = 0; i < 100; i++) {
    queue.enqueue(next_in++);
    EXPECT_EQ(queue.back(), next_in - 1);
  }
  EXPECT_EQ(queue.front(), next_out);
  EXPECT_EQ(queue.size(), next_in - next_out);
  while (!queue.isEmpty()) {
    EXPECT_EQ(queue.dequeue(), next_out++);
  }
  EXPECT_EQ(next_out, next_in);
  EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(QueueTest, CopyIsIndependentAndSelfAssignmentSafe) {
  Queue<int> a;
  for (int i = 0; i < 20; i++)
    a.enqueue(i);
  for (int i = 0; i < 7; i++)
    a.dequeue();
  Queue<int> b(a);
  a.clear();
  a.enqueue(99);
  EXPECT_EQ(b.size(), 13);
  EXPECT_EQ(b.front(), 7);
  EXPECT_EQ(b.back(), 19);
  b = b;
  EXPECT_EQ(b.size(), 13);
  EXPECT_THROW(Queue<int>().front(), std::out_of_range);
  EXPECT_THROW(Queue<int>().back(), std::out_of_range);
}
