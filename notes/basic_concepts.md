## Introduction to Data Structures & Algorithms

Data structures and algorithms are foundational concepts in computer science, playing an essential role in designing efficient software. A data structure defines how we store and organize data on a computer, while an algorithm delineates a step-by-step procedure to perform a task or solve a problem. This article introduces the fundamental aspects of data structures and algorithms, their importance, and how they are applied in computing.

### Data Structures

A data structure organizes data on a computer in a manner that enables efficient access and modification. The choice of the appropriate data structure depends on the specific use case and can significantly impact the performance of an application. Here are some common data structures:
Sure, here are the simplified explanations with the formal terms included:

1. An **array** is like a row of lockers, each numbered in order, where each locker can hold one item of the same type. Formally, an array is a contiguous block of memory that stores a fixed-size sequence of elements of the same type. Arrays are effective for quick access to data by index, but their size cannot change once set, making them less flexible for adding or removing elements.

2. A **stack** is like a stack of plates. You add new plates on top (push), and take plates from the top (pop). This follows the "Last-In, First-Out" (LIFO) principle, meaning the last item added is the first one removed. Stacks are commonly used in programming for managing function calls (function call stack) and 'undo' operations in software applications.

3. A **queue** is like a line at a checkout counter. People join at the back (enqueue) and leave from the front (dequeue). This follows the "First-In, First-Out" (FIFO) principle, where the first item added is the first one removed. Queues are useful for processing items in the order they arrive, such as task scheduling or event handling in computing systems.

4. A **linked list** is like a treasure hunt where each clue (node) points to the next one. Each node contains a value and a reference (pointer) to the next node. This makes linked lists dynamic and efficient for inserting and removing elements at any position in the list.

5. A **tree** is like a family tree, starting with one person (root) and branching out to children (nodes), with each node possibly having its own children. Formally, a tree is a hierarchical data structure composed of nodes arranged in multiple levels. Trees are useful for representing hierarchical relationships, such as filesystem structures or organizational charts.

6. A **graph** is like a network of cities connected by roads. Each city is a node, and each road is an edge connecting two nodes. Edges can be one-way (directed) or two-way (undirected). Graphs are used to model complex relationships and connections between elements, such as social networks, web pages (links), and routes between locations.

![ds](https://user-images.githubusercontent.com/37275728/185381435-9335db5b-8c9a-4e74-87dc-deac3c0356f1.png)

### Algorithms

Algorithms are step-by-step instructions to solve specific problems or perform tasks. They are everywhere in fields like computer science, mathematics, and engineering. To evaluate how good an algorithm is, we often look at its efficiency in terms of time complexity (how long it takes to run) and space complexity (how much memory it uses).

Think of an algorithm like a recipe for cooking. It consists of a series of steps to follow to achieve a specific result. Here are the key characteristics of a good algorithm:

- The data that an algorithm works with is referred to as its **input**, much like the ingredients required to prepare a dish in a recipe.
- Just as a recipe leads to a completed dish, the algorithm produces an **output**, which represents the final result after processing the input.
- It is essential that every step of the algorithm is defined with clarity and precision, ensuring that there is no ambiguity in the process, a concept known as **definiteness**.
- Similar to how a recipe has a defined end point when the dish is ready, an algorithm must have **finiteness**, meaning it will stop after a specific number of steps.
- For an algorithm to be **effective**, each step should be simple, executable, and directly contribute toward reaching the final result, just as every action in a recipe is purposeful and achievable.

#### Algorithms vs. Programs

Understanding the difference between an algorithm and a program is essential. Here’s a simple explanation with formal terms included:

An algorithm is like a high-level blueprint for solving a specific problem. It is abstract and language-independent, detailing a sequence of steps without any specific syntax. You can think of an algorithm as a recipe that outlines a method for solving a problem, and it can be represented in various ways, such as in plain text or as a flowchart.

For example, consider an algorithm for adding two numbers:

```
Step 1: Start
Step 2: Declare variables num1, num2, and sum.
Step 3: Read values into num1 and num2.
Step 4: Add num1 and num2 and store the result in sum.
Step 5: Print sum
Step 6: Stop
```

This algorithm can also be shown as a flowchart:

```
---------------------
|  Start            |
---------------------
        |
        V
-----------------------------
|  Declare num1, num2, sum  |
-----------------------------
        |
        V
------------------------
|  Read num1 and num2  |
------------------------
        |
        V
-----------------------
|  sum = num1 + num2  |
-----------------------
        |
        V
----------------------
|  Print sum         |
----------------------
        |
        V
----------------------
|  Stop              |
----------------------
```

On the other hand, a program is a concrete, language-dependent implementation of an algorithm. It follows the syntax rules of a particular programming language. For instance, the above algorithm can be implemented in Python as:

```python
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
sum = num1 + num2
print("The sum is", sum)
```

Here’s a key point to remember: algorithms are abstract steps that always terminate after a finite number of steps. In contrast, some programs can run indefinitely until an external action stops them. For example, an operating system is a program designed to run continuously in a loop until the computer is turned off.

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

#### Essential Algorithms for Software Engineers

* As a software engineer, mastering every algorithm isn't expected or necessary. Instead, it is more valuable to be proficient in leveraging libraries and packages that encapsulate widely-used algorithms. However, the ability to discern the most effective algorithm for a particular task based on its efficiency, the nature of the problem, and other relevant factors is crucial. 
* Understanding algorithms can significantly augment your problem-solving capabilities, particularly when you're beginning your programming journey. It provides a strong foundation in logical thinking, exposes you to various strategies for problem-solving, and helps you appreciate the nuances involved in choosing the most appropriate solution. After grasping the fundamentals of algorithms, the focus generally shifts towards using pre-built libraries and packages for problem-solving rather than creating algorithms from scratch.

### Understanding Algorithmic Complexity

Algorithmic complexity helps us understand the computational resources (time or space) an algorithm needs as the input size increases. Here’s a breakdown of different types of complexity:

* **Best case complexity** is the minimum time or space an algorithm requires for a given input size. For instance, an algorithm with a best case time complexity of O(1) always runs in constant time, regardless of the input size.
* **Average case complexity** signifies the average time or space an algorithm needs for all possible inputs of a given size. Calculating this can be more challenging because it requires understanding the distribution of possible inputs and their effect on the algorithm's performance.
* **Worst case complexity** indicates the maximum time or space an algorithm may take for any input of a certain size. This type of complexity is often the most critical since it provides an upper bound on the algorithm's execution time, offering predictability.
* **Space complexity** represents the total amount of memory an algorithm needs relative to the input size. This becomes important when memory resources are limited and the algorithm's efficiency is crucial.
* **Time complexity** measures the computational time an algorithm takes as the input size grows. This is the most frequently analyzed type of complexity because the speed of an algorithm often determines its usability.

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

The choice of an algorithm significantly impacts the application's performance, making the understanding of time complexity crucial.

#### Interpreting Big O Notation: Key Rules

- We focus on the rate of growth rather than the exact number of operations, which is why constant factors are typically ignored. For example, the function $5n$ is expressed as **$O(n)$**, neglecting the constant factor of 5.
- When an algorithm has multiple terms, only the term with the fastest growth rate is considered important. For example, if the running time is $n^2 + n$, the time complexity simplifies to **$O(n^2)$**, since $n^2$ grows faster than $n$.
- Big O notation describes an upper limit on the growth rate of a function, meaning that if an algorithm has a time complexity of **$O(n)$**, it can also be described as $O(n^2)$ or higher. However, an algorithm with **$O(n^2)$** complexity cannot be described as **$O(n)$**, because Big O does not imply a lower bound on growth.
- Terms that grow as fast as or faster than **$n$** or **$log n$** dominate constant terms. For example, in the complexity **$O(n + k)$**, the term **$n$** dominates, simplifying the overall complexity to **$O(n)$**.

#### Can every problem have an O(1) algorithm?

- Not every problem has an algorithm that can solve it, irrespective of the complexity. For instance, the Halting Problem is undecidable—no algorithm can accurately predict whether a given program will halt or run indefinitely on every possible input.
- Sometimes, we can create an illusion of $O(1)$ complexity by precomputing the results for all possible inputs and storing them in a lookup table (like a hash table). Then, we can solve the problem in constant time by directly retrieving the result from the table. This approach, known as memoization or caching, is limited by memory constraints and is only practical when the number of distinct inputs is small and manageable.
- Often, the lower bound complexity for a class of problems is $O(n)$ or $O(nlogn)$. This bound represents problems where you at least have to examine each element once (as in the case of $O(n)$ ) or perform a more complex operation on every input (as in $O(nlogn)$ ), like sorting. Under certain conditions or assumptions, a more efficient algorithm might be achievable.
  
#### When do algorithms have O(logn) or O(nlogn) complexity?

The exact time complexity of an algorithm usually stems from how the size of the input affects the execution flow of the algorithm—particularly the loop iterations. 

Consider four example algorithms with differing complexities:

I. **First Algorithm** $O(n)$: Here, the running time is directly proportional to the input size ($n$), as each loop iteration reduces $n$ by 1. Hence, the number of iterations equals the initial value of $n$.

```python
WHILE n > 0:
    n = n - 1
```

II. **Second Algorithm** $O(log(n))$: In this case, the running time is proportional to the number of times the loop can iterate before $n$ reduces to 0. Each loop iteration halves the value of $n$. This equals the number of times you can halve $n$ before it becomes 0, which also corresponds to $log(n)$.

```python
WHILE n > 0:
   n = n / 2
```

III. **Third Algorithm** $O(nlog(n))$: Here, the outer loop iterates $n$ times, and the inner loop iterates $log(n)$ times for each outer loop iteration. Hence, the total number of iterations is $n * log(n)$.

```python
m = n
WHILE m > 0:
   k = n
   WHILE k > 0:
      k = k / 2
   m = m - 1
```

IV. **Fourth Algorithm** $O(log^2(n))$: In this scenario, the outer loop iterates $log(n)$ times, and the inner loop also iterates $log(n)$ times for each outer loop iteration. Consequently, the total number of iterations equals $log^2(n)$.

```python
m = n
WHILE m > 0:
   k = n
   WHILE k > 0:
      k = k / 2
   m = m / 2
```

### Misconceptions

* Formal proof of Big O complexity is rarely necessary in everyday programming or software engineering. However, having a fundamental understanding of theoretical complexity is crucial when selecting appropriate algorithms, especially when solving complex problems. It aids in understanding the trade-offs between different solutions and predicting the algorithm's performance.
* It's not essential to assign Big O complexity for every single function or chunk of code you write. However, if you're dealing with large datasets or performance-critical applications, understanding the time and space complexity of your algorithms and data structures can help you make informed decisions about scalability and efficiency.
* Big O notation is not a predictor of an algorithm's precise running time for a given input size. Instead, it provides an upper bound on the growth rate of the algorithm's running time or space usage as the input size increases. It's a tool to compare the scalability of different algorithms, ignoring implementation details and specific characteristics of the input data.
* In real-world scenarios, the actual running time of an algorithm can be influenced by various factors, including the specific characteristics of the input data, the efficiency of the implementation, and the hardware and software environment in which it runs. Big O notation doesn't account for these factors.
* While it's crucial to consider performance, it shouldn't come at the cost of code readability and maintainability. Clear, simple code is often more valuable than highly optimized code, especially if the optimizations complicate the code without offering substantial performance improvements. Instead of optimizing every detail, focus on identifying and addressing the actual bottlenecks in your code, as these are the areas where optimizations can make a significant difference.
