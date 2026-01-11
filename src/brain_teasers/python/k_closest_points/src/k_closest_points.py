"""Find the K closest points to the origin."""

from __future__ import annotations

import math


def k_closest_points(
    points: list[tuple[int, int]], k: int
) -> list[tuple[int, int]]:
    """
    Return the K closest points to the origin (0, 0).

    Uses Euclidean distance to measure closeness.

    Args:
        points: List of (x, y) coordinate tuples.
        k: Number of closest points to return.

    Returns:
        List of the K closest points to the origin.
    """
    # Create a list of (distance, point) tuples
    distances = [(math.sqrt(x**2 + y**2), (x, y)) for x, y in points]
    # Sort by distance
    distances.sort()
    # Return the K closest points
    return [point for _, point in distances[:k]]
