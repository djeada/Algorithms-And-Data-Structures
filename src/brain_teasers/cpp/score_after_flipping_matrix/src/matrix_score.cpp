#include "matrix_score.h"

int matrixScore(std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }
    
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    
    // Step 1: Flip rows so that the first column is all 1s
    // This ensures the most significant bit is 1 for each row
    for (int i = 0; i < rows; ++i) {
        if (grid[i][0] == 0) {
            // Flip this row
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // Step 2: For each column (except the first), flip if it has more 0s than 1s
    for (int j = 1; j < cols; ++j) {
        int ones = 0;
        for (int i = 0; i < rows; ++i) {
            ones += grid[i][j];
        }
        
        if (ones < rows - ones) {
            // More 0s than 1s, flip this column
            for (int i = 0; i < rows; ++i) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    
    // Step 3: Calculate the score
    int score = 0;
    for (int i = 0; i < rows; ++i) {
        int rowValue = 0;
        for (int j = 0; j < cols; ++j) {
            rowValue = (rowValue << 1) | grid[i][j];
        }
        score += rowValue;
    }
    
    return score;
}
