#include <vector>

/**
 * @brief Finds any combination of numbers that add up to target.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return A vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int> howSumBasic(const unsigned int target,
                                      const std::vector<unsigned int> &numbers);

/**
 * @brief Finds any combination of numbers that add up to target using memoization.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return A vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int> howSumMemo(const unsigned int target,
                                     const std::vector<unsigned int> &numbers);

/**
 * @brief Finds any combination of numbers that add up to target using tabulation.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return A vector of numbers that sum to target, or empty if impossible.
 */
std::vector<unsigned int> howSumTable(const unsigned int target,
                                      const std::vector<unsigned int> &numbers);
