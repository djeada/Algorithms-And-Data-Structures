from typing import List


def product_of_array_except_self(arr: List[int]) -> List[int]:
    # Initialize the result array with all 1s
    result = [1] * len(arr)
    # Calculate the product of all elements to the left of each index
    left_product = 1
    for i in range(len(arr)):
        result[i] *= left_product
        left_product *= arr[i]
    # Calculate the product of all elements to the right of each index
    right_product = 1
    for i in range(len(arr) - 1, -1, -1):
        result[i] *= right_product
        right_product *= arr[i]
    return result
