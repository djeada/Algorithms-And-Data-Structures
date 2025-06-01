## Introduction to Data Structures & Algorithms

Data structures and algorithms are fundamental concepts in computer science that are key to building efficient software.

- A **data structure** specifies how data is stored and organized in memory. Examples include arrays, linked lists, stacks, queues, trees, and graphs. Choosing the right data structure can simplify solving specific problems.
- An **algorithm** is a step-by-step method for solving a problem or performing a task. Algorithms can range from simple operations like searching or sorting to complex computations in artificial intelligence or optimization.
- The combination of efficient data structures and algorithms enables developers to optimize software performance, both in terms of speed and memory usage.

### Data Structures

A **data structure** organizes and stores data in a way that allows efficient access, modification, and processing. The choice of the appropriate data structure depends on the specific use case and can significantly impact the performance of an application. Here are some common data structures:

1. Imagine an **array** as a row of lockers, each labeled with a number and capable of holding one item of the same type. Technically, arrays are blocks of memory storing elements sequentially, allowing quick access using an index. However, arrays have a fixed size, which limits their flexibility when you need to add or remove items.
2. Think of a **stack** like stacking plates: you always add new plates on top (push), and remove them from the top as well (pop). This structure follows the Last-In, First-Out (LIFO) approach, meaning the most recently added item is removed first. Stacks are particularly helpful in managing function calls (like in the call stack of a program) or enabling "undo" operations in applications.
3. A **queue** is similar to a line at the grocery store checkout. People join at the end (enqueue) and leave from the front (dequeue), adhering to the First-In, First-Out (FIFO) principle. This ensures the first person (or item) that arrives is also the first to leave. Queues work great for handling tasks or events in the exact order they occur, like scheduling print jobs or processing messages.
4. You can picture a **linked list** as a treasure hunt, where each clue leads you to the next one. Each clue, or node, holds data and a pointer directing you to the next node. Because nodes can be added or removed without shifting other elements around, linked lists offer dynamic and flexible management of data at any position.
5. A **tree** resembles a family tree, starting from one ancestor (the root) and branching out into multiple descendants (nodes), each of which can have their own children. Formally, trees are hierarchical structures organized across various levels. They’re excellent for showing hierarchical relationships, such as organizing files on your computer or visualizing company structures.
6. Consider a **graph** like a network of cities connected by roads. Each city represents a node, and the roads connecting them are edges, which can either be one-way (directed) or two-way (undirected). Graphs effectively illustrate complex relationships and networks, such as social media connections, website link structures, or even mapping transportation routes.

![image](https://github.com/user-attachments/assets/f1962de7-aa28-4348-9933-07e49c737cd9)

### Algorithms

An **algorithm** is like a clear and detailed set of instructions or steps for solving a specific problem or performing a particular task. Think of it like following a precise recipe when cooking:

- The ingredients needed represent the **input**, which are the data or information the algorithm uses to begin its work.
- The finished dish is the **output**, or the final result the algorithm provides after processing the input.
- Each instruction in an algorithm must be clear and precise. This clarity is known as **definiteness**, ensuring anyone following the steps reaches the same result without confusion.
- Algorithms must have a definite end-point, known as **termination**, meaning they can’t run indefinitely and must eventually finish with a result.
- Every step in an algorithm must be practical and achievable, known as **effectiveness**, ensuring the instructions can realistically be carried out to achieve the desired outcome.

To evaluate how good an algorithm is, we often look at its efficiency in terms of time complexity (how long it takes to run) and space complexity (how much memory it uses). We will discuss it in greater detail in later sections.

#### Algorithms vs. Programs

An **algorithm** is a high-level blueprint for solving a specific problem. It is abstract, language-independent, and specifies a clear sequence of steps without relying on any particular programming syntax. An algorithm can be thought of as a recipe or method for solving a problem and can be represented in multiple forms, such as plain text or a flowchart.

**Example:** Algorithm for adding two numbers:

```
Step 1: Start
Step 2: Declare variables num1, num2, and sum.
Step 3: Read values into num1 and num2.
Step 4: Add num1 and num2; store the result in sum.
Step 5: Print sum.
Step 6: Stop.
```

This algorithm can also be visualized using a flowchart:

```
---------------------
|       Start       |
---------------------
         |
         V
------------------------------
| Declare num1, num2, sum    |
------------------------------
         |
         V
--------------------------
| Read num1 and num2     |
--------------------------
         |
         V
--------------------------
| sum = num1 + num2      |
--------------------------
         |
         V
--------------------------
| Print sum              |
--------------------------
         |
         V
--------------------------
| Stop                   |
--------------------------
```

In contrast, a **program** is a concrete implementation of an algorithm. It is language-dependent and adheres to the specific syntax and rules of a programming language. For example, the above algorithm can be implemented in Python as:

```python
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
sum = num1 + num2
print("The sum is", sum)
```

To recap:

- Algorithms are abstract instructions designed to terminate after a finite number of steps.
- Programs are concrete implementations, which may sometimes run indefinitely or until an external action stops them. For instance, an operating system is a program designed to run continuously until explicitly terminated.

#### Types of Algorithms

Algorithms can be classified into various types based on the problems they solve and the strategies they use. Here are some common categories with consistent explanations and examples:

I. **Sorting Algorithms** arrange data in a specific order, such as ascending or descending. Examples include bubble sort, insertion sort, selection sort, and merge sort.

Example: Bubble Sort

```
Initial Array: [5, 3, 8, 4, 2]

Steps:
1. Compare adjacent elements and swap if needed.
2. Repeat for all elements.

After 1st Pass: [3, 5, 4, 2, 8]
After 2nd Pass: [3, 4, 2, 5, 8]
After 3rd Pass: [3, 2, 4, 5, 8]
After 4th Pass: [2, 3, 4, 5, 8] (Sorted)
```

II. **Search Algorithms** are designed to find a specific item or value within a collection of data. Examples include linear search, binary search, and depth-first search.

Example: Binary Search

```
Searching 33 in Sorted Array: [1, 3, 5, 7, 9, 11, 33, 45, 77, 89]

Steps:
1. Start with the middle element.
2. If the middle element is the target, return it.
3. If the target is greater, ignore the left half.
4. If the target is smaller, ignore the right half.
5. Repeat until the target is found or the subarray is empty.

Mid element at start: 9
33 > 9, so discard left half
New mid element: 45
33 < 45, so discard right half
New mid element: 11
33 > 11, so discard left half
The remaining element is 33, which is the target.
```

**Graph Algorithms** address problems related to graphs, such as finding the shortest path between nodes or determining if a graph is connected. Examples include Dijkstra's algorithm and the Floyd-Warshall algorithm.

Example: Dijkstra's Algorithm

```
Given a graph with weighted edges, find the shortest path from a starting node to all other nodes.

Steps:
1. Initialize the starting node with a distance of 0 and all other nodes with infinity.
2. Visit the unvisited node with the smallest known distance.
3. Update the distances of its neighboring nodes.
4. Repeat until all nodes have been visited.

Example Graph:
A -> B (1)
A -> C (4)
B -> C (2)
B -> D (5)
C -> D (1)

Starting from A:
- Shortest path to B: A -> B (1)
- Shortest path to C: A -> B -> C (3)
- Shortest path to D: A -> B -> C -> D (4)
```

**String Algorithms** deal with problems related to strings, such as finding patterns or matching sequences. Examples include the Knuth-Morris-Pratt (KMP) algorithm and the Boyer-Moore algorithm.

Example: Boyer-Moore Algorithm

```
Text:    "ABABDABACDABABCABAB"
Pattern: "ABABCABAB"

Steps:
1. Compare the pattern from right to left.
2. If a mismatch occurs, use the bad character and good suffix heuristics to skip alignments.
3. Repeat until the pattern is found or the text is exhausted.

Pattern matched starting at index 10 in the text.
```

#### Important Algorithms for Software Engineers

- As a software engineer, it is not necessary to **master every algorithm**. Instead, knowing how to effectively use libraries and packages that implement widely-used algorithms is more practical.
- The important skill is the ability to **select the right algorithm** for a task by considering factors such as its efficiency, the problem’s requirements, and any specific constraints.
- Learning **algorithms** during the early stages of programming enhances problem-solving skills. It builds a solid foundation in logical thinking, introduces various problem-solving strategies, and helps in understanding how to approach complex issues.
- Once the **fundamentals of algorithms** are understood, the focus often shifts to utilizing pre-built libraries and tools for solving real-world problems, as writing algorithms from scratch is rarely needed in practice.

### Understanding Algorithmic Complexity

Algorithmic complexity helps us understand the computational resources (time or space) an algorithm needs as the input size increases. Here’s a breakdown of different types of complexity:

* *Best-case complexity* describes how quickly or efficiently an algorithm runs under the most favorable conditions. For example, an algorithm with a best-case complexity of O(1) performs its task instantly, regardless of how much data it processes.
* *Average-case complexity* reflects the typical performance of an algorithm across all possible inputs. Determining this can be complex, as it involves analyzing how often different inputs occur and how each one influences the algorithm's overall performance.
* *Worst-case complexity* defines the maximum amount of time or resources an algorithm could consume when faced with the most difficult or demanding inputs. Understanding the worst-case scenario is crucial because it sets an upper limit on performance, ensuring predictable and reliable behavior.
* *Space complexity* refers to how much memory an algorithm needs relative to the amount of data it processes. It's an important consideration when memory availability is limited or when optimizing an algorithm to be resource-efficient.
* *Time complexity* indicates how the execution time of an algorithm increases as the input size grows. Typically, this is the primary focus when evaluating algorithm efficiency because faster algorithms are generally more practical and user-friendly.

#### Analyzing Algorithm Growth Rates

Understanding how the running time or space complexity of an algorithm scales with increasing input size is pivotal in algorithm analysis. To describe this rate of growth, we employ several mathematical notations that offer insights into the algorithm's efficiency under different conditions.

##### Big O Notation (O-notation)

The Big O notation represents an asymptotic upper bound, indicating the worst-case scenario for an algorithm's time or space complexity. Essentially, it signifies an upper limit on the growth of a function.

If we designate $f(n)$ as the actual complexity and $g(n)$ as the function in Big O notation, stating $f(n) = O(g(n))$ implies that $f(n)$, the time or space complexity of the algorithm, grows no faster than $g(n)$.

For instance, if an algorithm has a time complexity of $O(n)$, it signifies that the algorithm's running time does not grow more rapidly than a linear function of the input size, in the worst-case scenario.

##### Big Omega Notation (Ω-notation)

The Big Omega notation provides an asymptotic lower bound that expresses the best-case scenario for the time or space complexity of an algorithm.

If $f(n) = Ω(g(n))$, this means that $f(n)$ grows at a rate that is at least as fast as $g(n)$. In other words, $f(n)$ does not grow slower than $g(n)$.

For example, if an algorithm has a time complexity of $Ω(n)$, it implies that the running time is at the bare minimum proportional to the input size in the best-case scenario.

##### Theta Notation (Θ-notation)

Theta notation offers a representation of the average-case scenario for an algorithm's time or space complexity. It sets an asymptotically tight bound, implying that the function grows neither more rapidly nor slower than the bound.

Stating $f(n) = Θ(g(n))$ signifies that $f(n)$ grows at the same rate as $g(n)$ under average circumstances. This indicates the time or space complexity is both at most and at least a linear function of the input size.

Remember, these notations primarily address the growth rate as the input size becomes significantly large. While they offer a high-level comprehension of an algorithm's performance, the actual running time in practice can differ based on various factors, such as the specific input data, the hardware or environment where the algorithm is operating, and the precise way the algorithm is implemented in the code.

#### Diving into Big O Notation Examples

Big O notation is a practical tool for comparing the worst-case scenario of algorithm complexities. Here are examples of various complexities:

- The time complexity **$O(1)$**, known as constant time complexity, means that regardless of the input size, the algorithm performs its task in a fixed amount of time. A common example of this is retrieving an item by its index from an array or accessing a key-value pair in a hash map.
- When an algorithm has **$O(log n)$** time complexity, it operates logarithmically, meaning the time taken increases logarithmically with input size. As the input size doubles, the time taken only increases marginally. Binary search and operations on balanced binary trees are typical examples.
- An algorithm with **$O(n)$** time complexity exhibits linear behavior, where the running time scales directly with the input size. This is seen in simple, single-pass processes like iterating over an array or a linked list.
- In cases of **$O(n log n)$** time complexity, also called log-linear complexity, the running time grows both linearly and logarithmically with the input size. Sorting algorithms such as QuickSort, MergeSort, and HeapSort are prime examples of this complexity.
- With **$O(n^2)$** time complexity, the running time increases quadratically, often due to nested loops. Algorithms like Bubble Sort and Insertion Sort fall into this category.
- When an algorithm has **$O(n^3)$** time complexity, its running time scales cubically with the input size. This is common in algorithms involving three nested loops, such as naive matrix multiplication.
- **$O(2^n)$** represents exponential time complexity, where the running time doubles with each additional unit of input size. This is typical in brute-force algorithms like generating all subsets of a set or solving the Travelling Salesman Problem using a naive approach.

The graph below illustrates the growth of these different time complexities:

![big_o](https://user-images.githubusercontent.com/37275728/185381461-ec062561-1f55-4cf5-a3fa-d4cc0a2c06df.png)

Imagine you’re building an app and every millisecond counts—choosing the right algorithm can make it lightning-fast or tediously slow, so having a solid grasp of time complexity may pay off.

Here is a summary cheat sheet:

| Notation        | Name                 | Meaning                                                          | Common Examples                                        |
|-----------------|----------------------|------------------------------------------------------------------|--------------------------------------------------------|
| $O(1)$        | Constant time        | Running time does not depend on input size $n$.                  | Array indexing, hash‐table lookup                      |
| $O(\log n)$   | Logarithmic time     | Time grows proportionally to the logarithm of $n$.               | Binary search, operations on balanced BSTs             |
| $O(n)$        | Linear time          | Time grows linearly with $n$.                                    | Single loop over array, scanning for max/min          |
| $O(n \log n)$ | Linearithmic time    | Combination of linear and logarithmic growth.                    | Merge sort, heap sort, FFT                             |
| $O(n^2)$      | Quadratic time       | Time grows proportional to the square of $n$.                    | Bubble sort, selection sort, nested loops              |
| $O(n^3)$      | Cubic time           | Time grows proportional to the cube of $n$.                      | Naïve matrix multiplication (3 nested loops)           |
| $O(2^n)$      | Exponential time     | Time doubles with each additional element in the input.          | Recursive Fibonacci, brute‐force subset enumeration    |
| $O(n!)$       | Factorial time       | Time grows factorially with $n$.                                 | Brute‐force permutation generation, TSP brute‐force    |


#### Interpreting Big O Notation

- We focus on the rate of growth rather than the exact number of operations, which is why constant factors are typically ignored. For example, the function $5n$ is expressed as **$O(n)$**, neglecting the constant factor of 5.
- When an algorithm has multiple terms, only the term with the fastest growth rate is considered important. For example, if the running time is $n^2 + n$, the time complexity simplifies to **$O(n^2)$**, since $n^2$ grows faster than $n$.
- Big O notation describes an upper limit on the growth rate of a function, meaning that if an algorithm has a time complexity of **$O(n)$**, it can also be described as $O(n^2)$ or higher. However, an algorithm with **$O(n^2)$** complexity cannot be described as **$O(n)$**, because Big O does not imply a lower bound on growth.
- Terms that grow as fast as or faster than **$n$** or **$log n$** dominate constant terms. For example, in the complexity **$O(n + k)$**, the term **$n$** dominates, simplifying the overall complexity to **$O(n)$**.

#### Can every problem have an O(1) algorithm?

- Not every problem has an algorithm that can solve it, irrespective of the complexity. For instance, the Halting Problem is undecidable—no algorithm can accurately predict whether a given program will halt or run indefinitely on every possible input.
- Sometimes, we can create an illusion of $O(1)$ complexity by precomputing the results for all possible inputs and storing them in a lookup table (like a hash table). Then, we can solve the problem in constant time by directly retrieving the result from the table. This approach, known as memoization or caching, is limited by memory constraints and is only practical when the number of distinct inputs is small and manageable.
- Often, the lower bound complexity for a class of problems is $O(n)$ or $O(nlogn)$. This bound represents problems where you at least have to examine each element once (as in the case of $O(n)$ ) or perform a more complex operation on every input (as in $O(nlogn)$ ), like sorting. Under certain conditions or assumptions, a more efficient algorithm might be achievable.
  
### Recognising $O(\log n)$ and $O(n \log n)$ running-times

The growth rate of an algorithm almost always comes from **how quickly the remaining work shrinks** as the algorithm executes. Two common patterns are:

| Pattern                                                                   | Typical loop behaviour                               | Resulting time-complexity |
| ------------------------------------------------------------------------- | ---------------------------------------------------- | ------------------------- |
| *Halve (or otherwise divide) the problem each step*                       | $n \to n/2 \to n/4 \dots$                          | $\Theta(\log n)$        |
| *Do a linear amount of work, but each unit of work is itself logarithmic* | outer loop counts down one by one, inner loop halves | $\Theta(n \log n)$      |

Below are four miniature algorithms written in language-neutral *pseudocode* (no Python syntax), followed by the intuition behind each bound.

I. Linear - $\Theta(n)$

```text
procedure Linear(n)
    while n > 0 do
        n ← n − 1
    end while
end procedure
```

*Work left* drops by **1** each pass, so the loop executes exactly $n$ times.

II. Logarithmic - $\Theta(\log n)$

```text
procedure Logarithmic(n)
    while n > 0 do
        n ← ⌊n / 2⌋          ▹ halve the problem
    end while
end procedure
```

Each pass discards half of the remaining input, so only $\lfloor\log\_2 n\rfloor + 1$ iterations are needed.

*Common real examples: binary search, finding the height of a complete binary tree.*

III. Linear-logarithmic - $\Theta(n \log n)$

```text
procedure LinearLogarithmic(n)
    m ← n
    while m > 0 do                ▹ runs n times
        k ← n
        while k > 0 do            ▹ runs log n times
            k ← ⌊k / 2⌋
        end while
        m ← m − 1
    end while
end procedure
```

* **Outer loop:** $n$ iterations.
* **Inner loop:** $\lfloor\log\_2 n\rfloor + 1$ iterations for each outer pass.
* Total work $\approx n \cdot \log n$.

Classic real-world instances: mergesort, heapsort, many divide-and-conquer algorithms, building a heap then doing $n$ delete-min operations.

IV. Squared-logarithmic - $\Theta(\log^2 n)$

```text
procedure LogSquared(n)
    m ← n
    while m > 0 do                ▹ outer loop: log n times
        k ← n
        while k > 0 do            ▹ inner loop: log n times
            k ← ⌊k / 2⌋
        end while
        m ← ⌊m / 2⌋
    end while
end procedure
```

Both loops cut their control variable in half, so each contributes a $\log n$ factor, giving $\log^2 n$. Such bounds appear in some advanced data-structures (e.g., range trees) where *two* independent logarithmic dimensions are traversed.

Rules of thumb:

1. **Log factors come from repeatedly shrinking a quantity by a constant factor.** Any loop of the form `while x > 1: x \gets x / c` (for constant $c > 1$) takes $\Theta(\log x)$ steps.
2. **Multiplying two independent loops multiplies their costs.** An outer loop that counts $n$ times and an inner loop that counts $\log n$ times gives $n \cdot \log n$.
3. **Divide-and-conquer often yields $n \log n$.** Splitting the problem into a constant number of sub-problems of half size and doing $\Theta(n)$ work to combine them recurs to the *Master Theorem* case $T(n) = 2\,T\bigl(n/2\bigr) + \Theta(n) = \Theta(n \log n).$
4. **Nested logarithmic loops stack.** Two independent halving loops give $\log^2 n$; three give $\log^3 n$, and so on.

### Misconceptions

* Formal proof of Big O complexity is rarely necessary in everyday programming or software engineering. However, having a fundamental understanding of theoretical complexity is important when selecting appropriate algorithms, especially when solving complex problems. It aids in understanding the trade-offs between different solutions and predicting the algorithm's performance.
* It's not required to assign Big O complexity for every single function or chunk of code you write. However, if you're dealing with large datasets or performance-critical applications, understanding the time and space complexity of your algorithms and data structures can help you make informed decisions about scalability and efficiency.
* Big O notation is not a predictor of an algorithm's precise running time for a given input size. Instead, it provides an upper bound on the growth rate of the algorithm's running time or space usage as the input size increases. It's a tool to compare the scalability of different algorithms, ignoring implementation details and specific characteristics of the input data.
* In real-world scenarios, the actual running time of an algorithm can be influenced by various factors, including the specific characteristics of the input data, the efficiency of the implementation, and the hardware and software environment in which it runs. Big O notation doesn't account for these factors.
* While it's good to consider performance, it shouldn't come at the cost of code readability and maintainability. Clear, simple code is often more valuable than highly optimized code, especially if the optimizations complicate the code without offering substantial performance improvements. Instead of optimizing every detail, focus on identifying and addressing the actual bottlenecks in your code, as these are the areas where optimizations can make a significant difference.
