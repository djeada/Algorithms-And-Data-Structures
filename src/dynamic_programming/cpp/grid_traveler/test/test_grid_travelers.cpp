#include "grid_travelers.h"
#include "gtest/gtest.h"

TEST(GridTravelersTest, TestBasic1) {
  int m = 1;
  int n = 1;
  int result = 1;

  ASSERT_EQ(gridTravelersBasic(m, n), result);
}

TEST(GridTravelersTest, TestBasic2) {
  int m = 2;
  int n = 3;
  int result = 3;

  ASSERT_EQ(gridTravelersBasic(m, n), result);
}

TEST(GridTravelersTest, TestBasic3) {
  int m = 3;
  int n = 3;
  int result = 6;

  ASSERT_EQ(gridTravelersBasic(m, n), result);
}

TEST(GridTravelersTest, TestBasic4) {
  int m = 10;
  int n = 10;
  int result = 48620;

  ASSERT_EQ(gridTravelersBasic(m, n), result);
}

TEST(GridTravelersTest, TestMemo1) {
  int m = 1;
  int n = 1;
  int result = 1;

  ASSERT_EQ(gridTravelersMemo(m, n), result);
}

TEST(GridTravelersTest, TestMemo2) {
  int m = 2;
  int n = 3;
  int result = 3;

  ASSERT_EQ(gridTravelersMemo(m, n), result);
}

TEST(GridTravelersTest, TestMemo3) {
  int m = 3;
  int n = 3;
  int result = 6;

  ASSERT_EQ(gridTravelersMemo(m, n), result);
}

TEST(GridTravelersTest, TestMemo4) {
  int m = 10;
  int n = 10;
  int result = 48620;

  ASSERT_EQ(gridTravelersMemo(m, n), result);
}

TEST(GridTravelersTest, TestTable1) {
  int m = 1;
  int n = 1;
  int result = 1;

  ASSERT_EQ(gridTravelersTable(m, n), result);
}

TEST(GridTravelersTest, TestTable2) {
  int m = 2;
  int n = 3;
  int result = 3;

  ASSERT_EQ(gridTravelersTable(m, n), result);
}

TEST(GridTravelersTest, TestTable3) {
  int m = 3;
  int n = 3;
  int result = 6;

  ASSERT_EQ(gridTravelersTable(m, n), result);
}

TEST(GridTravelersTest, TestTable4) {
  int m = 10;
  int n = 10;
  int result = 48620;

  ASSERT_EQ(gridTravelersTable(m, n), result);
}

TEST(GridTravelersEdgeCases, NonPositiveDimensions) {
  for (auto f : {gridTravelersBasic, gridTravelersMemo, gridTravelersTable}) {
    ASSERT_EQ(f(0, 3), 0);
    ASSERT_EQ(f(3, 0), 0);
    ASSERT_EQ(f(-1, 3), 0);
    ASSERT_EQ(f(3, -2), 0);
    ASSERT_EQ(f(0, 0), 0);
  }
}

TEST(GridTravelersEdgeCases, SingleRowOrColumn) {
  for (auto f : {gridTravelersBasic, gridTravelersMemo, gridTravelersTable}) {
    ASSERT_EQ(f(1, 1), 1);
    ASSERT_EQ(f(1, 9), 1);
    ASSERT_EQ(f(9, 1), 1);
  }
}

TEST(GridTravelersEdgeCases, AsymmetricGrid) {
  for (auto f : {gridTravelersBasic, gridTravelersMemo, gridTravelersTable}) {
    ASSERT_EQ(f(2, 5), 5);
    ASSERT_EQ(f(5, 2), 5);
    ASSERT_EQ(f(3, 7), 28);
  }
}
