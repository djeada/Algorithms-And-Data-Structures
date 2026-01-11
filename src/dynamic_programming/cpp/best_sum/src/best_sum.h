#include <vector>

/**
 * @brief Finds the shortest combination of numbers that add up to target.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return Shortest vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int>
bestSumBasic(unsigned int target, const std::vector<unsigned int> &numbers);

/**
 * @brief Finds the shortest combination using memoization.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return Shortest vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int> bestSumMemo(unsigned int target,
                                      const std::vector<unsigned int> &numbers);

/**
 * @brief Finds the shortest combination using tabulation (bottom-up DP).
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return Shortest vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int>
bestSumTabulation(unsigned int target,
                  const std::vector<unsigned int> &numbers);
