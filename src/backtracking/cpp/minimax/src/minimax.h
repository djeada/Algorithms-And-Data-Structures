#include <utility>
#include <vector>

/**
 * @brief Evaluates the game state using the minimax algorithm.
 * @param board The current game board (3x3 grid).
 * @param player The current player (-1 or 1).
 * @return The best score achievable from this position.
 */
int minimax(std::vector<std::vector<int>> &board, int player);

/**
 * @brief Finds the best move for the current player using minimax.
 * @param board The current game board.
 * @param player The current player (-1 or 1).
 * @return The (row, col) pair for the best move.
 */
std::pair<int, int> find_best_move(std::vector<std::vector<int>> &board,
                                   int player);