import random

# Time complexity O(n^2)
def selectionsort_v1(array):

    for i in range(len(array)):
        i_min = i

        for j in range(i + 1, len(array)):
            if array[j] < array[i_min]:
                i_min = j

        array[i], array[i_min] = array[i_min], array[i]

    return array
