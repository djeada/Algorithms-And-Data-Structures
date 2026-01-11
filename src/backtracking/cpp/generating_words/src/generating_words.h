#include <set>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @brief Finds all valid words from a board using DFS traversal.
 *
 * Starting from each cell, explores all paths through adjacent cells
 * (including diagonals) to find words that exist in the word dictionary.
 *
 * @param board 2D grid of characters.
 * @param word_dict Set of valid words to search for.
 * @return Set of all found words that exist in the word dictionary.
 */
std::set<std::string>
generate_words(const std::vector<std::vector<char>> &board,
               const std::unordered_set<std::string> &word_dict);