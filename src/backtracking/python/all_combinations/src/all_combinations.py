"""
We want to find all possible k long combinations of integers ranging from 0 to n.
In this approach, an algorithmic technique, known as backtracking was used.
"""

# Time complexity: O(C(n,k)) = O((n!/(k! * (n - k)!)))
def all_combinations(n, k):
    def _all_combinations(n, k, output_list, increment, result):

        if k == 0:
            result.append(output_list.copy())
            return

        for i in range(increment, n - k + 2):
            output_list.append(i)
            _all_combinations(n, k - 1, output_list, i + 1, result)
            output_list.pop()

    result = list()

    _all_combinations(n, k, list(), 1, result)

    return result
