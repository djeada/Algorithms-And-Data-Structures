#include <string>

/**
 * @brief Checks if a string matches a pattern using backtracking.
 *
 * Each character in the pattern represents a variable that can match
 * one or more characters in the string. The same pattern character
 * must match the same substring throughout.
 *
 * @param string The string to match against.
 * @param pattern The pattern to match (each character is a variable).
 * @return True if the string matches the pattern, false otherwise.
 */
bool string_pattern(const std::string &string, const std::string &pattern);