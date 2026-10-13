#include "k_closest_points.h"
#include <algorithm>
#include <queue>

// Helper function to calculate squared distance from origin
static long long squaredDistance(const Point &p) {
  return static_cast<long long>(p.x) * p.x + static_cast<long long>(p.y) * p.y;
}

std::vector<Point> kClosestPoints(std::vector<Point> &points, int k) {
  if (k <= 0)
    return {};

  // Work on a copy so the caller's vector is left untouched
  std::vector<Point> sorted = points;
  if (k > static_cast<int>(sorted.size()))
    k = static_cast<int>(sorted.size());

  // Use partial_sort for O(n log k) complexity
  std::partial_sort(sorted.begin(), sorted.begin() + k, sorted.end(),
                    [](const Point &a, const Point &b) {
                      return squaredDistance(a) < squaredDistance(b);
                    });

  sorted.resize(k);
  return sorted;
}
