#pragma once

#include <vector>

/**
 * Calculate the sum of all elements in a subarray.
 * 
 * @param arr Input array
 * @param start Start index (inclusive)
 * @param end End index (inclusive)
 * @return Sum of elements from start to end
 */
int subarraySum(const std::vector<int>& arr, int start, int end);

/**
 * Prefix sum array for efficient range sum queries.
 * Supports O(1) range queries after O(n) preprocessing.
 */
class PrefixSum {
public:
    /**
     * Build prefix sum array from input.
     * @param arr Input array
     */
    explicit PrefixSum(const std::vector<int>& arr);
    
    /**
     * Get sum of elements from start to end (inclusive).
     * @param start Start index
     * @param end End index
     * @return Sum of elements in range
     */
    int rangeSum(int start, int end) const;
    
private:
    std::vector<long long> prefix_;
};
