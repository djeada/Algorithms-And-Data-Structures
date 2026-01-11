#include "k_closest_points.h"
#include <algorithm>
#include <queue>

// Helper function to calculate squared distance from origin
static int squaredDistance(const Point& p) {
    return p.x * p.x + p.y * p.y;
}

std::vector<Point> kClosestPoints(std::vector<Point>& points, int k) {
    if (k <= 0) return {};
    if (k >= static_cast<int>(points.size())) return points;
    
    // Use partial_sort for O(n log k) complexity
    std::partial_sort(points.begin(), points.begin() + k, points.end(),
        [](const Point& a, const Point& b) {
            return squaredDistance(a) < squaredDistance(b);
        });
    
    return std::vector<Point>(points.begin(), points.begin() + k);
}
