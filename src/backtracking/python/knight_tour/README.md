## All possible Knight’s tours on a chessboard

Given a chessboard of size n x n, find all sequences of moves of a knight on the chessboard such that the knight visits every square only once. The size of the chessboard n is given as input.

## Approach

To solve this problem, we can use a depth-first search algorithm to generate all possible tours of the knight on the chessboard.

The idea is to start from the top-left square of the chessboard, and try all possible moves of the knight from the current position. For each move, we update the chessboard to mark the square as visited, and then call the search function recursively. When all squares on the board have been visited, we add the current tour to the list of tours.

To make the search more efficient, we can use a 2D array to store the state of the chessboard, with None representing an unvisited square and an integer representing the move number of the knight on that square.

To generate the final result, we can use a helper function to transform each tour from a list of tuples representing the squares visited by the knight to a list of integers representing the consecutive moves of the knight on the chessboard.

## Complexity

The time complexity of this solution is O(k^n), where k is the number of possible moves of the knight (8 in this case) and n is the size of the chessboard. The space complexity is O(n^2), as we store the state of the chessboard in a 2D array.