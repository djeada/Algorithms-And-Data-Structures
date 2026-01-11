#include <string>
#include <vector>

/**
 * @brief Finds all ways to construct target from word bank.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Vector of all possible word combinations that construct target.
 */
std::vector<std::vector<std::string>>
allConstructBasic(const std::string &target,
                  const std::vector<std::string> &wordBank);

/**
 * @brief Finds all ways to construct target using memoization.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Vector of all possible word combinations that construct target.
 */
std::vector<std::vector<std::string>>
allConstructMemo(const std::string &target,
                 const std::vector<std::string> &wordBank);

/**
 * @brief Finds all ways to construct target using tabulation.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return Vector of all possible word combinations that construct target.
 */
std::vector<std::vector<std::string>>
allConstructTable(const std::string &target,
                  const std::vector<std::string> &wordBank);
