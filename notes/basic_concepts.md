## Intro to Data Structures & Algorithms

Data structures and algorithms are key parts of computer science. They help us keep track of and work with data. A data structure is how we save data on a computer, while an algorithm is a set of steps to solve a problem or do a task. Let's go over some basic ideas about data structures and algorithms, why they're important, and how we use them.

## Data Structures

Data structures help us put data on a computer so we can get to it and change it easily. Different data structures are good for different things, and some are made for specific jobs. Here's a list of some common data structures:

* Arrays: An array is a block of memory that holds a certain number of items of the same kind of data. Arrays are good for keeping and finding data, but they can't change size and aren't great for adding or taking away items.
* Stacks: A stack is a line of data that follows the "last-in, first-out" (LIFO) rule. Items are put on top of the stack (pushed) and taken off the top (popped). Stacks are used a lot to make undo features in software.
* Queues: A queue is a line of data that follows the "first-in, first-out" (FIFO) rule. Items are put at the end of the queue (enqueued) and taken from the front (dequeued). Queues are useful when data needs to be handled in a certain order, like tasks in a task queue or events in an event loop.
* Linked lists: A linked list is a line of data with a bunch of nodes. Each node has a value and a link to the next node. Linked lists can change size when needed and are good for easily adding and removing items.
* Trees: A tree is a data structure with nodes in layers. Each node in a tree has one or more child nodes, and the node at the top is called the root. Trees are useful for showing levels of connection, like the structure of a file system.
* Graphs: A graph is a data structure with points (nodes) and lines (edges) connecting them. Graphs can have one-way lines (directed) or two-way lines (undirected). Graphs help us show how things are connected and solve problems like finding the shortest way between two points.

![ds](https://user-images.githubusercontent.com/37275728/185381435-9335db5b-8c9a-4e74-87dc-deac3c0356f1.png)

## Algorithms
Algorithms are like recipes to solve problems or do tasks. They're made to work well and be useful in many areas like computer science, math, and engineering. There are lots of types of algorithms, and we can group them by how they work, how fast they are, and how much space they need.

### What Makes a Good Algorithm:
* Input: the info the algorithm gets.
* Output: the info the algorithm makes.
* Definiteness: each step should be clear and easy to understand.
* Finiteness: the algorithm can't go on forever. It has to stop after some steps.
* Effectiveness: each step should be doable and useful.

### Algorithms vs. Programs
Algorithms should be efficient and stop after some steps, but programs don't always need to be like that. For example, an operating system is a program that runs forever and might do the same thing over and over.

You can use a computer program to make an algorithm, but you don't have to. An algorithm can be explained in plain words or a programming language like Python or Java, without being made into a computer program.

### Types of Algorithms
There are lots of algorithms, and they can be grouped by what they do and how they work. Here are some common types:

* Sorting algorithms put data in a certain order, like from smallest to biggest. Some examples are bubble sort, insertion sort, selection sort, and merge sort.
* Searching algorithms look for a certain item or value in a bunch of data. Some examples are linear search, binary search, and depth-first search.
* Graph algorithms help with problems that have graphs, like finding the shortest way between two points or seeing if a graph is connected. Some examples are Dijkstra's algorithm and the Floyd-Warshall algorithm.
* String algorithms help with problems that have strings, like finding the longest part that two strings share or looking for a pattern in a string. Some examples are the Knuth-Morris-Pratt algorithm and the Boyer-Moore algorithm.

## What Algorithms Do I Need to Know as a Software Engineer?

As a software engineer, you don't need to know every algorithm by heart or be able to make them all. Instead, it's more important to know how to use libraries and packages that already have common algorithms, and to pick the best algorithm for what you're doing based on how fast it is and other things to think about.

Still, learning about algorithms and how they work can be really helpful, especially when you're starting to learn programming. Studying algorithms can help you get better at understanding how programming works and how to solve problems. It can also show you all the different ways to solve problems and what to think about when choosing a solution. But once you know the basics of how algorithms work, you can focus on using libraries and packages to solve problems instead of making algorithms from scratch.

## Understanding Algorithm Complexity

Algorithm complexity is about how long an algorithm takes to run or how much memory it needs when the input size grows. We can look at different kinds of complexity:

* **Best case complexity**: the shortest time or space an algorithm needs for any input of a certain size. For example, if an algorithm has a best case complexity of O(1), it means it always takes the same amount of time, no matter how big the input is.
* **Average case complexity**: the average time or space an algorithm needs for all possible inputs of a certain size. This can be harder to figure out than best case complexity because we have to think about how likely different inputs are and how they affect the algorithm's running time.
* **Worst case complexity**: the longest time or space an algorithm needs for any input of a certain size. This is often the most important kind of complexity because it gives us an idea of the maximum time the algorithm will take.
* **Space complexity**: how much memory an algorithm needs when the input size grows. This matters when designing algorithms because sometimes we don't have enough memory for the algorithm to work well.
* **Time complexity**: how long an algorithm takes when the input size grows. This is the most common kind of complexity because it's usually the main thing we care about when looking at an algorithm's performance.

### How Fast Algorithms Grow

The rate of growth of an algorithm tells us how its running time or space complexity changes when the input size gets bigger. We can use different notations to talk about the rate of growth:

#### O-Notation

O-notation is for the asymptotic upper bound, or the maximum running time or space complexity of an algorithm.

$f(n) = O(g(n))$ means that $f(n)$ grows slower or at the same rate as $g(n)$.

For example, if an algorithm has a time complexity of O(n), its running time is at most a linear function of the input size.

#### Ω-Notation

Ω-notation is for the asymptotic lower bound, or the minimum running time or space complexity of an algorithm.

$f(n) = Ω(g(n))$ means that $f(n)$ grows faster or at the same rate as $g(n)$.

For example, if an algorithm has a time complexity of Ω(n), its running time is at least a linear function of the input size.

#### Θ-Notation

Θ-notation is for the asymptotic average-case complexity, or how an algorithm usually performs.

$f(n) = Θ(g(n))$ means that $f(n)$ grows at the same rate as $g(n)$, both faster and slower.

For example, if an algorithm has a time complexity of Θ(n), its running time is both at most and at least a linear function of the input size.

Remember that these notations only talk about how fast an algorithm grows when the input size gets really big. In real life, the actual running time of an algorithm might be different because of things like the specific input, the computer it's running on, and how the algorithm is implemented.

### Examples of O-Notation

* $O(1)$: Constant time complexity. The algorithm takes the same time no matter how big the input is. Examples: getting an element from an array or looking up a value in a hash table.
* $O(log n)$: Logarithmic time complexity. The algorithm's running time grows logarithmically with the input size. Examples: binary search and inserting an element in a balanced binary search tree.
* $O(n)$: Linear time complexity. The algorithm's running time grows with the input size. Examples: linear search and iterating through an array.
* $O(n log n)$: Linear logarithmic time complexity. The algorithm's running time grows with the input size and the number of operations grows logarithmically. Examples: merge sort and heapsort.
* $O(n^2)$: Quadratic time complexity. The algorithm's running time grows with the square of the input size. Examples: bubble sort and selection sort.
* $O(n^3)$: Cubic time complexity. The algorithm's running time grows with the cube of the input size. Examples: matrix multiplication and finding the transitive closure of a graph.
* $O(2^n)$: Exponential time complexity. The algorithm's running time grows exponentially with the input size. Examples: brute-force solution to the traveling salesman problem and generating all subsets of a set.

![big_o](https://user-images.githubusercontent.com/37275728/185381461-ec062561-1f55-4cf5-a3fa-d4cc0a2c06df.png)

As you can see, the time complexity of an algorithm has a big effect on its performance. It's important to think about the time complexity of an algorithm when deciding which one to use for a certain problem.

### Big-O Rules:

1. Ignore constant factors: When analyzing an algorithm's complexity, constant factors are generally disregarded as they don't influence the overall growth rate. For instance, a running time of $5n$ has the same complexity as $n$ since the constant factor of 5 doesn't impact the growth rate as $n$ increases.
2. Ignore smaller terms: When analyzing an algorithm's complexity, slower-growing terms are generally disregarded in favor of the dominant term. For example, an algorithm with a running time of $n^2 + n$ has a dominant term of $n^2$, so its complexity is $O(n^2)$.
3. Upper bound only: Big O notation gives an upper bound on an algorithm's growth rate. If an algorithm has a complexity of $O(a)$, it's also an $O(b)$ algorithm if $a < b$. However, if an algorithm has a complexity of $O(b)$, it's not necessarily an $O(a)$ algorithm if $a < b$, since Big O notation doesn't provide a lower bound on growth rate.
4. $n$ and $log n$ are "bigger" than any constant: When analyzing an algorithm's complexity, terms that grow at least as fast as $n$ or $log(n)$ are considered "dominant" or "significant". In the complexity $O(n + k)$, the term $n$ is dominant since it grows at least as fast as $n$, so the complexity simplifies to $O(n)$.

### Can every problem have an O(1) algorithm?

* Not all problems can have an algorithm, even if solvable. For example, the Halting problem is undecidable, meaning there is no algorithm that can solve it.
* In some cases, precomputing solutions and storing them in a hash table or other data structure can provide constant-time access. However, this is only feasible if the number of possible inputs is finite and small enough to fit in available storage space.
* For many problems, the best complexity is $O(n)$ or $O(nlogn)$, as the problem requires performing an operation on each input element. In some cases, a more efficient algorithm with a lower complexity, like an $O(1)$ algorithm, may be possible if the problem has specific properties that allow more efficient solutions.

### When do algorithms have O(logn) or O(nlogn) complexity?

The actual complexity of an algorithm depends on how the input size affects the number of iterations of the loop.

Examples of algorithms with different complexities:

1. First algorithm: Complexity of $O(n)$ as running time is directly proportional to input size ($n$). Each loop iteration reduces $n$ by 1, so the number of iterations equals the initial value of $n$.

```python
WHILE n > 0:
    n = n - 1
```

2. Second algorithm: Complexity of $O(log(n))$ as running time is proportional to the number of times the loop can be iterated before $n$ becomes 0. Each loop iteration halves the value of $n$. The number of iterations equals the number of times $n$ can be halved before it becomes 0, which is the same as the number of times the integer value of $log(n)$ can be halved before it becomes 0.

```python
WHILE n > 0:
   n = n / 2
```

3. Third algorithm: Complexity of $O(nlog(n))$ because the outer loop iterates $n$ times and the inner loop iterates $log(n)$ times for each outer loop iteration. The total number of iterations is $n * log(n)$.

```python
m = n
WHILE m > 0:
   k = n
   WHILE k > 0:
      k = k / 2
   m = m - 1
```

4. Fourth algorithm: Complexity of $O(log^2(n))$ because the outer loop iterates $log(n)$ times and the inner loop iterates $log(n)$ times for each outer loop iteration. The total number of iterations is $log^2(n)$.

```python
m = n
WHILE m > 0:
   k = n
   WHILE k > 0:
      k = k / 2
   m = m / 2
```

### Misconceptions

* Formal proof of Big O complexity is rarely necessary in practice, but understanding theoretical complexity can be useful for choosing appropriate algorithms and understanding limitations and trade-offs.
* Understanding the complexity of algorithms and data structures you're using can help make informed decisions about scalability and efficiency, even if defining Big O complexity for every piece of code isn't necessary.
* Big O notation describes the upper bound on an algorithm's running time growth rate but doesn't predict the exact running time for a specific input size. It is a general way to compare scalability of different algorithms and doesn't consider implementation details or input data characteristics.
* The actual running time of an algorithm for a given input size may be affected by factors like implementation, input data characteristics, and hardware and software environments.
* Simple, readable code is often more important than performance optimization at the expense of complexity. Focusing on identifying and addressing actual bottlenecks can be more effective than trying to optimize every aspect of your code.
