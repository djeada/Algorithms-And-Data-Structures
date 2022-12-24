from typing import List, Tuple
import math


def k_closest_points(points: List[Tuple[int, int]], K: int) -> List[Tuple[int, int]]:
    """Return the K closest points to the origin."""
    # Create a list of the distances from the origin
    distances = [(math.sqrt(x ** 2 + y ** 2), (x, y)) for x, y in points]
    # Sort the list of distances
    distances.sort()
    # Return the K closest points
    return [point for _, point in distances[:K]]
