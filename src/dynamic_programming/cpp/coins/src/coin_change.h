#include <vector>

/**
 * @brief Finds the minimum number of coins needed to make up the given amount.
 * @param amount The target amount.
 * @param coins Vector of coin denominations.
 * @return Minimum number of coins needed, or INT_MAX if impossible.
 */
int coinChangeBasic(int amount, const std::vector<int> &coins);

/**
 * @brief Finds the minimum number of coins needed using memoization.
 * @param amount The target amount.
 * @param coins Vector of coin denominations.
 * @return Minimum number of coins needed, or INT_MAX if impossible.
 */
int coinChangeMemo(int amount, const std::vector<int> &coins);

/**
 * @brief Finds the minimum number of coins needed using tabulation.
 * @param amount The target amount.
 * @param coins Vector of coin denominations.
 * @return Minimum number of coins needed.
 */
int coinChangeTable(int amount, const std::vector<int> &coins);
