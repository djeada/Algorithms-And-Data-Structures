"""Randomize an array ensuring no element stays in its original position."""

from __future__ import annotations

import random
from collections import Counter


def randomize_array(array: list[int]) -> list[int]:
    """
    Randomize an array of integers.

    Ensures that no element remains in its original position (when possible).

    Args:
        array: List of integers to randomize.

    Returns:
        A new randomized list of integers.
    """
    n = len(array)
    # Nothing can move if there is at most one element or all are identical
    if n <= 1 or all(x == array[0] for x in array):
        return array.copy()

    counts = Counter(array)
    max_count = max(counts.values())

    if 2 * max_count <= n:
        # A derangement by value exists. Group equal values together (random
        # order inside each group) and rotate by a random shift in
        # [max_count, n - max_count]; equal values are never mapped together.
        order = list(range(n))
        random.shuffle(order)
        order.sort(key=lambda idx: array[idx])
        shift = random.randint(max_count, n - max_count)
        result = [None] * n
        for k in range(n):
            result[order[k]] = array[order[(k + shift) % n]]
        return result

    # Too many duplicates for a full derangement: use a random cyclic
    # permutation (Sattolo), which at least moves every position.
    indices = list(range(n))
    for i in range(n - 1, 0, -1):
        j = random.randrange(i)
        indices[i], indices[j] = indices[j], indices[i]
    return [array[indices[i]] for i in range(n)]
