#include "array_product.h"

std::vector<int> productExceptSelf(const std::vector<int> &nums) {
  int n = static_cast<int>(nums.size());
  if (n == 0)
    return {};

  // Unsigned arithmetic wraps instead of invoking signed-overflow UB, so
  // intermediate products that overflow (e.g. when a later zero cancels
  // them) still yield the correct result.
  std::vector<unsigned int> acc(n, 1u);

  // Calculate prefix products (product of all elements before index i)
  unsigned int prefix = 1u;
  for (int i = 0; i < n; ++i) {
    acc[i] = prefix;
    prefix *= static_cast<unsigned int>(nums[i]);
  }

  // Calculate suffix products and multiply with prefix
  unsigned int suffix = 1u;
  for (int i = n - 1; i >= 0; --i) {
    acc[i] *= suffix;
    suffix *= static_cast<unsigned int>(nums[i]);
  }

  std::vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    result[i] = static_cast<int>(acc[i]);
  }
  return result;
}
