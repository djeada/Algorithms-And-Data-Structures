#include "k_closest_points.h"
#include "gtest/gtest.h"
#include <algorithm>

// Helper to check if two vectors of points contain the same points (order independent)
bool containsSamePoints(std::vector<Point>& a, std::vector<Point>& b) {
    if (a.size() != b.size()) return false;
    
    auto distanceCompare = [](const Point& p1, const Point& p2) {
        int d1 = p1.x * p1.x + p1.y * p1.y;
        int d2 = p2.x * p2.x + p2.y * p2.y;
        if (d1 != d2) return d1 < d2;
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y;
    };
    
    std::sort(a.begin(), a.end(), distanceCompare);
    std::sort(b.begin(), b.end(), distanceCompare);
    
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].x != b[i].x || a[i].y != b[i].y) return false;
    }
    return true;
}

TEST(KClosestPointsTest, BasicExample) {
    std::vector<Point> points = {{1, 2}, {3, 4}, {-1, -2}, {-3, -4}};
    auto result = kClosestPoints(points, 2);
    std::vector<Point> expected = {{1, 2}, {-1, -2}};
    EXPECT_TRUE(containsSamePoints(result, expected));
}

TEST(KClosestPointsTest, ThreeClosest) {
    std::vector<Point> points = {{1, 1}, {1, 2}, {3, 4}, {-1, -2}, {-3, -4}};
    auto result = kClosestPoints(points, 3);
    std::vector<Point> expected = {{1, 1}, {1, 2}, {-1, -2}};
    EXPECT_TRUE(containsSamePoints(result, expected));
}

TEST(KClosestPointsTest, KEqualsSize) {
    std::vector<Point> points = {{1, 2}, {3, 4}};
    auto result = kClosestPoints(points, 2);
    EXPECT_EQ(result.size(), 2u);
}

TEST(KClosestPointsTest, KGreaterThanSize) {
    std::vector<Point> points = {{1, 2}, {3, 4}};
    auto result = kClosestPoints(points, 10);
    EXPECT_EQ(result.size(), 2u);
}

TEST(KClosestPointsTest, KIsZero) {
    std::vector<Point> points = {{1, 2}, {3, 4}};
    auto result = kClosestPoints(points, 0);
    EXPECT_TRUE(result.empty());
}

TEST(KClosestPointsTest, SinglePoint) {
    std::vector<Point> points = {{1, 1}};
    auto result = kClosestPoints(points, 1);
    EXPECT_EQ(result.size(), 1u);
    EXPECT_EQ(result[0].x, 1);
    EXPECT_EQ(result[0].y, 1);
}

TEST(KClosestPointsTest, OriginPoint) {
    std::vector<Point> points = {{0, 0}, {1, 1}, {2, 2}};
    auto result = kClosestPoints(points, 1);
    EXPECT_EQ(result.size(), 1u);
    EXPECT_EQ(result[0].x, 0);
    EXPECT_EQ(result[0].y, 0);
}
