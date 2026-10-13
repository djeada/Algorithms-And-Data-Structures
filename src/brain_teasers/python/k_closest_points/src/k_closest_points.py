"""Find the K closest points to the origin."""

from __future__ import annotations


def k_closest_points(points: list[tuple[int, int]], k: int) -> list[tuple[int, int]]:
    """
    Return the K closest points to the origin (0, 0).

    Uses Euclidean distance to measure closeness.

    Args:
        points: List of (x, y) coordinate tuples.
        k: Number of closest points to return.

    Returns:
        List of the K closest points to the origin.
    """
    if k <= 0:
        return []
    # Squared integer distance avoids floating-point rounding for large values
    distances = [(x * x + y * y, (x, y)) for x, y in points]
    # Sort by distance
    distances.sort()
    # Return the K closest points
    return [point for _, point in distances[:k]]
