## Generating all permutations of a list of elements

Given a list of elements, the problem is to generate all possible permutations of these elements.

For example, if the input list is `[1, 2, 3]`, the possible permutations are:

```
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 1, 2]
[3, 2, 1]
```

##  Approach

One approach to solve this problem is to use a backtracking algorithm.

A backtracking algorithm works by starting with an empty list and adding elements to it one at a time, then exploring the resulting permutations, and backtracking (removing the last added element) when it is no longer possible to generate new permutations.

To implement the backtracking algorithm, we can use a recursive function that takes two arguments:

* `input_list`: the list of elements from which the permutations are generated.
* `output_list`: the current permutation being generated.

The function can follow these steps:

* If the length of `output_list` is equal to the length of `input_list`, it means that a permutation of all the elements has been found. In this case, the function can append the permutation to a list of results and return.
* If the length of `output_list` is not equal to the length of `input_list`, the function can enter a loop that enumerates the elements of the input list.
* For each element, the function can check if it is present in the `output_list`. If the element is not present, the function can call itself recursively with `input_list and output_list + [element]` (to add the element to the permutation).
* After the loop, the function can return the list of results.

The time complexity of this approach is $O(n! * n)$, where n is the length of the input list.
