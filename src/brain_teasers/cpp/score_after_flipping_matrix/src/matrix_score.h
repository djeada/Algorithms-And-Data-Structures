#pragma once

#include <vector>

/**
 * Calculate the score after flipping a binary matrix.
 * Each row represents a binary number. We can flip any row or column.
 * Goal is to maximize the sum of all rows interpreted as binary numbers.
 * 
 * @param grid Binary matrix (0s and 1s)
 * @return Maximum possible score after optimal flipping
 */
int matrixScore(std::vector<std::vector<int>>& grid);
