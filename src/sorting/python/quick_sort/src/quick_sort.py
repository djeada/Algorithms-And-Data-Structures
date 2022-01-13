import random

# Time complexity O(nlogn)
# in-place 2-way partition
def quicksort_v1(array):
    def _quicksort(array, start, stop):

        if stop - start < 2:
            return

        i = random.randint(start, stop - 1)
        array[i], array[stop - 1] = array[stop - 1], array[i]
        i = partition(array, start, stop)
        _quicksort(array, start, i)
        _quicksort(array, i + 1, stop)

    def partition(array, start, stop):
        i = start
        j = stop - 2
        key = array[stop - 1]

        while i <= j:
            if array[i] <= key:
                i += 1
            elif array[j] >= key:
                j -= 1
            else:
                array[i], array[j] = array[j], array[i]
                i += 1
                j -= 1
        array[i], array[stop - 1] = array[stop - 1], array[i]
        return i

    _quicksort(array, 0, len(array))
    return array


# Time complexity O(nlogn)
# in-place 3-way partition
def quicksort_v2(array):
    def _quicksort(array, start, stop):

        if stop - start < 2:
            return

        key = array[random.randint(start, stop - 1)]
        index_1 = index_2 = start
        index_3 = stop

        while index_2 < index_3:
            if array[index_2] < key:
                array[index_2], array[index_1] = array[index_1], array[index_2]
                index_1 += 1
                index_2 += 1

            elif array[index_2] == key:
                index_2 += 1

            else:
                index_3 -= 1
                array[index_2], array[index_3] = array[index_3], array[index_2]

        _quicksort(array, start, index_1)
        _quicksort(array, index_3, stop)

    _quicksort(array, 0, len(array))
    return array
