#include <string>

/**
 * @brief Finds minimum insertions to make a string a palindrome using recursion.
 * @param s The input string.
 * @return Minimum number of character insertions needed.
 */
int minimum_insertions_for_palindrome_basic(const std::string &s);

/**
 * @brief Finds minimum insertions to make a string a palindrome using memoization.
 * @param s The input string.
 * @return Minimum number of character insertions needed.
 */
int minimum_insertions_for_palindrome_memo(const std::string &s);

/**
 * @brief Finds minimum insertions to make a string a palindrome using tabulation.
 * @param s The input string.
 * @return Minimum number of character insertions needed.
 */
int minimum_insertions_for_palindrome_tab(const std::string &s);