#include "fibonacci.h"
#include "gtest/gtest.h"

TEST(FibonacciTest, TestWith0) {
  int num = 0;
  int result = 0;

  ASSERT_EQ(fibonacciBasic(num), result);
}

TEST(FibonacciTest, TestBasicWith1) {
  int num = 1;
  int result = 1;

  ASSERT_EQ(fibonacciBasic(num), result);
}

TEST(FibonacciTest, TestBasicWith2) {
  int num = 2;
  int result = 1;

  ASSERT_EQ(fibonacciBasic(num), result);
}

TEST(FibonacciTest, TestBasictWith20) {
  int num = 20;
  int result = 6765;

  ASSERT_EQ(fibonacciBasic(num), result);
}

TEST(FibonacciTest, TestMemoWith0) {
  int num = 0;
  int result = 0;

  ASSERT_EQ(fibonacciMemo(num), result);
}

TEST(FibonacciTest, TestMemoWith1) {
  int num = 1;
  int result = 1;

  ASSERT_EQ(fibonacciMemo(num), result);
}

TEST(FibonacciTest, TestMemoWith2) {
  int num = 2;
  int result = 1;

  ASSERT_EQ(fibonacciMemo(num), result);
}

TEST(FibonacciTest, TestMemoWith20) {
  int num = 20;
  int result = 6765;

  ASSERT_EQ(fibonacciMemo(num), result);
}

TEST(FibonacciTest, TestTableWith0) {
  int num = 0;
  int result = 0;

  ASSERT_EQ(fibonacciTable(num), result);
}

TEST(FibonacciTest, TestTableWith1) {
  int num = 1;
  int result = 1;

  ASSERT_EQ(fibonacciTable(num), result);
}

TEST(FibonacciTest, TestTableWith2) {
  int num = 2;
  int result = 1;

  ASSERT_EQ(fibonacciTable(num), result);
}

TEST(FibonacciTest, TestTableWith20) {
  int num = 20;
  int result = 6765;

  ASSERT_EQ(fibonacciTable(num), result);
}
