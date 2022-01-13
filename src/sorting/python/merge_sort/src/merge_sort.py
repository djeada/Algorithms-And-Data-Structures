# Time complexity O(n^2)
def mergesort_v1(array):
    def merge(array_a, array_b):
        result = list()

        while len(array_a) + len(array_b) > 0:

            if len(array_b) == 0 or (len(array_a) > 0 and array_a[0] < array_b[0]):
                result.append(array_a[0])
                array_a = array_a[1:]

            else:
                result.append(array_b[0])
                array_b = array_b[1:]

        return result

    n = len(array)

    if n < 2:
        return array

    return merge(mergesort_v1(array[: n // 2]), mergesort_v1(array[n // 2 :]))


# Time complexity O(nlogn)
def mergesort_v2(array):
    def merge(array_a, array_b):
        result = list()
        index_a = index_b = 0

        while len(array_a) + len(array_b) > index_a + index_b:

            if len(array_b) <= index_b or (
                len(array_a) > index_a and array_a[index_a] < array_b[index_b]
            ):
                result.append(array_a[index_a])
                index_a += 1

            else:
                result.append(array_b[index_b])
                index_b += 1

        return result

    n = len(array)

    if n < 2:
        return array

    return merge(mergesort_v2(array[: n // 2]), mergesort_v2(array[n // 2 :]))
