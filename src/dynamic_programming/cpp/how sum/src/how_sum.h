#include <vector>

std::vector<unsigned int> howSumBasic(const unsigned int target,
                                      const std::vector<unsigned int> &numbers);

std::vector<unsigned int> howSumMemo(const unsigned int target,
                                     const std::vector<unsigned int> &numbers);

std::vector<unsigned int> howSumTable(const unsigned int target,
                                      std::vector<unsigned int> numbers);
