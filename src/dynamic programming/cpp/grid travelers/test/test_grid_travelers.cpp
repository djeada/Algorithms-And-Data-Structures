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
