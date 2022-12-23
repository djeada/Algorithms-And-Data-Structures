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

    for i in range(len(array) - 1, 0, -1):
        index = random.randint(0, i)
        if index != i:
            array[index] ^= array[i]
            array[i] ^= array[index]
            array[index] ^= array[i]

    return array
