#include "subarray_sum.h"

int subarraySum(const std::vector<int>& arr, int start, int end) {
    if (arr.empty() || start < 0 || end >= static_cast<int>(arr.size()) || start > end) {
        return 0;
    }
    
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += arr[i];
    }
    return sum;
}

PrefixSum::PrefixSum(const std::vector<int>& arr) {
    prefix_.resize(arr.size() + 1, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
        prefix_[i + 1] = prefix_[i] + arr[i];
    }
}

int PrefixSum::rangeSum(int start, int end) const {
    if (start < 0 || end >= static_cast<int>(prefix_.size()) - 1 || start > end) {
        return 0;
    }
    return static_cast<int>(prefix_[end + 1] - prefix_[start]);
}
