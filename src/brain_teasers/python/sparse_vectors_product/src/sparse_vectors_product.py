from typing import Dict


def sparse_vectors_product(v1: Dict[int, int], v2: Dict[int, int]) -> int:

    # Initialize the product to 0
    product = 0

    # Iterate through the first vector
    for index, value in v1.items():

        # If the index is in the second vector, add the product of the values to the product
        if index in v2:
            product += value * v2[index]

    # Return the product
    return product
