#include "array_product.h"

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n == 0) return {};
    
    std::vector<int> result(n, 1);
    
    // Calculate prefix products (product of all elements before index i)
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    
    // Calculate suffix products and multiply with prefix
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    
    return result;
}
