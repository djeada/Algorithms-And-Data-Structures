from typing import List


def subarray_sum(array: List[int], start: int, end: int) -> int:
    # Initialize the sum to 0
    subarray_sum = 0
    # Iterate through the subarray and add the elements to the sum
    for i in range(start, end):
        subarray_sum += array[i]
    # Return the sum
    return subarray_sum
