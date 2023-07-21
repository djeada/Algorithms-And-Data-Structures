"""
Randomize an array of integers in place.
Ensure that no two integers are in the same position as they were in the original array.
"""
import random
from typing import List


def randomize_array(array: List[int]) -> List[int]:
    """
    Randomize an array of integers in place.
    Ensure that no two integers are in the same position as they were in the original array.
    :param array: List of integers to randomize.
    :return: Randomized list of integers.
    """
    n = len(array)
    # Check if all elements are identical or array is of length 1
    if n == 1 or all(x == array[0] for x in array):
        return array
    else:
        new_array = array.copy()  # Create a copy of the array so we don't mutate the original
        for i in range(n):
            # Select a random index that's not equal to the current one
            swap_with = random.choice([x for x in range(n) if x != i and new_array[x] != array[i]])
            # Swap elements
            new_array[i], new_array[swap_with] = new_array[swap_with], new_array[i]
        return new_array
