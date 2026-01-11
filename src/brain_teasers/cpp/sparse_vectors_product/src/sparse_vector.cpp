#include "sparse_vector.h"
#include <vector>

int sparseVectorProduct(const std::unordered_map<int, int>& vec1,
                        const std::unordered_map<int, int>& vec2) {
    int result = 0;
    
    // Iterate over the smaller map for efficiency
    const auto& smaller = (vec1.size() <= vec2.size()) ? vec1 : vec2;
    const auto& larger = (vec1.size() <= vec2.size()) ? vec2 : vec1;
    
    for (const auto& pair : smaller) {
        auto it = larger.find(pair.first);
        if (it != larger.end()) {
            result += pair.second * it->second;
        }
    }
    
    return result;
}

SparseVector::SparseVector(const std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            data_[static_cast<int>(i)] = nums[i];
        }
    }
}

int SparseVector::dotProduct(const SparseVector& other) const {
    return sparseVectorProduct(data_, other.data_);
}
