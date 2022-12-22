#include <utility>
#include <vector>

int minimax(std::vector<std::vector<int>> &board, int player);
std::pair<int, int> find_best_move(std::vector<std::vector<int>> &board,
                                   int player);