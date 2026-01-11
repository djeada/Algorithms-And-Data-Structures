#include "matrix_score.h"
#include "gtest/gtest.h"

TEST(MatrixScoreTest, BasicExample) {
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };
    
    EXPECT_EQ(matrixScore(grid), 39);
}

TEST(MatrixScoreTest, SingleRow) {
    std::vector<std::vector<int>> grid = {{0, 1}};
    EXPECT_EQ(matrixScore(grid), 3);  // Flip to get [1, 1] = 3
}

TEST(MatrixScoreTest, SingleColumn) {
    std::vector<std::vector<int>> grid = {{0}, {1}, {0}};
    EXPECT_EQ(matrixScore(grid), 3);  // All 1s = 1+1+1 = 3
}

TEST(MatrixScoreTest, AllOnes) {
    std::vector<std::vector<int>> grid = {
        {1, 1},
        {1, 1}
    };
    EXPECT_EQ(matrixScore(grid), 6);  // 3 + 3
}

TEST(MatrixScoreTest, AllZeros) {
    std::vector<std::vector<int>> grid = {
        {0, 0},
        {0, 0}
    };
    EXPECT_EQ(matrixScore(grid), 6);  // Flip rows to get all 1s: 3 + 3
}

TEST(MatrixScoreTest, EmptyGrid) {
    std::vector<std::vector<int>> grid = {};
    EXPECT_EQ(matrixScore(grid), 0);
}
