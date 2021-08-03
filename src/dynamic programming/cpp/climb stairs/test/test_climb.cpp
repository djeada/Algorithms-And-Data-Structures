#include "climb.h"
#include "gtest/gtest.h"

TEST(ClimbTest, TestWith0) {
  int num = 0;
  int result = 1;

  ASSERT_EQ(climbBasic(num), result);
}

TEST(ClimbTest, TestBasicWith1) {
  int num = 1;
  int result = 1;

  ASSERT_EQ(climbBasic(num), result);
}

TEST(ClimbTest, TestBasicWith2) {
  int num = 2;
  int result = 2;

  ASSERT_EQ(climbBasic(num), result);
}

TEST(ClimbTest, TestBasictWith20) {
  int num = 20;
  int result = 121415;

  ASSERT_EQ(climbBasic(num), result);
}

TEST(ClimbTest, TestMemoWith0) {
  int num = 0;
  int result = 1;

  ASSERT_EQ(climbMemo(num), result);
}

TEST(ClimbTest, TestMemoWith1) {
  int num = 1;
  int result = 1;

  ASSERT_EQ(climbMemo(num), result);
}

TEST(ClimbTest, TestMemoWith2) {
  int num = 2;
  int result = 2;

  ASSERT_EQ(climbMemo(num), result);
}

TEST(ClimbTest, TestMemoWith20) {
  int num = 20;
  int result = 121415;

  ASSERT_EQ(climbMemo(num), result);
}
