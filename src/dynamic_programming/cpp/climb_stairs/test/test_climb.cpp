#include "climb.h"
#include "gtest/gtest.h"

TEST(TestClimbBasic, TestWith0) {
  int num = 0;
  int result = 1;
  EXPECT_EQ(countWaysToClimbBasic(num), result);
}

TEST(TestClimbBasic, TestWith1) {
  int num = 1;
  int result = 1;
  EXPECT_EQ(countWaysToClimbBasic(num), result);
}

TEST(TestClimbBasic, TestWith2) {
  int num = 2;
  int result = 2;
  EXPECT_EQ(countWaysToClimbBasic(num), result);
}

TEST(TestClimbBasic, TestWith10) {
  int num = 10;
  int result = 274;
  EXPECT_EQ(countWaysToClimbBasic(num), result);
}

TEST(TestClimbBasic, TestWith20) {
  int num = 20;
  int result = 121415;
  EXPECT_EQ(countWaysToClimbBasic(num), result);
}

TEST(TestClimbMemo, TestWith0) {
  int num = 0;
  int result = 1;
  EXPECT_EQ(countWaysToClimbMemo(num), result);
}

TEST(TestClimbMemo, TestWith1) {
  int num = 1;
  int result = 1;
  EXPECT_EQ(countWaysToClimbMemo(num), result);
}

TEST(TestClimbMemo, TestWith2) {
  int num = 2;
  int result = 2;
  EXPECT_EQ(countWaysToClimbMemo(num), result);
}

TEST(TestClimbMemo, TestWith10) {
  int num = 10;
  int result = 274;
  EXPECT_EQ(countWaysToClimbMemo(num), result);
}

TEST(TestClimbMemo, TestWith20) {
  int num = 20;
  int result = 121415;
  EXPECT_EQ(countWaysToClimbMemo(num), result);
}

TEST(TestClimbTable, TestWith0) {
  int num = 0;
  int result = 1;
  EXPECT_EQ(countWaysToClimbTable(num), result);
}

TEST(TestClimbTable, TestWith1) {
  int num = 1;
  int result = 1;
  EXPECT_EQ(countWaysToClimbTable(num), result);
}

TEST(TestClimbTable, TestWith2) {
  int num = 2;
  int result = 2;
  EXPECT_EQ(countWaysToClimbTable(num), result);
}

TEST(TestClimbTable, TestWith10) {
  int num = 10;
  int result = 274;
  EXPECT_EQ(countWaysToClimbTable(num), result);
}

TEST(TestClimbTable, TestWith20) {
  int num = 20;
  int result = 121415;
  EXPECT_EQ(countWaysToClimbTable(num), result);
}
