"""Compute the dot product of two sparse vectors."""

from __future__ import annotations


def sparse_vectors_product(v1: dict[int, int], v2: dict[int, int]) -> int:
    """
    Compute the dot product of two sparse vectors.

    Sparse vectors are represented as dictionaries mapping indices to values.
    Only non-zero values are stored.

    Args:
        v1: First sparse vector (index -> value).
        v2: Second sparse vector (index -> value).

    Returns:
        The dot product of the two vectors.
    """
    product = 0

    for index, value in v1.items():
        if index in v2:
            product += value * v2[index]

    return product
