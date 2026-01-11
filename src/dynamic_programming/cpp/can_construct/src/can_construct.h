#include <string>
#include <vector>

/**
 * @brief Determines if target string can be constructed from word bank.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return True if target can be constructed, false otherwise.
 */
bool canConstructBasic(const std::string &target,
                       const std::vector<std::string> &wordBank);

/**
 * @brief Determines if target string can be constructed using memoization.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return True if target can be constructed, false otherwise.
 */
bool canConstructMemo(const std::string &target,
                      const std::vector<std::string> &wordBank);

/**
 * @brief Determines if target string can be constructed using tabulation.
 * @param target The target string to construct.
 * @param wordBank Vector of words that can be reused.
 * @return True if target can be constructed, false otherwise.
 */
bool canConstructTable(const std::string &target,
                       const std::vector<std::string> &wordBank);
