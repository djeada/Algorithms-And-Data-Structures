#include <vector>

/**
 * @brief Finds the length of the longest common subsequence using recursion.
 * @param arrayA First array.
 * @param arrayB Second array.
 * @return Length of the longest common subsequence.
 */
int longestCommonSubsequenceBasic(const std::vector<int> &arrayA,
                                  const std::vector<int> &arrayB);

/**
 * @brief Finds the length of the longest common subsequence using memoization.
 * @param arrayA First array.
 * @param arrayB Second array.
 * @return Length of the longest common subsequence.
 */
int longestCommonSubsequenceMemo(const std::vector<int> &arrayA,
                                 const std::vector<int> &arrayB);

/**
 * @brief Finds the length of the longest common subsequence using tabulation.
 * @param arrayA First array.
 * @param arrayB Second array.
 * @return Length of the longest common subsequence.
 */
int longestCommonSubsequenceTable(const std::vector<int> &arrayA,
                                  const std::vector<int> &arrayB);
