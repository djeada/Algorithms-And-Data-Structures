# Dynamic Programming

Dynamic Programming (DP) is a way to solve complex problems by breaking them into smaller, easier problems. Instead of solving the same small problems again and again, DP stores their solutions in a structure like an array, table, or map. This avoids wasting time on repeated calculations and makes the process much faster and more efficient.

The main opportunity for DP is repeated work. When different choices lead to the same subproblem, solve that state once and reuse its result. The benefit depends on having fewer distinct states than recursive calls in the naive solution.

DP needs a state definition that contains everything needed to solve a subproblem and a recurrence that combines previously solved states. Optimization problems require optimal substructure; counting and feasibility problems combine counts or Boolean answers instead. Overlapping subproblems make storing these results useful. With a valid dependency order, each state can be computed once.

Check both the recurrence and the amount of overlap before adding a cache. Reuse can save substantial work, but a large state space can still make a DP solution expensive.

This method was introduced by Richard Bellman in the 1950s and has become a valuable tool in areas like computer science, economics, and operations research. It has been used to solve problems that would otherwise take too long by turning slow, exponential-time algorithms into much faster polynomial-time solutions. DP is used in practice for tackling real-world optimization challenges.

DP appears in routing, scheduling, matching, compression, and resource allocation. In each setting, the central task is to identify which partial results can be reused without losing information needed for correctness.

## Principles

Two properties explain when dynamic programming is useful, especially for optimization:

A useful mindset here is to treat DP like a story you’re building: first you define the “chapters” (subproblems), then you decide how chapters connect (transitions), and finally you make sure you never rewrite a chapter you already finished (storage).

### 1. Optimal Substructure

A problem has optimal substructure when the best solution to the overall problem can be built from the best solutions to its smaller parts. In simple terms, solving the smaller pieces perfectly ensures the entire problem is solved perfectly too.

Formally, if the optimal solution $S_n$ for a problem of size $n$ can be created by combining the optimal solutions $S_k$ for smaller sizes $k < n$, then the problem is said to exhibit optimal substructure.

Why this matters: DP depends on trust. You’re trusting that if you make the best choice for a subproblem, you’re not accidentally ruining the final answer. If that trust holds, you can safely “lock in” sub-results. If it doesn’t, DP will confidently assemble a solution that looks logical but isn’t globally optimal.

Mathematical Representation:

Consider a problem where we want to find the optimal value $V(n)$ for a given parameter $n$. If there exists a function $f$ such that:

$ V(n) = \min_{1 \le k < n} f(V(k), V(n-k)), \qquad n \ge 2 $

then this is one possible form of an optimal-substructure recurrence, provided the state is sufficient and the combination accounts for every valid choice and its cost. It is not a universal DP formula: many problems need several state parameters or different transitions. Base cases must be defined separately.

Example: Shortest Path in Graphs

In the context of graph algorithms, suppose we want to find the shortest path from vertex $A$ to vertex $C$. If $B$ is an intermediate vertex on the shortest path from $A$ to $C$, then the two segments of that path are shortest paths between their respective endpoints. Otherwise, replacing a segment with a shorter one would improve the whole route. This reasoning assumes finite shortest-path distances; relevant negative cycles can make a shortest walk undefined.

This example also highlights a common “do”: make sure you can clearly explain how a best solution is composed. If you can’t describe how the big answer is built from smaller best answers, your “DP solution” is probably just a recursive solution with a table taped to it.

### 2. Overlapping Subproblems

A problem has overlapping subproblems when it can be divided into smaller problems that are solved multiple times. This happens when the same subproblem appears in different parts of the solution process. In a straightforward recursive approach, this leads to solving the same subproblem repeatedly, which wastes time and resources. Dynamic Programming addresses this by solving each subproblem once and storing the result for reuse, improving efficiency significantly.

A valid recurrence establishes correctness; repeated subproblems explain why caching helps. Without repetition, storing every intermediate result may add memory overhead without reducing the amount of computation.

Mathematical Representation:

Let $S(n)$ be the set of subproblems for problem size $n$. If there exists $s \in S(n)$ such that $s$ appears in $S(k)$ for multiple $k$, the problem has overlapping subproblems.

Example: Fibonacci Numbers

The recursive computation of Fibonacci numbers $F(n) = F(n - 1) + F(n - 2)$ involves recalculating the same Fibonacci numbers multiple times. For instance, to compute $F(5)$, we need to compute $F(4)$ and $F(3)$, both of which require computing $F(2)$ and $F(1)$ multiple times.

Fibonacci makes the overlap easy to see: the same values are recomputed in separate recursive branches. Memoization preserves the recurrence while eliminating those repeated computations.

## Techniques

There are two primary methods for implementing dynamic programming algorithms:

You can think of these as two different writing styles for the same story. Memoization writes chapters only when needed (and bookmarks them). Tabulation writes every chapter in order, from page 1 onward. Both can end at the same ending; the difference is how they get there.

### 1. Memoization (Top-Down Approach)

> **First step:** Write the function signature with exactly the parameters that define a subproblem, and say in one sentence what it returns. Write the base cases before the recursive case, and make sure every argument that changes between calls is part of the cache key.

Memoization is a technique used to optimize recursive problem-solving by storing the results of solved subproblems in a data structure, such as a hash table or an array. When the algorithm encounters a subproblem, it first checks if the result is already stored. If it is, the algorithm simply retrieves the cached result instead of recomputing it. This approach reduces redundant calculations, making the solution process faster and more efficient.

A “do” for memoization: keep the recursion because it matches the problem’s natural definition, but make every subproblem cheap after the first time. A “don’t”: let your memo structure accidentally depend on hidden state (like mutable defaults or changing globals) in a way that makes results inconsistent.

Algorithm Steps:

1. Identify the parameters that uniquely define a subproblem and create a recursive function using these parameters.
2. Establish base cases to terminate recursion.
3. Initialize a data structure to store computed subproblem results.
4. Before computing a subproblem, check if its result is already stored.
5. If not already computed, compute the subproblem's result and store it.

Example: Computing Fibonacci Numbers with Memoization

```python
def fibonacci(n, memo=None):
    if n < 0:
        raise ValueError("n must be non-negative")
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n <= 1:
        memo[n] = n
    else:
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]
```

Analysis:

- Time Complexity: $O(n)$, since each number up to $n$ is computed once.
- Space complexity: $O(n)$ stored values and an $O(n)$ recursion stack. Python's recursion limit can prevent this version from handling large $n$ even when sufficient heap memory is available.

These Fibonacci examples assume integer $n$ and count arithmetic operations as constant time. Exact Fibonacci numbers grow to $\Theta(n)$ bits, so arbitrary-precision arithmetic adds cost; $O(n)$ additions is not the same as $O(n)$ bit operations.

One practical note when learning: top-down DP is often easier to write correctly first, because you start from the real question (“solve $n$”) and naturally reach for smaller questions. If you can write the recurrence cleanly, memoization is usually your fastest path to a working solution.

### 2. Tabulation (Bottom-Up Approach)

> **First step:** Decide the table's dimensions and what one cell means, then find which cells each cell reads from. Choose loop directions so those cells are always filled first, and note which cell holds the final answer.

Tabulation is a technique that solves a problem by working from the smallest subproblems up to the larger ones in a step-by-step, iterative way. It stores the solutions to these subproblems in a table, often an array, and uses these stored values to solve bigger subproblems until the final solution is reached. Unlike memoization, which works recursively and checks if a solution is already computed, tabulation systematically builds the solution from the ground up. This method is efficient and avoids the overhead of recursive calls.

The “why” behind tabulation is control: you decide the exact order states are computed, and you avoid recursion limits and call overhead. Fill the table in dependency order. Do not fill it in a convenient order that violates dependencies, because then you’ll be reading values that aren’t valid yet.

Algorithm Steps:

1. Initialize the table by setting up a structure to store the results of subproblems, and ensure that base cases are properly initialized to handle the simplest instances of the problem.
2. Iterative computation is carried out using loops to fill the table, making sure that each subproblem is solved in the correct order before being used to solve larger subproblems.
3. Construct the solution by referencing the filled table, using the stored values to derive the final solution to the original problem efficiently.

Example: Computing Fibonacci Numbers with Tabulation

```python
def fibonacci(n):
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    fib_table = [0] * (n + 1)
    fib_table[0], fib_table[1] = 0, 1
    for i in range(2, n + 1):
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2]
    return fib_table[n]
```

Analysis:

- The time complexity is $O(n)$, since the algorithm iterates from 2 to $n$, computing each Fibonacci number sequentially.
- The space complexity is $O(n)$, due to the storage required for the table that holds the Fibonacci numbers up to $n$.

A nice way to make tabulation feel natural is to ask: “What’s the smallest thing I must know before I can know the next thing?” That question basically is the loop order.

### Comparison of Memoization and Tabulation

| Aspect               | Memoization (Top-Down)                                    | Tabulation (Bottom-Up)                                |
| -------------------- | --------------------------------------------------------- | ----------------------------------------------------- |
| Approach         | Recursive                                                 | Iterative                                             |
| Storage          | Stores solutions as needed                                | Pre-fills table with solutions to all subproblems     |
| Overhead         | Function call overhead due to recursion                   | Minimal overhead due to iteration                     |
| Flexibility      | May be easier to implement for complex recursive problems | May require careful ordering of computations          |
| Space Efficiency | Potentially higher due to recursion stack and memoization | Can be more space-efficient with careful table design |

If you’re choosing between them, a simple rule of thumb is: start with memoization to get the recurrence right, then switch to tabulation when you want tighter performance or cleaner memory control.

## Implementation Techniques

Dynamic programming problems are often formulated using recurrence relations, which express the solution to a problem in terms of its subproblems.

A recurrence specifies how the answer for a state depends on other states. Define that relationship, its base cases, and a valid evaluation order before deciding how to store the results.

### Formulating Recurrence Relations

> **First step:** Look at the last decision made in an optimal solution, such as whether the last characters match or whether the last item is taken. Each possible last decision becomes one term of the recurrence, and the empty or smallest input becomes the base case.

Example: Longest Common Subsequence (LCS)

Given two sequences $X = x_1, x_2, ..., x_m$ and $Y = y_1, y_2, ..., y_n$, let $LCS(i,j)$ be the LCS length of their first $i$ and $j$ elements. The recurrence uses one-based character indices and a zero row and column for empty prefixes:

$$ LCS(i, j) = \begin{cases}
0 & \text{if } i = 0 \text{ or } j = 0 \\
LCS(i - 1, j - 1) + 1 & \text{if } x_i = y_j \\
\max(LCS(i - 1, j), LCS(i, j - 1)) & \text{if } x_i \neq y_j
\end{cases} $$

Implementation:

We can implement the LCS problem using either memoization or tabulation. With tabulation, we build a two-dimensional table $LCS[0..m][0..n]$ iteratively.

- The time complexity is $O(mn)$, as the algorithm processes a grid or matrix of size $m \times n$, iterating through each cell.
- The space complexity is $O(mn)$, due to the table storing intermediate results, but this can be reduced to $O(n)$ by optimizing the storage to only keep necessary data for the current and previous rows.

The reason LCS is such a beloved DP example is that the “choices” are easy to explain: if characters match, you take the diagonal; if they don’t, you take the best of left/top. That clear decision structure is exactly what good DP feels like: simple local rules that reliably build a global answer.

### State Representation

> **First step:** Write the state in words, for example "dp[i][w] is the best value using the first i items with capacity w", and check that two situations with the same state really have the same best future. If they do not, the state is missing information and needs another dimension.

Properly defining the state is crucial for dynamic programming.

- State variables are the parameters that uniquely define each subproblem, helping to break down the problem into smaller, manageable components.
- State transition refers to the rules or formulas that describe how to move from one state to another, typically using the results of smaller subproblems to solve larger ones.

Think of state design like labeling drawers in a workshop. If the labels are precise, you can find what you need instantly and build bigger things confidently. If the labels are vague, you’ll keep opening drawers, guessing, and making mistakes, even if the math is technically “there.”

Example: 0/1 Knapsack Problem

- Assume positive integer weights, non-negative integer capacity, and at most one copy of each item. Initialize $dp[0][w]=0$ and $dp[i][0]=0$.
- The problem statement focuses on selecting $n$ items, each with a weight $w_i$ and value $v_i$, while ensuring the total weight stays within the knapsack capacity $W$, in order to maximize the total value.
- In state representation, $dp[i][w]$ represents the maximum value that can be achieved using the first $i$ items with a total weight capacity of $w$.
- State Transition:

$$ dp[i][w] = \begin{cases}
dp[i - 1][w] & \text{if } w_i > w \\
\max(dp[i - 1][w], dp[i - 1][w - w_i] + v_i) & \text{if } w_i \leq w
\end{cases} $$

Implementation:

We fill the table $dp[0..n][0..W]$ iteratively based on the state transition.

- The time complexity is $O(nW)$, where $n$ is the number of items and $W$ is the capacity of the knapsack, as the algorithm iterates through both items and weights.
- The space complexity is $O(nW)$, but this can be optimized to $O(W)$ because each row in the table depends only on the values from the previous row, allowing for space reduction.

The $O(nW)$ bound is pseudopolynomial: it is polynomial in the numeric capacity $W$, but not in the number of bits needed to encode $W$. DP does not always turn exponential problems into polynomial-time algorithms.

A key “do” here is to interpret your state in plain language. If you can’t say what `dp[i][w]` means in one sentence, debugging will be painful. A key “don’t” is mixing meanings (for example, letting `w` sometimes mean “remaining capacity” and sometimes mean “used weight”), that’s how DP tables become nonsense.

## Advanced Concepts

### Memory Optimization

> **First step:** Get the full-table version working first, then mark exactly which earlier cells each cell reads. If it reads only the previous row, two rows are enough, and a single array often works when the loop direction guarantees that old values are read before they are overwritten.

In some cases, we can optimize space complexity by noticing dependencies between states.

This is where DP graduates from “works” to “works well.” Once the recurrence is correct, you can ask: “Do I truly need all previous states, or only a slice of them?” Many DP solutions only depend on the previous row, previous column, or a small window, so storing everything is optional.

Example: Since $dp[i][w]$ depends only on $dp[i - 1][w]$ and $dp[i - 1][w - w_i]$, we can use a one-dimensional array and update it in reverse.

```python
def knapsack(weights, values, capacity):
    best = [0] * (capacity + 1)
    for weight, value in zip(weights, values):
        for remaining in range(capacity, weight - 1, -1):
            best[remaining] = max(
                best[remaining], best[remaining - weight] + value
            )
    return best[capacity]
```

Here `weights` and `values` must have the same length, weights must be positive integers, and capacity must be a non-negative integer. Keeping only values is enough to return the optimum; reconstructing the chosen items requires additional predecessor information or recomputation.

One important “do/don’t” hidden in this snippet is the reverse loop. Updating from high to low prevents using the same item multiple times in a single iteration. If you go forward, you silently switch the problem you’re solving.

### Dealing with Non-Overlapping Subproblems

If a problem has optimal substructure but does not have overlapping subproblems, it is often better to use Divide and Conquer instead of Dynamic Programming. Divide and Conquer works by breaking the problem into independent subproblems, solving each one separately, and then combining their solutions. Since there are no repeated subproblems to reuse, storing intermediate results (as in Dynamic Programming) is unnecessary, making Divide and Conquer a more suitable and efficient choice in such cases.

This distinction matters because DP isn’t “better recursion”, it’s “recursion plus reuse.” If there’s nothing to reuse, DP is extra work for no gain. Picking the right paradigm is part of writing efficient algorithms, not just correct ones.

Example: Merge Sort algorithm divides the list into halves, sorts each half, and then merges the sorted halves.

## Common DP Patterns

Most interview DP problems are variations on a small number of shapes. Once you recognize the shape, the state, the transition, and the loop order follow almost mechanically. The sections below cover the shapes behind the most common LeetCode DP questions.

### Linear DP over a Sequence

> **First step:** Write down in words what `dp[i]` means for the prefix ending at position `i`, then list the few earlier indices it can come from. Decide the values for the first one or two positions and whether the answer is `dp[n]` or the best over all `i`.

The simplest DP shape walks along an array or string once, and each position depends on a constant number of earlier positions. Climbing Stairs (LeetCode 70) uses $dp[i] = dp[i-1] + dp[i-2]$ because the last move was either one step or two; the version in the problem list below also allows jumps of three and adds $dp[i-3]$. House Robber (LeetCode 198) either skips house $i$ or robs it on top of the best answer two houses back, so $dp[i] = \max(dp[i-1], dp[i-2] + a_i)$.

Recognize this pattern when the input is processed left to right and each decision only interacts with a short window behind it. House Robber II (LeetCode 213) puts the houses in a circle, which you break by running the linear version twice, once without the first house and once without the last. Decode Ways (LeetCode 91) adds $dp[i-1]$ when the single digit is 1 to 9 and $dp[i-2]$ when the two-digit number is 10 to 26. Word Break (LeetCode 139) sets $dp[i]$ to true when some dictionary word ends at position $i$ and $dp$ is true where that word starts.

Longest Valid Parentheses (LeetCode 32) stores the length of the longest valid substring ending at $i$. When s[i] is ')' and the character at $j = i - dp[i-1] - 1$ is '(', then $dp[i] = dp[i-1] + 2 + dp[j-1]$, taking $dp[j-1]$ as 0 when $j = 0$, and the answer is the maximum over all $i$.

```python
def rob_line(houses):
    prev2, prev1 = 0, 0                  # best up to i-2 and up to i-1
    for amount in houses:
        prev2, prev1 = prev1, max(prev1, prev2 + amount)
    return prev1

def rob_circle(houses):                  # LeetCode 213
    if len(houses) == 1:
        return houses[0]
    return max(rob_line(houses[1:]), rob_line(houses[:-1]))
```

These run in $O(n)$ time and $O(1)$ extra space when each state looks back a constant number of steps, while Word Break looks back up to the longest word length $L$ and costs about $O(n L^2)$ when each candidate word is sliced and looked up in a hash set. The most common mistake is in Decode Ways, where a '0' cannot be decoded on its own and a pair starting with '0', such as "06", is not a valid two-digit code.

### Kadane's Algorithm and Running Best

> **First step:** Define the local state as the best subarray that ends exactly at index `i`, because that is what makes a one-step recurrence possible. Keep a separate global best, since the answer can end anywhere.

Maximum Subarray (LeetCode 53) asks for the largest sum of a contiguous subarray. Let $cur_i$ be the best sum of a subarray that ends exactly at index $i$. That subarray either extends the best one ending at $i-1$ or starts fresh at $i$, so $cur_i = \max(a_i, cur_{i-1} + a_i)$, and the answer is the largest $cur_i$ seen, not the last one.

Maximum Product Subarray (LeetCode 152) needs two running values, because multiplying by a negative number turns the smallest product into the largest. Track both the maximum and the minimum product ending at $i$, and swap them when $a_i$ is negative. Recognize this family by the word "contiguous" next to "maximum" or "minimum".

```python
def max_subarray(nums):                  # LeetCode 53
    cur = best = nums[0]
    for x in nums[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best

def max_product(nums):                   # LeetCode 152
    hi = lo = best = nums[0]
    for x in nums[1:]:
        if x < 0:
            hi, lo = lo, hi
        hi = max(x, hi * x)
        lo = min(x, lo * x)
        best = max(best, hi)
    return best
```

Both run in $O(n)$ time and $O(1)$ space. The most common mistake is starting `best` at 0, which returns 0 for an array whose elements are all negative.

### 0/1 and Unbounded Knapsack

> **First step:** Decide whether each item may be used once or any number of times, because that fixes the direction of the capacity loop. Then decide whether a cell holds a Boolean, a count, or a minimum or maximum, and initialize `dp[0]` and the other cells to match.

The one-dimensional knapsack in Memory Optimization iterates capacity from high to low, and that direction is what makes it 0/1. When `best[c]` reads `best[c - w]`, that cell still holds the value from before the current item was considered. Iterating capacity from low to high means `best[c - w]` may already include the current item, so the item can be taken again, which is exactly the unbounded knapsack.

Partition Equal Subset Sum (LeetCode 416) is 0/1 subset sum: an odd total is impossible, otherwise ask whether some subset reaches half the total. Target Sum (LeetCode 494) becomes 0/1 counting after a little algebra. If $P$ is the sum of the numbers given a plus sign and $S$ is the total, then $P - (S - P) = t$, so $P = (S + t)/2$ and you count subsets with that sum. Coin Change (LeetCode 322) and Perfect Squares (LeetCode 279) are unbounded minimization with $dp[c] = \min(dp[c], dp[c - x] + 1)$, where every cell except $dp[0] = 0$ starts at infinity.

```python
def can_partition(nums):                 # LeetCode 416, 0/1, Boolean
    total = sum(nums)
    if total % 2:
        return False
    target = total // 2
    reach = [True] + [False] * target
    for x in nums:
        for c in range(target, x - 1, -1):    # downward: each number once
            reach[c] = reach[c] or reach[c - x]
    return reach[target]

def coin_change(coins, amount):          # LeetCode 322, unbounded, minimum
    INF = float("inf")
    dp = [0] + [INF] * amount
    for coin in coins:
        for c in range(coin, amount + 1):     # upward: coin can be reused
            dp[c] = min(dp[c], dp[c - coin] + 1)
    return dp[amount] if dp[amount] != INF else -1
```

Both run in $O(n T)$ time and $O(T)$ space, where $n$ is the number of items and $T$ the target sum or amount. The most common mistake in Target Sum is forgetting to return 0 when $S + t$ is odd or $|t| > S$, since the subset target is then not a valid non-negative integer.

### Counting Combinations Versus Permutations

> **First step:** Decide whether [1, 2] and [2, 1] are the same way or two different ways. If they are the same, put the item loop outside; if they are different, put the target loop outside.

Coin Change II (LeetCode 518) and Combination Sum IV (LeetCode 377) look identical: count the ways to reach a target using numbers that can be reused. The only difference is whether order matters, and that is controlled entirely by which loop is on the outside.

With coins in the outer loop, each way is built by first deciding how many of the first coin to use, then how many of the second, and so on, so each multiset of coins is counted exactly once. With the amount in the outer loop, $dp[t]$ sums over every possible last element, so 1 + 2 and 2 + 1 are counted as different sequences. Climbing Stairs is the permutation version with steps of 1 and 2.

```python
def count_combinations(coins, amount):   # LeetCode 518, order ignored
    dp = [1] + [0] * amount
    for coin in coins:
        for t in range(coin, amount + 1):
            dp[t] += dp[t - coin]
    return dp[amount]

def count_permutations(nums, target):    # LeetCode 377, order matters
    dp = [1] + [0] * target
    for t in range(1, target + 1):
        for x in nums:
            if x <= t:
                dp[t] += dp[t - x]
    return dp[target]
```

Both take $O(k T)$ time for $k$ choices and target $T$, with $O(T)$ space. The most common mistake is setting $dp[0] = 0$, but the empty selection is the one way to make 0 and every other count is built from it.

### Grid DP

> **First step:** Decide which neighbors can move into a cell, usually the one above and the one to the left, and fill the grid in an order where they are already done, such as row by row. Set the first row, the first column, and any blocked cells explicitly before the main loop.

In grid problems the state is a cell $(i, j)$ and the value is the number of ways, or the best cost, to reach it from the start. Unique Paths (LeetCode 62) sums the top and left neighbors, and Unique Paths II (LeetCode 63) forces blocked cells to 0. Minimum Path Sum (LeetCode 64) takes the smaller of the two neighbors plus the cell's own cost. Triangle (LeetCode 120) is easiest bottom-up: each entry becomes its value plus the smaller of the two entries below it, and the apex ends up holding the answer.

Maximal Square (LeetCode 221) uses a different state: $dp[i][j]$ is the side of the largest all-ones square whose bottom-right corner is $(i, j)$. If the cell is 1, $dp[i][j] = 1 + \min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])$, and the answer is the square of the largest side seen anywhere.

Each row depends only on the row above and on cells already filled in the current row, so a single array of width $n$ is enough. Before the update, `dp[j]` still holds the value from the row above.

```python
def unique_paths_with_obstacles(grid):   # LeetCode 63
    cols = len(grid[0])
    dp = [0] * cols
    dp[0] = 1
    for row in grid:
        for j in range(cols):
            if row[j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j - 1]       # from above plus from the left
    return dp[-1]
```

This takes $O(mn)$ time and $O(n)$ space. The most common mistake is filling the whole first row and first column with 1, which ignores obstacles, since every cell after a blocked cell in the first row or column must be 0.

### Longest Increasing Subsequence

> **First step:** Decide whether you need only the length or the subsequence itself, and whether "increasing" is strict. Strict uses `bisect_left` and non-decreasing uses `bisect_right`, and recovering the subsequence needs parent indices.

Longest Increasing Subsequence (LeetCode 300) has a direct $O(n^2)$ DP. Let $dp[i]$ be the length of the longest increasing subsequence that ends at index $i$; then $dp[i] = 1 + \max dp[j]$ over all $j < i$ with $a_j < a_i$, or 1 if there is no such $j$, and the answer is the largest $dp[i]$.

The faster patience method keeps an array `tails`, where `tails[k]` is the smallest possible last value of an increasing subsequence of length $k + 1$ seen so far. This array is always sorted, so each new value is placed with binary search. It either extends the longest subsequence or replaces the first tail that is greater than or equal to it, which makes that length easier to extend later. Russian Doll Envelopes (LeetCode 354) reduces to this after sorting by width ascending and, for equal widths, height descending.

```python
from bisect import bisect_left

def length_of_lis(nums):                 # LeetCode 300
    tails = []
    for x in nums:
        k = bisect_left(tails, x)        # first tail >= x
        if k == len(tails):
            tails.append(x)
        else:
            tails[k] = x
    return len(tails)
```

The patience method runs in $O(n \log n)$ time and $O(n)$ space. The most common mistake is returning `tails` as the answer subsequence, which it generally is not; to rebuild a real one, record for each element the index that sat at position $k - 1$ when it was placed.

### Two-String DP

> **First step:** Define `dp[i][j]` on prefixes, the first `i` characters of one string and the first `j` of the other, in an (m+1) by (n+1) table whose row 0 and column 0 stand for the empty prefix. Fill those borders first, because most bugs in this family live there.

LCS above is the template for a large family. The cell $dp[i][j]$ looks at the last characters of the two prefixes and at three neighbors: the diagonal (both characters used), the cell above (drop a character of the first string), and the cell to the left (drop a character of the second). Problems differ only in what those moves cost and what the borders hold. Delete Operation for Two Strings (LeetCode 583) is just $m + n$ minus twice the LCS length (LeetCode 1143).

Edit Distance (LeetCode 72) takes the diagonal for free when the characters match, and otherwise 1 plus the minimum of replace (diagonal), delete (above), and insert (left), with borders $dp[i][0] = i$ and $dp[0][j] = j$. Distinct Subsequences (LeetCode 115) counts how many times $t$ appears as a subsequence of $s$: $dp[i][j] = dp[i-1][j]$, plus $dp[i-1][j-1]$ when the characters match, with $dp[i][0] = 1$. Interleaving String (LeetCode 97) stores whether the first $i$ characters of s1 and the first $j$ of s2 can form the first $i + j$ characters of s3.

Wildcard Matching (LeetCode 44) and Regular Expression Matching (LeetCode 10) put the text on one axis and the pattern on the other. In 44, a cell whose pattern character is '*' is true if $dp[i][j-1]$ (the star matches nothing) or $dp[i-1][j]$ (the star absorbs one more character). In 10, a pair such as 'x*' is handled together: $dp[i][j] = dp[i][j-2]$ for zero copies, or $dp[i-1][j]$ when the text character matches x. Row 0 must be computed too, because patterns like "a*b*" match the empty string.

```python
def edit_distance(a, b):                 # LeetCode 72
    m, n = len(a), len(b)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = i                     # delete all of a[:i]
    for j in range(n + 1):
        dp[0][j] = j                     # insert all of b[:j]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j - 1],   # replace
                                   dp[i - 1][j],       # delete
                                   dp[i][j - 1])       # insert
    return dp[m][n]
```

This takes $O(mn)$ time and $O(mn)$ space, which drops to $O(n)$ by keeping two rows or one row plus the saved diagonal value. The most common mistake is mixing table indices with string indices, since $dp[i][j]$ compares a[i - 1] with b[j - 1].

### Interval DP and Palindromes

> **First step:** Define `dp[i][j]` on the range from `i` to `j` and decide what the last action inside that range is, such as matching the two ends or picking a split point. Fill ranges in order of increasing length, starting from ranges of length one or zero as the base case.

Some problems are about a contiguous range whose answer depends on smaller ranges inside it. The table is indexed by both ends, and every range must be computed after the ranges it contains, which is easiest by looping over the length, or by running $i$ downward and $j$ upward from $i$.

Longest Palindromic Subsequence (LeetCode 516) compares the two ends: if $s_i = s_j$ then $dp[i][j] = dp[i+1][j-1] + 2$, otherwise $dp[i][j] = \max(dp[i+1][j], dp[i][j-1])$. Minimum Insertion Steps to Make a String Palindrome (LeetCode 1312, listed below) is $n$ minus that length. Longest Palindromic Substring (LeetCode 5) can use a Boolean table where $pal[i][j]$ is true when the ends match and $pal[i+1][j-1]$ is true, but expanding around each of the $2n - 1$ centers gives the same $O(n^2)$ time with $O(1)$ space.

Burst Balloons (LeetCode 312) is the split-point version. Pad the array with a 1 on each side and let $dp[i][j]$ be the most coins from bursting every balloon strictly between $i$ and $j$. The trick is to choose the balloon $k$ that bursts last in that range, because then its neighbors are exactly $i$ and $j$, and the two sides become independent subproblems.

```python
def max_coins(nums):                     # LeetCode 312
    a = [1] + nums + [1]
    n = len(a)
    dp = [[0] * n for _ in range(n)]
    for length in range(2, n):           # length = j - i
        for i in range(n - length):
            j = i + length
            for k in range(i + 1, j):    # k is the last balloon burst
                dp[i][j] = max(dp[i][j],
                               dp[i][k] + a[i] * a[k] * a[j] + dp[k][j])
    return dp[0][n - 1]
```

With $O(n^2)$ ranges and $O(n)$ split points this takes $O(n^3)$ time and $O(n^2)$ space, which is fine for $n$ up to a few hundred. The most common mistake is choosing the balloon that bursts first, which leaves the neighbors of the remaining balloons unknown.

### State Machine DP for Stock Problems

> **First step:** List the states you can be in at the end of a day, such as holding a share, not holding, or cooling down, and draw the allowed moves between them with their gain or cost. Each move becomes one term of the transition, and every state is updated from yesterday's values.

The Best Time to Buy and Sell Stock family looks like several problems but is one pattern. Each day you are in one of a few states, and buying or selling moves you between them. Keep the best profit for each state, update all of them from the previous day, and the answer is the best not-holding state on the last day.

With unlimited transactions (LeetCode 122) the states are hold and free, with $hold = \max(hold, free - p)$ and $free = \max(free, hold + p)$. A transaction fee (LeetCode 714) subtracts the fee on the selling move. A cooldown (LeetCode 309) adds a third state for the day right after a sale, from which you may not buy. At most $k$ transactions (LeetCode 188, and LeetCode 123 with $k = 2$) gives a hold and a free state for each transaction count.

```python
def max_profit_cooldown(prices):         # LeetCode 309
    hold, sold, rest = float("-inf"), 0, 0
    for p in prices:
        hold, sold, rest = (max(hold, rest - p),   # keep, or buy after a rest day
                            hold + p,              # sell today
                            max(rest, sold))       # idle, cooldown ends
    return max(sold, rest)

def max_profit_k(k, prices):             # LeetCode 188
    buy = [float("-inf")] * (k + 1)
    sell = [0] * (k + 1)
    for p in prices:
        for t in range(1, k + 1):
            buy[t] = max(buy[t], sell[t - 1] - p)
            sell[t] = max(sell[t], buy[t] + p)
    return sell[k]
```

This is $O(n)$ time and $O(1)$ space for a fixed number of states, and $O(nk)$ time with $O(k)$ space for $k$ transactions. The most common mistake is updating one state in place and then reading its new value for another state of the same day, which in the cooldown problem lets you buy the day after selling; assign all states together or use temporaries.

### DP on Trees

> **First step:** Decide what each subtree should return to its parent, often a pair such as "best if this node is used" and "best if it is not". Use a post-order traversal so children are finished first, and keep any answer that cannot be passed upward in a separate variable.

On a tree the subproblems are subtrees, and a post-order DFS already visits them in dependency order, so no explicit table is needed. Each call returns a small tuple of values for its subtree and the parent combines its children's tuples.

House Robber III (LeetCode 337) returns two numbers per node: the best total if this node is robbed, in which case both children must be skipped, and the best total if it is not, in which case each child takes its better option. Binary Tree Maximum Path Sum (LeetCode 124) returns the best path that starts at the node and goes down, which may use at most one child, while a separate global value records paths that bend through the node and use both children. Diameter of Binary Tree (LeetCode 543) has the same shape.

```python
def rob_tree(root):                      # LeetCode 337
    def dfs(node):                       # returns (robbed, skipped)
        if node is None:
            return 0, 0
        l_rob, l_skip = dfs(node.left)
        r_rob, r_skip = dfs(node.right)
        robbed = node.val + l_skip + r_skip
        skipped = max(l_rob, l_skip) + max(r_rob, r_skip)
        return robbed, skipped
    return max(dfs(root))

def max_path_sum(root):                  # LeetCode 124
    best = float("-inf")
    def down(node):                      # best path from node going down
        nonlocal best
        if node is None:
            return 0
        left = max(down(node.left), 0)   # drop negative branches
        right = max(down(node.right), 0)
        best = max(best, node.val + left + right)
        return node.val + max(left, right)
    down(root)
    return best
```

Both visit each node once, so they take $O(n)$ time and $O(h)$ stack space for tree height $h$. The most common mistake in LeetCode 124 is returning the bent path through both children to the parent, which stops being a valid path once it continues upward.

### Bitmask DP

> **First step:** Check that the number of items is small, about 20 or fewer, and decide what one bit means, usually "this item is already used". Then decide what the state needs besides the mask, such as the last item visited or how full the current group is.

When the state must remember exactly which items have been used and $n$ is small, encode that set as an integer whose bit $i$ is 1 when item $i$ is used. There are $2^n$ masks, about a million for $n = 20$, and each transition adds one item whose bit is still 0, so a larger mask always comes after a smaller one.

Partition to K Equal Sum Subsets (LeetCode 698) fills groups one at a time. The total of the used numbers modulo the group size tells you how full the current group is, so a mask only needs a reachable flag. Minimum Number of Work Sessions to Finish the Tasks (LeetCode 1986) stores a pair per mask, the fewest sessions and the smallest load of the last session, compared in that order. Find the Shortest Superstring (LeetCode 943) uses $dp[mask][last]$, the classic travelling salesman state.

```python
def can_partition_k(nums, k):            # LeetCode 698
    total = sum(nums)
    if total % k:
        return False
    side, n = total // k, len(nums)
    reachable = [False] * (1 << n)
    filled = [0] * (1 << n)              # load of the current group
    reachable[0] = True
    for mask in range(1 << n):
        if not reachable[mask]:
            continue
        for i in range(n):
            if mask & (1 << i) or filled[mask] + nums[i] > side:
                continue                 # already used, or group overflows
            nxt = mask | (1 << i)
            reachable[nxt] = True
            filled[nxt] = (filled[mask] + nums[i]) % side
    return reachable[(1 << n) - 1]
```

This takes $O(2^n n)$ time and $O(2^n)$ space. The most common mistake is operator precedence in C++ and Java, where `mask & (1 << i) == 0` performs the comparison before the AND, so always write `(mask & (1 << i)) == 0`.

## Common Terms

These terms show up constantly around DP because DP is really about breaking a big idea into structured pieces. The more comfortable you are with these building blocks, the faster DP problems start to feel like patterns instead of puzzles.

### Recursion

A process is called recursion when a function solves a problem by calling itself, either directly or indirectly, with a smaller instance of the same problem. This continues until the function reaches a base case, which is a condition that stops further recursive calls and provides a straightforward solution. Recursion is useful for problems that can naturally be divided into similar smaller subproblems.

Mathematical Perspective:

A recursive function $f(n)$ satisfies:

$$ f(n) = g(f(k), f(n - k)) $$

for some function $g$ and smaller subproblem size $k < n$.

Example: Computing $n!$:

$$ n! = n \times (n - 1)! $$

with base case $0! = 1$.

In DP, recursion is often your first draft: it expresses the logic cleanly. Then DP adds the missing ingredient: remembering what you already solved.

### Subset

For a set $S$, a subset $T$ is a set where every element of $T$ is also an element of $S$. Denoted as $T \subseteq S$.

Mathematical Properties:

- The total subsets of a set with $n$ elements is $2^n$, as each element can either be included or excluded from a subset.
- The power set of a set $S$, denoted as $\mathcal{P}(S)$, is the set of all possible subsets of $S$, including the empty set and $S$ itself.

Relevance to DP:

Subsets often represent different states or configurations in combinatorial problems, such as the subset-sum problem.

The “why you should care” is right in the number $2^n$: subsets explode fast. DP is often the difference between “impossible after n=40” and “fine for n=10,000,” depending on the structure.

### Subarray

A contiguous segment of an array $A$. A subarray is defined by a starting index $i$ and an ending index $j$, with $0 \leq i \leq j < n$, where $n$ is the length of the array.

Mathematical Representation:

$$ \text{Subarray } A[i..j] = [A_i, A_{i+1}, ..., A_j] $$

Example:

Given $A = [3, 5, 7, 9]$, the subarray from index $1$ to $2$ is $[5, 7]$.

Relevance to DP:

Subarray problems include finding the maximum subarray sum (Kadane's algorithm), where dynamic programming efficiently computes optimal subarrays.

Subarrays matter in DP because contiguity gives you a natural order, perfect for transitions. When a problem is about “best segment,” “best window,” or “best range,” DP patterns show up immediately.

### Substring

A contiguous sequence of characters within a string $S$. Analogous to subarrays in arrays.

Mathematical Representation:

A substring $S[i..j]$ is:

$$ S_iS_{i+1}...S_j $$

with $0 \leq i \leq j < \text{length}(S)$.

Example:

For $S = "dynamic"$, the substring from index $2$ to $4$ is $"nam"$.

Relevance to DP:

Substring problems include finding the longest palindromic substring or the longest common substring between two strings.

Strings are a DP playground because “prefixes” and “ends at i/j” are easy states to define. If you’ve ever seen a 2D DP table with characters along the top and side, you’ve met this world.

### Subsequence

A sequence derived from another sequence by deleting zero or more elements without changing the order of the remaining elements.

Mathematical Representation:

Given sequence $S$, subsequence $T$ is:

$$ T = [S_{i_1}, S_{i_2}, ..., S_{i_k}] $$

where $0 \leq i_1 < i_2 < ... < i_k < n$.

Example:

For $S = [a, b, c, d]$, $[a, c, d]$ is a subsequence.

Relevance to DP:

The Longest Common Subsequence (LCS) problem is a classic dynamic programming problem.

LCS Dynamic Programming Formulation:

Let $X = x_1 x_2 ... x_m$ and $Y = y_1 y_2 ... y_n$. Define $L[i][j]$ as the length of the LCS of $X[1..i]$ and $Y[1..j]$.

Recurrence Relation:

$$ L[i][j] = \begin{cases}
0 & \text{if } i = 0 \text{ or } j = 0 \\
L[i - 1][j - 1] + 1 & \text{if } x_i = y_j \\
\max(L[i - 1][j], L[i][j - 1]) & \text{if } x_i \neq y_j
\end{cases} $$

Implementation:

We build a two-dimensional table $L[0..m][0..n]$ using the above recurrence.

Time Complexity: $O(mn)$

Subsequences are where DP really earns its reputation, because “skip or take” decisions can branch exponentially. DP keeps that branching logically, but prevents it from becoming computational chaos.

## Practical Considerations

### Identifying DP Problems

This section is your pattern-matching toolkit. DP gets dramatically easier once you stop trying to “invent DP” every time and instead learn to recognize the signals that a table of reused sub-results will pay off.

I. If the problem asks for the number of ways to do something:

- Counting paths in a grid.
- DP avoids enumerating every route. An obstacle-free rectangular grid also has a direct binomial-coefficient formula.

II. If the task is to find the minimum or maximum value under constraints:

- Knapsack problem.
- Subset enumeration is a baseline; branch-and-bound and other methods may also apply.

III. If the same inputs appear again during recursion:

- Fibonacci numbers.
- Without DP, Fibonacci numbers would be recomputed many times.

IV. If the solution depends on both the current step and remaining resources (time, weight, money, length):

- Scheduling tasks within a time limit.
- A state can capture remaining time, although the exact scheduling constraints determine whether DP, greedy selection, or another method is appropriate.

V. If the problem works with prefixes, substrings, or subsequences:

- Longest common subsequence.
- A naive recursion explores exponentially many choices; caching prefix states removes repeated work.

VI. If choices at each step must be explored and combined carefully:

- Coin change with mixed denominations.
- DP guarantees the fewest coins for arbitrary positive integer denominations when its recurrence is correct. Exhaustive search can also guarantee optimality, while greedy works only for suitable coin systems.

VII. If the state space can be stored in a table or array:

- Problems with discrete states.
- A finite state space makes direct tabulation possible. Continuous-state problems need additional structure, a different representation, or an approximation; an array is not a requirement for every DP formulation.

A good “do” when scanning a problem is to ask: “Can I describe a state with a small number of integers (like i, j, w)?” If yes, DP is often on the table. A good “don’t” is jumping into DP just because the problem is hard, hard problems also show up in greedy, graph, and divide-and-conquer territory.

### State Design and Transition

- A well-chosen state defines what each subproblem represents, while a poorly chosen one leaves the formulation incomplete; for example, `dp[i][w]` in the knapsack problem captures value using `i` items and capacity `w`.
- A correct transition connects states consistently, while skipping this leads to undefined progress; in knapsack, the choice to include or exclude an item gives the formula for moving between states.

If DP ever feels “mysterious,” it’s usually because the state meaning isn’t crisp. Once the state is clear, the transition almost writes itself: you ask what decision moves you from smaller states to bigger ones, and you encode that decision as a recurrence.

### Complexity Optimization

- Reducing memory usage by discarding unnecessary states makes solutions efficient, while failing to do so can waste resources; for example, knapsack space can shrink from `O(nW)` to `O(W)` with a one-dimensional array.
- Using pruning to skip impossible paths speeds up computation, while omitting it allows redundant work; in recursive search with memoization, a branch can be ignored only when a proven bound shows it cannot improve the answer. Do not cache a partially explored or pruned result as an exact state value if it depends on the current global bound.

The key “why” here is that DP gives you structure, but structure can still be expensive. Optimization is about keeping the structure while trimming what you don’t truly need, whether that’s table size, transitions, or states that can never be reached.

### Common Pitfalls

I. Failure to Define Proper Base Cases

- Example: In grid path counting, omitting `dp[0][0] = 1` prevents any valid paths from being constructed.
- Consequence: Without correct starting values, the DP table propagates errors and produces incorrect results.

A simple “do”: before filling anything, write down the smallest cases and ensure they make sense. A simple “don’t”: assume the base case is “obvious” and skip it, DP will punish that immediately.

II. Updating States in the Wrong Dependency Order

- Example: In knapsack with a 1D array, iterating weights from low to high causes items to be reused multiple times.
- Consequence: Using the wrong order inflates computed values and leads to invalid or impossible solutions.

The ordering rule is not a style preference, it’s part of correctness. If your transition reads from states you’ve already updated in the same iteration, you may be solving a different problem than you think.

III. Ignoring Special or Edge Case Inputs

- Example: In knapsack, a zero-capacity input should return zero value rather than throwing an error.
- Consequence: Overlooking edge inputs causes crashes or incorrect answers in boundary conditions.

A good “do” is to test the edges early: zeros, ones, empty inputs, minimal sizes. DP solutions can look perfect on “normal” cases while quietly breaking on the boundaries where states and base cases are most exposed.

## List of Problems

For the sum and coin problems below, assume a non-negative integer target and positive integer choices. Zero or negative choices can create nonterminating recurrences when reuse is allowed. For string construction, use nonempty word-bank entries; words may be reused, and their order in the concatenation matters. Enumerating every construction remains output-sensitive even with memoization.

### Fibonacci Sequence

The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting with 0 and 1. This sequence is a classic example used to demonstrate recursive algorithms and dynamic programming techniques.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/fibonacci/)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/fibonacci/)

### Grid Traveler

The Grid Traveler problem involves finding the total number of ways to traverse an `m x n` grid from the top-left corner to the bottom-right corner, with the constraint that you can only move right or down.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/grid_traveler)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/grid_traveler)

### Climbing Stairs

The Climbing Stairs problem requires determining the number of distinct ways to reach the top of a staircase with 'n' steps, given that you can climb either 1, 2, or 3 steps at a time.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/climb_stairs)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/climbing_stairs)

### Can Sum

The Can Sum problem involves determining if it is possible to achieve a target sum using any number of elements from a given list of numbers. Each number in the list can be used multiple times.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/can_sum)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/can_sum)

### How Sum

The How Sum problem extends the Can Sum problem by identifying which elements from the list can be combined to sum up to the target value.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/how_sum)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/how_sum)

### Best Sum

The Best Sum problem further extends the How Sum problem by finding the smallest combination of numbers that add up to exactly the target sum.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/best_sum)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/best_sum)

### Can Construct

The Can Construct problem involves determining if a target string can be constructed from a given list of substrings.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/can_construct)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/can_construct)

### Count Construct

The Count Construct problem expands on the Can Construct problem by determining the number of ways a target string can be constructed using a list of substrings.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/count_construct)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/count_construct)

### All Constructs

The All Constructs problem is a variation of the Count Construct problem, which identifies all the possible combinations of substrings from a list that can be used to form the target string.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/all_construct)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/all_construct)

### Coins

The Coins problem aims to find the minimum number of coins needed to make a given value, provided an infinite supply of each coin denomination.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/coins)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/coins)

### Longest Common Subsequence

The Longest Common Subsequence problem involves finding the longest subsequence that two sequences have in common, where a subsequence is derived by deleting some or no elements without changing the order of the remaining elements.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/longest_common_subsequence)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/longest_common_subsequence)

### Longest Increasing Subarray

The Longest Increasing Subarray problem involves identifying the longest contiguous subarray where the elements are strictly increasing.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/longest_increasing_subarray)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/longest_increasing_subarray)

### Knuth-Morris-Pratt

The Knuth-Morris-Pratt (KMP) algorithm is a pattern searching algorithm that looks for occurrences of a "word" within a main "text string" using preprocessing over the pattern to achieve linear time complexity. It is primarily a string-matching algorithm; it appears here because its prefix table reuses information from shorter prefixes.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/kmp)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/kmp)

### Minimum Insertions to Form a Palindrome

This problem involves finding the minimum number of insertions needed to transform a given string into a palindrome. The goal is to make the string read the same forwards and backwards with the fewest insertions possible.

- [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome)
- [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/dynamic_programming/python/minimum_insertions_for_palindrome)

## Reading the Problem Statement

The wording and the constraints of a problem usually tell you which DP shape is intended before you write any code. Use this table to translate the statement into the decisions described above.

| If the problem says | What it means for your code |
| --- | --- |
| "number of ways" or "how many" | Transitions add counts, the base case is one way to do nothing, and counts usually need modulo $10^9 + 7$ after every addition. |
| "minimum cost" or "maximum profit" | Transitions take a min or a max, unreachable states start at positive or negative infinity, and an infinite final value means impossible, often returned as -1. |
| "is it possible" or "can you" | A Boolean table combined with or, often a simpler version of the counting DP. |
| "each item can be used at most once" | 0/1 knapsack, with the item loop outside and the capacity loop running downward. |
| "unlimited supply" or "can be reused" | Unbounded knapsack, with the capacity loop running upward so the current item can feed itself. |
| "combinations" or "order does not matter" | Items in the outer loop and the target in the inner loop, as in Coin Change II. |
| "different orders count as different" | Target in the outer loop and items in the inner loop, as in Combination Sum IV. |
| two strings or two arrays | An (m+1) by (n+1) table indexed by prefix lengths, with row 0 and column 0 for the empty prefix. |
| "subsequence" | Elements may be skipped, so a mismatch falls back to dropping one side and taking the better or summed neighbor. |
| "substring" or "subarray" | Elements must be contiguous, so a mismatch resets the state to 0 and the answer is the best over all end positions. |
| "contiguous" with "maximum sum" or "maximum product" | Kadane, with a best-ending-here value and a separate global best, plus a running minimum for products. |
| "palindrome" | Interval states on the range from i to j filled by increasing length, or expansion around centers for substrings. |
| "adjacent elements cannot both be chosen" | The House Robber shape, take or skip with a look back of two positions. |
| "cooldown", "fee", or "at most k transactions" | A state machine with one variable per state, each updated from the previous day's values. |
| "burst", "merge", or neighbors join after a removal | Interval DP that picks the last operation inside each range. |
| a binary tree with "maximum" or "rob" | Post-order DFS that returns a small tuple of states per subtree. |
| n up to $10^5$ or more | Only $O(n)$ or $O(n \log n)$ total work, so one-dimensional states with constant or logarithmic transitions. |
| n up to a few thousand | $O(n^2)$ is fine, such as the simple LIS or a two-string table. |
| n up to about 500 | $O(n^3)$ fits, which usually signals interval DP with a split point. |
| n up to about 20 | Bitmask DP over the $2^n$ subsets is intended. |
| "return the path" or "list the actual items" | Store the choice made at each state as a parent pointer, or walk the filled table backward from the answer cell. |
