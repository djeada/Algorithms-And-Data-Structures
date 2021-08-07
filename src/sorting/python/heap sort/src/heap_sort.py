import random

# Time complexity O(nlogn)
def heapsort_v1(array):
    def parent(i):
        return i >> 1

    def left_child(i):
        return i << 1

    def right_child(i):
        return (i << 1) + 1

    def heapify(array, curr, offset):

        if curr + offset > len(array):
            return

        heapify(array, left_child(curr), offset)
        heapify(array, right_child(curr), offset)

        if curr > 1 and array[curr + offset - 1] < array[parent(curr) + offset - 1]:
            array[curr + offset - 1], array[parent(curr) + offset - 1] = (
                array[parent(curr) + offset - 1],
                array[curr + offset - 1],
            )

    for i in range(len(array)):
        heapify(array, 1, i)

    return array
