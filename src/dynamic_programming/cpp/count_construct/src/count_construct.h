#include <string>
#include <vector>

/**
 * @brief Counts the number of ways to construct target from word bank.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Number of ways to construct target.
 */
int countConstructBasic(const std::string &target,
                        const std::vector<std::string> &wordBank);

/**
 * @brief Counts the number of ways to construct target using memoization.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Number of ways to construct target.
 */
int countConstructMemo(const std::string &target,
                       const std::vector<std::string> &wordBank);

/**
 * @brief Counts the number of ways to construct target using tabulation.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Number of ways to construct target.
 */
int countConstructTable(const std::string &target,
                        const std::vector<std::string> &wordBank);
