## Dynamic Programming

Dynamic Programming (DP) is a way to solve complex problems by breaking them into smaller, easier problems. Instead of solving the same small problems again and again, DP **stores their solutions** in a structure like an array, table, or map. This avoids wasting time on repeated calculations and makes the process much faster and more efficient.

Before you even touch formulas, it helps to know *why DP feels like a superpower*: a lot of “hard” problems aren’t hard because each step is complicated, they’re hard because you keep stumbling into the **same** steps repeatedly. DP is basically the art of noticing that repetition and saying, “Cool, I’ll pay the cost once, then reuse it.”

DP works best for problems that have two features. The first is **optimal substructure**, which means you can build the solution to a big problem from the solutions to smaller problems. The second is **overlapping subproblems**, where the same smaller problems show up multiple times during the process. By focusing on these features, DP ensures that each part of the problem is solved only once.

A practical way to “care” about these two features is this: they’re your green lights. If a problem has both, DP usually turns what feels impossible into something routine. If it doesn’t, DP can become a slow, memory-hungry distraction. So these aren’t academic definitions, they’re decision tools.

This method was introduced by Richard Bellman in the 1950s and has become a valuable tool in areas like computer science, economics, and operations research. It has been used to solve problems that would otherwise take too long by turning slow, exponential-time algorithms into much faster polynomial-time solutions. DP is used in practice for tackling real-world optimization challenges.

And that’s the real payoff: DP isn’t about writing big tables for fun, it’s about making your program behave like a thoughtful planner instead of a frantic guesser. When you see DP in the wild, it’s usually hiding inside something that needs to be fast *and* correct: routing, scheduling, matching, compression, resource allocation, and more.

### Principles

To effectively apply dynamic programming, a problem must satisfy two properties:

A useful mindset here is to treat DP like a story you’re building: first you define the “chapters” (subproblems), then you decide how chapters connect (transitions), and finally you make sure you never rewrite a chapter you already finished (storage).

#### 1. Optimal Substructure

A problem has **optimal substructure** when the best solution to the overall problem can be built from the best solutions to its smaller parts. In simple terms, solving the smaller pieces perfectly ensures the entire problem is solved perfectly too.

Formally, if the optimal solution $S_n$ for a problem of size $n$ can be created by combining the optimal solutions $S_k$ for smaller sizes $k < n$, then the problem is said to exhibit optimal substructure.

Why this matters: DP depends on trust. You’re trusting that if you make the best choice for a subproblem, you’re not accidentally ruining the final answer. If that trust holds, you can safely “lock in” sub-results. If it doesn’t, DP will confidently assemble a solution that looks logical but isn’t globally optimal.

**Mathematical Representation**:

Consider a problem where we want to find the optimal value $V(n)$ for a given parameter $n$. If there exists a function $f$ such that:

$$ V(n) = \min_{k} { f(V(k), V(n - k)) } $$

then the problem exhibits optimal substructure.

**Example**: Shortest Path in Graphs

In the context of graph algorithms, suppose we want to find the shortest path from vertex $A$ to vertex $C$. If $B$ is an intermediate vertex on the shortest path from $A$ to $C$, then the shortest path from $A$ to $C$ is the concatenation of the shortest path from $A$ to $B$ and the shortest path from $B$ to $C$.

This example also highlights a common “do”: make sure you can clearly explain how a best solution is *composed*. If you can’t describe how the big answer is built from smaller best answers, your “DP solution” is probably just a recursive solution with a table taped to it.

#### 2. Overlapping Subproblems

A problem has **overlapping subproblems** when it can be divided into smaller problems that are solved multiple times. This happens when the same subproblem appears in different parts of the solution process. In a straightforward recursive approach, this leads to solving the same subproblem repeatedly, which wastes time and resources. Dynamic Programming addresses this by solving each subproblem once and storing the result for reuse, improving efficiency significantly.

This is the efficiency engine. Optimal substructure tells you DP *can* work; overlapping subproblems tells you DP is *worth it*. If subproblems don’t repeat, caching doesn’t buy you much, and you’re better off with a different approach.

**Mathematical Representation**:

Let $S(n)$ be the set of subproblems for problem size $n$. If there exists $s \in S(n)$ such that $s$ appears in $S(k)$ for multiple $k$, the problem has overlapping subproblems.

**Example**: Fibonacci Numbers

The recursive computation of Fibonacci numbers $F(n) = F(n - 1) + F(n - 2)$ involves recalculating the same Fibonacci numbers multiple times. For instance, to compute $F(5)$, we need to compute $F(4)$ and $F(3)$, both of which require computing $F(2)$ and $F(1)$ multiple times.

Fibonacci is the classic demo not because it’s deep, but because it’s obvious. It teaches the key emotional lesson: recursion can feel elegant while quietly doing ridiculous repeated work, DP keeps the elegance and removes the waste.

### Techniques

There are two primary methods for implementing dynamic programming algorithms:

You can think of these as two different writing styles for the same story. Memoization writes chapters only when needed (and bookmarks them). Tabulation writes every chapter in order, from page 1 onward. Both can end at the same ending; the difference is how they get there.

#### 1. Memoization (Top-Down Approach)

**Memoization** is a technique used to optimize recursive problem-solving by storing the results of solved subproblems in a data structure, such as a hash table or an array. When the algorithm encounters a subproblem, it first checks if the result is already stored. If it is, the algorithm simply retrieves the cached result instead of recomputing it. This approach reduces redundant calculations, making the solution process faster and more efficient.

A “do” for memoization: keep the recursion because it matches the problem’s natural definition, but make every subproblem cheap after the first time. A “don’t”: let your memo structure accidentally depend on hidden state (like mutable defaults or changing globals) in a way that makes results inconsistent.

**Algorithm Steps**:

1. Identify the parameters that uniquely define a subproblem and create a **recursive function** using these parameters.
2. Establish **base cases** to terminate recursion.
3. Initialize a data structure to **store** computed subproblem results.
4. Before computing a subproblem, **check if its result is already stored**.
5. If not already computed, **compute the subproblem's result** and store it.

**Example**: Computing Fibonacci Numbers with Memoization

```python
def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        memo[n] = n
    else:
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo)
    return memo[n]
```

**Analysis**:

* **Time Complexity**: $O(n)$, since each number up to $n$ is computed once.
* **Space Complexity**: $O(n)$, due to the memoization structure.

One practical note when learning: top-down DP is often easier to write correctly first, because you start from the real question (“solve $n$”) and naturally reach for smaller questions. If you can write the recurrence cleanly, memoization is usually your fastest path to a working solution.

#### 2. Tabulation (Bottom-Up Approach)

**Tabulation** is a technique that solves a problem by working from the smallest subproblems up to the larger ones in a step-by-step, iterative way. It stores the solutions to these subproblems in a table, often an array, and uses these stored values to solve bigger subproblems until the final solution is reached. Unlike memoization, which works recursively and checks if a solution is already computed, tabulation systematically builds the solution from the ground up. This method is efficient and avoids the overhead of recursive calls.

The “why” behind tabulation is control: you decide the exact order states are computed, and you avoid recursion limits and call overhead. The “do” is to fill the table in dependency order. The “don’t” is to fill it in a convenient order that violates dependencies, because then you’ll be reading values that aren’t valid yet.

**Algorithm Steps**:

1. **Initialize the table** by setting up a structure to store the results of subproblems, and ensure that base cases are properly initialized to handle the simplest instances of the problem.
2. **Iterative computation** is carried out using loops to fill the table, making sure that each subproblem is solved in the correct order before being used to solve larger subproblems.
3. **Construct the solution** by referencing the filled table, using the stored values to derive the final solution to the original problem efficiently.

**Example**: Computing Fibonacci Numbers with Tabulation

```python
def fibonacci(n):
    if n <= 1:
        return n
    fib_table = [0] * (n + 1)
    fib_table[0], fib_table[1] = 0, 1
    for i in range(2, n + 1):
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2]
    return fib_table[n]
```

**Analysis**:

* The **time complexity** is $O(n)$, since the algorithm iterates from 2 to $n$, computing each Fibonacci number sequentially.
* The **space complexity** is $O(n)$, due to the storage required for the table that holds the Fibonacci numbers up to $n$.

A nice way to make tabulation feel natural is to ask: “What’s the smallest thing I must know before I can know the next thing?” That question basically *is* the loop order.

#### Comparison of Memoization and Tabulation

| Aspect               | Memoization (Top-Down)                                    | Tabulation (Bottom-Up)                                |
| -------------------- | --------------------------------------------------------- | ----------------------------------------------------- |
| **Approach**         | Recursive                                                 | Iterative                                             |
| **Storage**          | Stores solutions as needed                                | Pre-fills table with solutions to all subproblems     |
| **Overhead**         | Function call overhead due to recursion                   | Minimal overhead due to iteration                     |
| **Flexibility**      | May be easier to implement for complex recursive problems | May require careful ordering of computations          |
| **Space Efficiency** | Potentially higher due to recursion stack and memoization | Can be more space-efficient with careful table design |

If you’re choosing between them, a simple rule of thumb is: start with memoization to get the recurrence right, then switch to tabulation when you want tighter performance or cleaner memory control.

### Implementation Techniques

Dynamic programming problems are often formulated using recurrence relations, which express the solution to a problem in terms of its subproblems.

This step is where DP stops being “a concept” and becomes “a tool.” Your recurrence is the blueprint: it tells you what a state means and exactly how it is built. Without a recurrence (explicit or implicit), you don’t have DP, you have hope and a table.

#### Formulating Recurrence Relations

**Example**: Longest Common Subsequence (LCS)

Given two sequences $X = x_1, x_2, ..., x_m$ and $Y = y_1, y_2, ..., y_n$, the length of their LCS can be defined recursively:

$$ LCS(i, j) = \begin{cases}
0 & \text{if } i = 0 \text{ or } j = 0 \
LCS(i - 1, j - 1) + 1 & \text{if } x_i = y_j \
\max(LCS(i - 1, j), LCS(i, j - 1)) & \text{if } x_i \neq y_j
\end{cases} $$

**Implementation**:

We can implement the LCS problem using either memoization or tabulation. With tabulation, we build a two-dimensional table $LCS[0..m][0..n]$ iteratively.

* The **time complexity** is $O(mn)$, as the algorithm processes a grid or matrix of size $m \times n$, iterating through each cell.
* The **space complexity** is $O(mn)$, due to the table storing intermediate results, but this can be reduced to $O(n)$ by optimizing the storage to only keep necessary data for the current and previous rows.

The reason LCS is such a beloved DP example is that the “choices” are easy to explain: if characters match, you take the diagonal; if they don’t, you take the best of left/top. That clear decision structure is exactly what good DP feels like: simple local rules that reliably build a global answer.

#### State Representation

Properly defining the state is crucial for dynamic programming.

* **State variables** are the parameters that uniquely define each subproblem, helping to break down the problem into smaller, manageable components.
* **State transition** refers to the rules or formulas that describe how to move from one state to another, typically using the results of smaller subproblems to solve larger ones.

Think of state design like labeling drawers in a workshop. If the labels are precise, you can find what you need instantly and build bigger things confidently. If the labels are vague, you’ll keep opening drawers, guessing, and making mistakes, even if the math is technically “there.”

**Example**: 0/1 Knapsack Problem

* The **problem statement** focuses on selecting $n$ items, each with a weight $w_i$ and value $v_i$, while ensuring the total weight stays within the knapsack capacity $W$, in order to maximize the total value.
* In **state representation**, $dp[i][w]$ represents the maximum value that can be achieved using the first $i$ items with a total weight capacity of $w$.
* **State Transition**:

$$ dp[i][w] = \begin{cases}
dp[i - 1][w] & \text{if } w_i > w \
\max(dp[i - 1][w], dp[i - 1][w - w_i] + v_i) & \text{if } w_i \leq w
\end{cases} $$

**Implementation**:

We fill the table $dp[0..n][0..W]$ iteratively based on the state transition.

* The **time complexity** is $O(nW)$, where $n$ is the number of items and $W$ is the capacity of the knapsack, as the algorithm iterates through both items and weights.
* The **space complexity** is $O(nW)$, but this can be optimized to $O(W)$ because each row in the table depends only on the values from the previous row, allowing for space reduction.

A key “do” here is to interpret your state in plain language. If you can’t say what `dp[i][w]` *means* in one sentence, debugging will be painful. A key “don’t” is mixing meanings (for example, letting `w` sometimes mean “remaining capacity” and sometimes mean “used weight”), that’s how DP tables become nonsense.

### Advanced Concepts

#### Memory Optimization

In some cases, we can optimize space complexity by noticing dependencies between states.

This is where DP graduates from “works” to “works well.” Once the recurrence is correct, you can ask: “Do I truly need *all* previous states, or only a slice of them?” Many DP solutions only depend on the previous row, previous column, or a small window, so storing everything is optional.

**Example**: Since $dp[i][w]$ depends only on $dp[i - 1][w]$ and $dp[i - 1][w - w_i]$, we can use a one-dimensional array and update it in reverse.

```python
dp = [0] * (W + 1)
for i in range(1, n + 1):
    for w in range(W, w_i - 1, -1):
        dp[w] = max(dp[w], dp[w - w_i] + v_i)
```

One important “do/don’t” hidden in this snippet is the reverse loop. Updating from high to low prevents using the same item multiple times in a single iteration. If you go forward, you silently switch the problem you’re solving.

#### Dealing with Non-Overlapping Subproblems

If a problem has **optimal substructure** but does not have **overlapping subproblems**, it is often better to use **Divide and Conquer** instead of Dynamic Programming. Divide and Conquer works by breaking the problem into independent subproblems, solving each one separately, and then combining their solutions. Since there are no repeated subproblems to reuse, storing intermediate results (as in Dynamic Programming) is unnecessary, making Divide and Conquer a more suitable and efficient choice in such cases.

This distinction matters because DP isn’t “better recursion”, it’s “recursion plus reuse.” If there’s nothing to reuse, DP is extra work for no gain. Picking the right paradigm is part of writing efficient algorithms, not just correct ones.

**Example**: Merge Sort algorithm divides the list into halves, sorts each half, and then merges the sorted halves.

### Common Terms

These terms show up constantly around DP because DP is really about breaking a big idea into structured pieces. The more comfortable you are with these building blocks, the faster DP problems start to feel like patterns instead of puzzles.

#### Recursion

A process is called **recursion** when a function solves a problem by calling itself, either directly or indirectly, with a smaller instance of the same problem. This continues until the function reaches a **base case**, which is a condition that stops further recursive calls and provides a straightforward solution. Recursion is useful for problems that can naturally be divided into similar smaller subproblems.

**Mathematical Perspective**:

A recursive function $f(n)$ satisfies:

$$ f(n) = g(f(k), f(n - k)) $$

for some function $g$ and smaller subproblem size $k < n$.

**Example**: Computing $n!$:

$$ n! = n \times (n - 1)! $$

with base case $0! = 1$.

In DP, recursion is often your first draft: it expresses the logic cleanly. Then DP adds the missing ingredient: remembering what you already solved.

#### Subset

For a set $S$, a subset $T$ is a set where every element of $T$ is also an element of $S$. Denoted as $T \subseteq S$.

**Mathematical Properties**:

* The **total subsets** of a set with $n$ elements is $2^n$, as each element can either be included or excluded from a subset.
* The **power set** of a set $S$, denoted as $\mathcal{P}(S)$, is the set of all possible subsets of $S$, including the empty set and $S$ itself.

**Relevance to DP**:

Subsets often represent different states or configurations in combinatorial problems, such as the subset-sum problem.

The “why you should care” is right in the number $2^n$: subsets explode fast. DP is often the difference between “impossible after n=40” and “fine for n=10,000,” depending on the structure.

#### Subarray

A contiguous segment of an array $A$. A subarray is defined by a starting index $i$ and an ending index $j$, with $0 \leq i \leq j < n$, where $n$ is the length of the array.

**Mathematical Representation**:

$$ \text{Subarray } A[i..j] = [A_i, A_{i+1}, ..., A_j] $$

**Example**:

Given $A = [3, 5, 7, 9]$, the subarray from index $1$ to $2$ is $[5, 7]$.

**Relevance to DP**:

Subarray problems include finding the maximum subarray sum (Kadane's algorithm), where dynamic programming efficiently computes optimal subarrays.

Subarrays matter in DP because contiguity gives you a natural order, perfect for transitions. When a problem is about “best segment,” “best window,” or “best range,” DP patterns show up immediately.

#### Substring

A contiguous sequence of characters within a string $S$. Analogous to subarrays in arrays.

**Mathematical Representation**:

A substring $S[i..j]$ is:

$$ S_iS_{i+1}...S_j $$

with $0 \leq i \leq j < \text{length}(S)$.

**Example**:

For $S = "dynamic"$, the substring from index $2$ to $4$ is $"nam"$.

**Relevance to DP**:

Substring problems include finding the longest palindromic substring or the longest common substring between two strings.

Strings are a DP playground because “prefixes” and “ends at i/j” are easy states to define. If you’ve ever seen a 2D DP table with characters along the top and side, you’ve met this world.

#### Subsequence

A sequence derived from another sequence by deleting zero or more elements without changing the order of the remaining elements.

**Mathematical Representation**:

Given sequence $S$, subsequence $T$ is:

$$ T = [S_{i_1}, S_{i_2}, ..., S_{i_k}] $$

where $0 \leq i_1 < i_2 < ... < i_k < n$.

**Example**:

For $S = [a, b, c, d]$, $[a, c, d]$ is a subsequence.

**Relevance to DP**:

The Longest Common Subsequence (LCS) problem is a classic dynamic programming problem.

**LCS Dynamic Programming Formulation**:

Let $X = x_1 x_2 ... x_m$ and $Y = y_1 y_2 ... y_n$. Define $L[i][j]$ as the length of the LCS of $X[1..i]$ and $Y[1..j]$.

**Recurrence Relation**:

$$ L[i][j] = \begin{cases}
0 & \text{if } i = 0 \text{ or } j = 0 \
L[i - 1][j - 1] + 1 & \text{if } x_i = y_j \
\max(L[i - 1][j], L[i][j - 1]) & \text{if } x_i \neq y_j
\end{cases} $$

**Implementation**:

We build a two-dimensional table $L[0..m][0..n]$ using the above recurrence.

**Time Complexity**: $O(mn)$

Subsequences are where DP really earns its reputation, because “skip or take” decisions can branch exponentially. DP keeps that branching logically, but prevents it from becoming computational chaos.

### Practical Considerations

#### Identifying DP Problems

This section is your pattern-matching toolkit. DP gets dramatically easier once you stop trying to “invent DP” every time and instead learn to recognize the signals that a table of reused sub-results will pay off.

I. If the problem asks for the number of *ways* to do something:

* Counting paths in a grid.
* Without DP, you would need to enumerate every route.

II. If the task is to find the *minimum* or *maximum* value under constraints:

* Knapsack problem.
* Without DP, you would need to check every subset of items.

III. If the same *inputs* appear again during recursion:

* Fibonacci numbers.
* Without DP, Fibonacci numbers would be recomputed many times.

IV. If the solution depends on both the *current step* and *remaining resources* (time, weight, money, length):

* Scheduling tasks within a time limit.
* Without DP, brute force would be required.

V. If the problem works with *prefixes, substrings, or subsequences*:

* Longest common subsequence.
* Without DP, exponential checking would be needed.

VI. If choices at each step must be explored and combined carefully:

* Coin change with mixed denominations.
* Without DP, you cannot guarantee the fewest coins.

VII. If the state space can be stored in a *table or array*:

* Problems with discrete states.
* Without this, problems with infinitely many possibilities (like arbitrary real numbers) cannot be handled.

A good “do” when scanning a problem is to ask: “Can I describe a state with a small number of integers (like i, j, w)?” If yes, DP is often on the table. A good “don’t” is jumping into DP just because the problem is hard, hard problems also show up in greedy, graph, and divide-and-conquer territory.

#### State Design and Transition

* A well-chosen *state* defines what each subproblem represents, while a poorly chosen one leaves the formulation incomplete; for example, `dp[i][w]` in the knapsack problem captures value using `i` items and capacity `w`.
* A correct *transition* connects states consistently, while skipping this leads to undefined progress; in knapsack, the choice to include or exclude an item gives the formula for moving between states.

If DP ever feels “mysterious,” it’s usually because the state meaning isn’t crisp. Once the state is clear, the transition almost writes itself: you ask what decision moves you from smaller states to bigger ones, and you encode that decision as a recurrence.

#### Complexity Optimization

* Reducing *memory usage* by discarding unnecessary states makes solutions efficient, while failing to do so can waste resources; for example, knapsack space can shrink from `O(nW)` to `O(W)` with a one-dimensional array.
* Using *pruning* to skip impossible paths speeds up computation, while omitting it allows redundant work; in recursive search with memoization, branches exceeding a current best value can be safely ignored.

The key “why” here is that DP gives you structure, but structure can still be expensive. Optimization is about keeping the structure while trimming what you don’t truly need, whether that’s table size, transitions, or states that can never be reached.

#### Common Pitfalls

I. Failure to Define Proper Base Cases

* *Example*: In grid path counting, omitting `dp[0][0] = 1` prevents any valid paths from being constructed.
* *Consequence*: Without correct starting values, the DP table propagates errors and produces incorrect results.

A simple “do”: before filling anything, write down the smallest cases and ensure they make sense. A simple “don’t”: assume the base case is “obvious” and skip it, DP will punish that immediately.

II. Updating States in the Wrong Dependency Order

* *Example*: In knapsack with a 1D array, iterating weights from low to high causes items to be reused multiple times.
* *Consequence*: Using the wrong order inflates computed values and leads to invalid or impossible solutions.

The ordering rule is not a style preference, it’s part of correctness. If your transition reads from states you’ve already updated in the same iteration, you may be solving a different problem than you think.

III. Ignoring Special or Edge Case Inputs

* *Example*: In knapsack, a zero-capacity input should return zero value rather than throwing an error.
* *Consequence*: Overlooking edge inputs causes crashes or incorrect answers in boundary conditions.

A good “do” is to test the edges early: zeros, ones, empty inputs, minimal sizes. DP solutions can look perfect on “normal” cases while quietly breaking on the boundaries where states and base cases are most exposed.

### List of Problems

#### Fibonacci Sequence

The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting with 0 and 1. This sequence is a classic example used to demonstrate recursive algorithms and dynamic programming techniques.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/fibonacci/)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/fibonacci/)

#### Grid Traveler

The Grid Traveler problem involves finding the total number of ways to traverse an `m x n` grid from the top-left corner to the bottom-right corner, with the constraint that you can only move right or down.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/grid_traveler)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/grid_traveler)

#### Climbing Stairs

The Climbing Stairs problem requires determining the number of distinct ways to reach the top of a staircase with 'n' steps, given that you can climb either 1, 2, or 3 steps at a time.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/climb_stairs)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/climbing_stairs)

#### Can Sum

The Can Sum problem involves determining if it is possible to achieve a target sum using any number of elements from a given list of numbers. Each number in the list can be used multiple times.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_sum)

#### How Sum

The How Sum problem extends the Can Sum problem by identifying which elements from the list can be combined to sum up to the target value.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/how_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/how_sum)

#### Best Sum

The Best Sum problem further extends the How Sum problem by finding the smallest combination of numbers that add up to exactly the target sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/best_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/best_sum)

#### Can Construct

The Can Construct problem involves determining if a target string can be constructed from a given list of substrings.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/can_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/can_construct)

#### Count Construct

The Count Construct problem expands on the Can Construct problem by determining the number of ways a target string can be constructed using a list of substrings.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/count_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/count_construct)

#### All Constructs

The All Constructs problem is a variation of the Count Construct problem, which identifies all the possible combinations of substrings from a list that can be used to form the target string.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/all_construct)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/all_construct)

#### Coins

The Coins problem aims to find the minimum number of coins needed to make a given value, provided an infinite supply of each coin denomination.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/coin_change)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/coins)

#### Longest Common Subsequence

The Longest Common Subsequence problem involves finding the longest subsequence that two sequences have in common, where a subsequence is derived by deleting some or no elements without changing the order of the remaining elements.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_common_subsequence)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_common_subsequence)

#### Longest Increasing Subarray

The Longest Increasing Subarray problem involves identifying the longest contiguous subarray where the elements are strictly increasing.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/longest_increasing_subarray)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/longest_increasing_subarray)

#### Knuth-Morris-Pratt

The Knuth-Morris-Pratt (KMP) algorithm is a pattern searching algorithm that looks for occurrences of a "word" within a main "text string" using preprocessing over the pattern to achieve linear time complexity.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/kmp)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/kmp)

#### Minimum Insertions to Form a Palindrome

This problem involves finding the minimum number of insertions needed to transform a given string into a palindrome. The goal is to make the string read the same forwards and backwards with the fewest insertions possible.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/cpp/minimum_insertions_for_palindrome)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/blob/master/src/dynamic_programming/python/minimum_insertions_for_palindrome)
