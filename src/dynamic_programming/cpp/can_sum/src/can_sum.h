#include <vector>

/**
 * @brief Determines if target sum can be achieved using numbers from the list.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return True if target sum is achievable, false otherwise.
 */
bool canSumBasic(const unsigned int target,
                 const std::vector<unsigned int> &numbers);

/**
 * @brief Determines if target sum can be achieved using memoization.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return True if target sum is achievable, false otherwise.
 */
bool canSumMemo(const unsigned int target,
                const std::vector<unsigned int> &numbers);

/**
 * @brief Determines if target sum can be achieved using tabulation.
 * @param target The target sum to achieve.
 * @param numbers Vector of numbers that can be reused.
 * @return True if target sum is achievable, false otherwise.
 */
bool canSumTable(const unsigned int target,
                 const std::vector<unsigned int> &numbers);
