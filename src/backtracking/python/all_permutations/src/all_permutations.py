"""
We want to find all possible permutations of the given list. 
In this approach, an algorithmic technique, known as backtracking was used.

Iterates across each branch of a state space tree using DFS.
There are precisely len(input list) - len(output list) children in each state.
We reach the end when the size of the input list equals the size of the output list.
"""

# Time complexity: O(n! * n)
def all_permutations(input_list):
    def _all_permutations(input_list, output_list, indices_used, result):

        if len(output_list) == len(input_list):
            result.append(output_list.copy())
            return

        for i in range(len(input_list)):
            if not i in indices_used or not indices_used[i]:
                output_list.append(input_list[i])
                indices_used[i] = True
                _all_permutations(input_list, output_list, indices_used, result)
                output_list.pop()
                indices_used[i] = False

    result = list()

    _all_permutations(input_list, list(), dict(), result)

    return result
