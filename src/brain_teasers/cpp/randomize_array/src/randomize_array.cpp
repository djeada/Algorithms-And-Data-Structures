#include "randomize_array.h"

// Template instantiations
template void shuffleArray<int>(std::vector<int>&);
template void shuffleArray<double>(std::vector<double>&);
template std::vector<int> getShuffledCopy<int>(const std::vector<int>&);
template std::vector<double> getShuffledCopy<double>(const std::vector<double>&);
