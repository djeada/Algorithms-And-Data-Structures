#pragma once

#include <vector>
#include <algorithm>
#include <random>

/**
 * Fisher-Yates shuffle algorithm for randomizing an array.
 * 
 * @param arr Array to shuffle (modified in place)
 */
template<typename T>
void shuffleArray(std::vector<T>& arr) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    for (int i = static_cast<int>(arr.size()) - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        std::swap(arr[i], arr[j]);
    }
}

/**
 * Get a shuffled copy of an array.
 * 
 * @param arr Input array
 * @return Shuffled copy of the array
 */
template<typename T>
std::vector<T> getShuffledCopy(const std::vector<T>& arr) {
    std::vector<T> result = arr;
    shuffleArray(result);
    return result;
}
