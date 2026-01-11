#pragma once

#include <unordered_map>
#include <vector>

/**
 * Calculate the dot product of two sparse vectors.
 * Sparse vectors are represented as maps from index to value.
 * 
 * @param vec1 First sparse vector
 * @param vec2 Second sparse vector
 * @return Dot product of the two vectors
 */
int sparseVectorProduct(const std::unordered_map<int, int>& vec1,
                        const std::unordered_map<int, int>& vec2);

/**
 * Sparse vector class for efficient storage and dot product.
 */
class SparseVector {
public:
    /**
     * Create a sparse vector from a dense vector.
     * @param nums Dense vector representation
     */
    explicit SparseVector(const std::vector<int>& nums);
    
    /**
     * Calculate dot product with another sparse vector.
     * @param other Other sparse vector
     * @return Dot product
     */
    int dotProduct(const SparseVector& other) const;
    
private:
    std::unordered_map<int, int> data_;
};
