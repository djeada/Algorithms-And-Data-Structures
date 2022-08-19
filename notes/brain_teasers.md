## Rules of thumb when solving a programming 

### General
* If a problem is unfamiliar, start with brute force solution.
* Write unit tests; they will be useful when optimizing your implementation.
* Always take into account hash tables (dictionaries) with access in O(1) time complexity.
* To increase speed, consider what information you can store to save time. Use auxiliary data structures to improve time complexity. 

### Arrays
* Try sorting first.
* If the array is sorted, consider binary search.
* Use two pointer technique.

### Strings
* If you have a large number of strings, consider putting them in a prefix tree / trie.

### Graphs and trees
* Many problems can be treated as graph problems and/or traversed using breadth-first or depth-first traversal.
* Consider using a stack if the problem involves parsing or traversals.
* Consider heaps whenever you need to take the minimum or maximum of a dynamic collection.
