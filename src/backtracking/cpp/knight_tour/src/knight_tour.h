#include <string>
#include <vector>

/**
 * @brief Finds all knight's tour solutions for an n x n board.
 *
 * A knight's tour is a sequence of moves where the knight visits
 * every square exactly once.
 *
 * @param n Size of the board.
 * @return Vector of all valid tours, where each tour is an n x n grid showing the order of moves.
 */
std::vector<std::vector<std::vector<int>>> knight_tour(int n);