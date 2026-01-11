#include <unordered_map>

/**
 * @brief Counts ways to climb n stairs taking 1, 2, or 3 steps at a time.
 * @param numSteps Total number of steps to climb.
 * @return Number of distinct ways to reach the top.
 */
int countWaysToClimbBasic(int numSteps);

/**
 * @brief Counts ways to climb n stairs using memoization.
 * @param n Total number of steps to climb.
 * @return Number of distinct ways to reach the top.
 */
int countWaysToClimbMemo(int n);

/**
 * @brief Counts ways to climb n stairs using tabulation (bottom-up DP).
 * @param n Total number of steps to climb.
 * @return Number of distinct ways to reach the top.
 */
int countWaysToClimbTable(int n);