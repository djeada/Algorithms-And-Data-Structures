#include <vector>

/**
 * @brief Finds the length of the longest increasing subsequence using recursion.
 * @param array The input array.
 * @return Length of the longest increasing subsequence.
 */
int longestIncreasingSubarrayBasic(const std::vector<int> &array);

/**
 * @brief Finds the length of the longest increasing subsequence using memoization.
 * @param array The input array.
 * @return Length of the longest increasing subsequence.
 */
int longestIncreasingSubarrayMemo(const std::vector<int> &array);

/**
 * @brief Finds the length of the longest increasing subsequence using tabulation.
 * @param array The input array.
 * @return Length of the longest increasing subsequence.
 */
int longestIncreasingSubarrayTable(const std::vector<int> &array);
