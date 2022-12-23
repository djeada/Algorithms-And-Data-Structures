#include "stack.h"
#include "gtest/gtest.h"

TEST(StackTest, EmptyStack) {
  Stack<int> stack;
  ASSERT_TRUE(stack.isEmpty());
}

TEST(StackTest, AddingMultipleElements) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  EXPECT_EQ(stack.size(), 3);

  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);

  ASSERT_TRUE(stack.isEmpty());

  // adding the same elements in different order
  stack.push(3);
  stack.push(1);
  stack.push(2);

  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);
  EXPECT_EQ(stack.pop(), 3);
}

TEST(StackTest, Top) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  EXPECT_EQ(stack.top(), 3);
}

TEST(StackTest, TopWhenEmpty) {
  Stack<int> stack;
  ASSERT_THROW(stack.top(), std::out_of_range);
}

TEST(StackTest, PopWhenEmpty) {
  Stack<int> stack;
  ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST(StackTest, CopyConstructor) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  Stack<int> stack2(stack);
  EXPECT_EQ(stack2.pop(), 3);
  EXPECT_EQ(stack2.pop(), 2);
  EXPECT_EQ(stack2.pop(), 1);
}

TEST(StackTest, AssignmentOperator) {
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  Stack<int> stack2;
  stack2 = stack;
  EXPECT_EQ(stack2.pop(), 3);
  EXPECT_EQ(stack2.pop(), 2);
  EXPECT_EQ(stack2.pop(), 1);
}
