#pragma once

#include <vector>

/**
 * Calculate the product of all elements in an array except the element at each index.
 * The result is returned as a new array with the same length as the input array.
 * 
 * @param nums Input array of integers
 * @return Array where each element is the product of all other elements
 */
std::vector<int> productExceptSelf(const std::vector<int>& nums);
