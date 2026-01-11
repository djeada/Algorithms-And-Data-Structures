#pragma once

#include <vector>

/**
 * Represents a point in 2D space
 */
struct Point {
    int x;
    int y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

/**
 * Find the K closest points to the origin (0, 0).
 * Distance is calculated using Euclidean distance.
 * 
 * @param points Vector of points
 * @param k Number of closest points to return
 * @return Vector of the K closest points to the origin
 */
std::vector<Point> kClosestPoints(std::vector<Point>& points, int k);
