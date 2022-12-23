#include <vector>

std::vector<unsigned int>
bestSumBasic(unsigned int target, const std::vector<unsigned int> &numbers);

std::vector<unsigned int> bestSumMemo(unsigned int target,
                                      const std::vector<unsigned int> &numbers);

std::vector<unsigned int>
bestSumTabulation(unsigned int target,
                  const std::vector<unsigned int> &numbers);
