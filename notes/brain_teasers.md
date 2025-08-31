## Solving Programming Brain Teasers

Programming puzzles and brain teasers are a fun way to sharpen your coding and problem-solving skills. You’ll often see them in technical interviews, where they’re used to test how you think, analyze problems, and come up with efficient solutions. To do well, it helps to practice and build solid strategies for tackling these kinds of challenges.

### General Strategies

When tackling programming puzzles, consider the following strategies:

* Start with a *simple solution* to get a clear grasp of the problem—this often highlights what really needs optimizing later.
* Use *unit tests* to make sure your code works across different inputs, especially tricky edge cases.
* Think about your algorithm’s *time and space complexity* to understand how efficient it is and where it can be improved.
* Pick the *right data structure* (like an array, hash map, or tree) to make your solution faster and easier to reason about.
* Break the problem into *smaller pieces* so it feels less overwhelming and easier to solve step by step.
* Try both *recursive* and *iterative* approaches—you’ll often find one fits the problem more naturally.
* Always keep *edge cases* and *constraints* in mind so your solution doesn’t break with unusual inputs.
* Apply *targeted optimization* only where it matters—improve performance without making the code messy.

### Data Structures

A solid grasp of data structures is helpful for effective programming. Below are some practical strategies and tips to help you use them more confidently and efficiently.

#### Working with Arrays

Arrays are basic data structures that store elements in a continuous block of memory, making it easy to access any element quickly.

* Sorting an array can often simplify many problems, with algorithms like Quick Sort and Merge Sort offering efficient $O(n \log n)$ time complexity. For nearly sorted or small arrays, *Insertion Sort* might be a better option due to its simplicity and efficiency in such cases.
* In sorted arrays, *binary search* provides a fast way to find elements or their positions, working in $O(\log n)$. Be cautious with mid-point calculations in languages that may experience integer overflow due to fixed-size integer types.
* The *two-pointer* technique uses two indices, typically starting from opposite ends of the array, to solve problems involving pairs or triplets, like finding two numbers that sum to a target. It helps optimize both time and space efficiency.
* The *sliding window* technique is effective for solving subarray or substring problems, such as finding the longest substring without repeating characters. It maintains a dynamic subset of the array while iterating, improving overall efficiency.
* *Prefix sums* enable fast range sum queries after preprocessing the array in $O(n)$. Likewise, difference arrays allow efficient range updates without the need to modify individual elements one by one.
* In-place operations modify the array directly without using extra memory. This method saves space but requires careful handling to avoid unintended side effects on other parts of the program.
* When dealing with duplicates, it’s important to adjust the algorithm to handle them appropriately. For example, the two-pointer technique may need to skip duplicates to prevent redundant results or errors.
* When working with large arrays, it’s important to be mindful of memory usage, as they can consume a lot of space. To optimize, try to minimize the space complexity by using more memory-efficient data structures or algorithms. For instance, instead of storing a full array of values, consider using a *sliding window* or *in-place modifications* to avoid extra memory allocation. Additionally, analyze the space complexity of your solution and check for operations that create large intermediate data structures, which can lead to excessive memory consumption. In constrained environments, tools like memory profiling or checking the space usage of your program (e.g., using Python’s `sys.getsizeof()`) can help you identify areas for improvement.
* When using dynamic arrays, it’s helpful to allow automatic resizing, which lets the array expand or shrink based on the data size. This avoids the need for manual memory management and improves flexibility.
* Resizing arrays frequently can be costly in terms of time complexity. A more efficient approach is to resize the array exponentially, such as doubling its size, rather than resizing it by a fixed amount each time.
* To avoid unnecessary memory usage, it's important to pass arrays by reference (or using pointers in some languages) when possible, instead of copying the entire array for each function call.
* For arrays with many zero or null values, using sparse arrays or hash maps can be useful. This allows you to store only non-zero values, saving memory when dealing with large arrays that contain mostly empty data.
* When dealing with multi-dimensional arrays, flattening them into a one-dimensional array can make it easier to perform operations, but be aware that this can temporarily increase memory usage.
* To improve performance, accessing memory in contiguous blocks is important. Random access patterns may lead to cache misses, which can slow down operations, so try to access array elements sequentially when possible.
* The `bisect` module helps maintain sorted order in a list by finding the appropriate index for inserting an element or by performing binary searches.
* Use `bisect.insort()` to insert elements into a sorted list while keeping it ordered.
* Use `bisect.bisect_left()` or `bisect.bisect_right()` to find the index where an element should be inserted.
* Don’t use on unsorted lists or when frequent updates are needed, as maintaining order can be inefficient.
* Binary search operations like `bisect_left()` are `O(log n)`, but `insort()` can be `O(n)` due to shifting elements.

#### Working with Strings

Strings, as sequences of characters, often require special handling due to their immutable nature in some languages and the variety of operations performed on them.

* In languages with *immutable strings*, concatenating inside a loop with `+` can be very slow—$O(n^2)$ time. Instead, use tools like `StringBuilder` in Java or `''.join(list_of_strings)` in Python to bring it down to $O(n)$.
* For *string searching*, algorithms like Knuth-Morris-Pratt (KMP), Rabin-Karp, or Boyer-Moore are much faster than the naive $O(nm)$ approach.
* *Tries (prefix trees)* let you store and retrieve strings with shared prefixes efficiently. They’re common in autocomplete, spell-checkers, and IP routing.
* *Regular expressions* are powerful for pattern matching, but they need careful design—badly written patterns can cause exponential slowdowns.
* Always keep *Unicode and character encoding* (UTF-8, ASCII, etc.) in mind when handling strings, especially with international text or external data. It prevents bugs and ensures proper compatibility.
* For *anagram checks*, compare character counts with arrays or hash maps. For *palindrome checks*, the two-pointer method or comparing against the reversed string gives a simple, efficient solution.
* *Substring and slicing operations* can vary in cost depending on the language. In some (like Python), slices create new strings, while in others (like Java, newer versions), substrings copy data. Always be mindful of hidden overhead.
* When dealing with *very large text processing*, consider using *streaming* or *buffered reading* instead of loading everything into memory at once.
* *Hashing strings* (e.g., rolling hash) is useful for fast lookups, substring checks, or detecting duplicates, especially in algorithms like Rabin-Karp or for building hash-based data structures.
* *Suffix arrays* and *suffix trees* are powerful for advanced text processing tasks like pattern matching, longest common substring, and text compression.
* *String interning* (pooling identical strings) can save memory and speed up equality checks in languages like Java, but overuse can increase GC pressure.
* For *case-insensitive comparisons*, normalize strings first (e.g., `.lower()` in Python, `.toLowerCase()` in Java), but remember locale-specific rules (e.g., Turkish dotted/dotless "i").
* Use *string formatting libraries* (e.g., Python f-strings, Java’s `String.format`) instead of manual concatenation for cleaner, safer, and often more efficient code.
* Be cautious with *regex backtracking traps*—even professional developers can accidentally write patterns that blow up on certain inputs. Tools like regex debuggers can help test patterns.
* *Memory trade-offs* matter: a trie might be faster than a hash map for prefix searches but can use much more memory.
* For *streaming algorithms* (like real-time log processing), sliding window techniques combined with hash maps or deques can efficiently handle substring or frequency problems.

#### Working with Linked Lists

Linked lists are dynamic data structures consisting of nodes that contain data and references to the next (and possibly previous) nodes.

* Choosing the *right type of linked list* depends on the problem requirements. A singly linked list is more memory-efficient and works well when traversal is only needed in one direction. A doubly linked list, on the other hand, is better suited when you need to move both forward and backward or when frequent insertions and deletions at both ends are required.
* *Insertions and deletions* in a linked list are efficient if the position is already known, especially at the head or tail, where they can be done in constant time, $O(1)$. When deleting, it’s crucial to correctly update the previous node’s pointer so the list structure remains intact.
* *Reversing a singly linked list* is done by iterating through the nodes and redirecting each node’s `next` pointer to its predecessor. This takes $O(n)$ time and requires only $O(1)$ extra space, making it a very efficient operation.
* *Cycle detection* can be handled with Floyd’s Tortoise and Hare algorithm. By moving two pointers at different speeds—one slow and one fast—any cycle will eventually cause the two pointers to meet.
* Handling *edge cases* is essential. For example, empty lists, single-node lists, and lists that contain cycles all require special care. Always check for null pointers to avoid runtime errors, especially in languages without built-in safety checks.
* In environments with *manual memory management*, don’t forget to explicitly free memory for nodes that are no longer in use. This prevents memory leaks and helps keep resource usage efficient.
* The *fast and slow pointer technique* (also called the two-pointer method) is widely used with linked lists. Besides cycle detection, it can be applied to find the middle of a list in a single pass: the slow pointer moves one step at a time, while the fast pointer moves two steps. When the fast pointer reaches the end, the slow pointer will be at the middle.
* *Finding the kth node from the end* can also be solved with two pointers. By moving the fast pointer $k$ steps ahead, then advancing both fast and slow pointers together, the slow pointer will land exactly on the kth node from the end. This avoids the need to first compute the length of the list.
* *Merging two sorted linked lists* can be done efficiently using pointers to walk through both lists simultaneously, always choosing the smaller current node to attach next. This is commonly used as part of merge sort for linked lists.
* *Splitting a linked list* into halves is another use case of the fast/slow pointer method. When the fast pointer reaches the end, the slow pointer indicates the midpoint, allowing the list to be divided for algorithms like merge sort.
* *Removing duplicates* from a linked list may require extra memory (such as a hash set) if the list is unsorted. For a sorted linked list, duplicates can be removed in-place by checking adjacent nodes.
* *Palindromic linked lists* can be checked by finding the middle of the list (fast/slow pointer), reversing the second half, and then comparing both halves node by node.
* *Intersection detection* between two linked lists can be solved by advancing two pointers through both lists. If one pointer reaches the end, redirect it to the start of the other list. If the lists intersect, the pointers will eventually meet at the intersection node.
* *Rotating a linked list* by $k$ positions requires computing the length, connecting the tail to the head to form a cycle, and then breaking the cycle at the right position to create the rotated list.
* For very large datasets, *linked lists vs arrays* trade-offs become important. Linked lists excel at dynamic memory usage and frequent insertions/deletions, but they have poorer cache locality and slower random access compared to arrays.

#### Working with Heaps

* When you frequently need the next smallest or largest item, a *priority queue* offers O(1) peek and O(log n) updates, whereas rescanning a list is O(n) per step; e.g., choosing the earliest-deadline task.
* For practical implementations, an array-backed *binary heap* is cache-friendly with O(n) build and O(log n) push/pop, whereas pointer trees add overhead; e.g., worker queues in backend services.
* If the requirement is to repeatedly extract the minimum, a *min-heap* returns it quickly as new items arrive, whereas resorting after each insertion wastes time; e.g., streaming tasks ordered by due time.
* When tracking the current maximum continuously, a *max-heap* maintains the top element efficiently, whereas maintaining a full sorted list is unnecessary; e.g., live high-bid tracking in auctions.
* For top-k results on a stream, a *fixed-size heap* of k items yields O(log k) updates and bounded memory, whereas storing everything and sorting is slower and larger; e.g., top 100 error types today.
* To keep a running median, two *heaps* (max-heap lower half, min-heap upper) give O(log n) updates and O(1) median queries, whereas recomputing from all values is O(n); e.g., live latency dashboards.
* In shortest-path search, an *indexed priority queue* supports decrease-key in O(log n), whereas a plain heap needs lazy deletes that add overhead; e.g., Dijkstra on road networks.
* During k-way merging, a *min-heap* holding one head per list outputs the next item in O(log k), whereas pairwise merges inflate complexity; e.g., merging sorted SSTables in storage engines.
* For time-ordered processing, an event *priority queue* schedules the next timestamped event correctly, whereas FIFO or LIFO queues break ordering; e.g., discrete-event network simulators.
* In heuristic search like A*, a *priority queue* ordered by f=g+h explores promising nodes sooner, whereas BFS/DFS explore many irrelevant nodes; e.g., game map pathfinding.
* To initialize from bulk data, using *heapify* builds a heap in O(n), whereas inserting one item at a time costs O(n log n); e.g., preparing a backlog for scheduling.
* When you must sort in place with bounded memory, *heapsort* provides O(n log n) time and O(1) extra space, whereas mergesort needs additional buffers; e.g., firmware sorting tables.
* If priorities change dynamically, supporting *decrease-key* (or increase-key) avoids duplicates and stale entries, whereas delete-and-reinsert inflates size and time; e.g., reprioritizing tickets as SLAs age.
* Recognize heap-friendly patterns when the loop is “extract best, then insert new,” as a *greedy workflow* matches heap operations well, whereas balanced trees maintain unused total order; e.g., job schedulers.
* Avoid heaps when the task is fast membership checks or deletes by value, because a *hash table* handles contains/remove efficiently, whereas heaps need extra indexing; e.g., deduplicating queued emails.
* When priorities are small integers, a *bucket queue* (array of buckets) gives near O(1) operations, whereas a binary heap remains O(log n); e.g., Dijkstra with weights 0–100.

#### Working with Trees and Binary Trees

Trees are hierarchical data structures with a root node and child nodes. Binary trees are a specific type where each node has at most two children.

* To visit every node systematically, applying *tree traversals* ensures predictable orders (in-, pre-, post-order) and stack-friendly iterations, whereas skipping them leads to ad-hoc scans that miss nodes; e.g., in a BST, in-order prints sorted IDs.
* Searching large key sets is more helpful with a *binary search tree* because ordered left/right children give O(log n) searches in balanced cases, while omitting this structure can degrade to linear scans; for instance, finding a user ID among thousands.
* To keep operations predictable, maintaining a *balanced BST* uses rotations to preserve logarithmic height, whereas ignoring balance can turn inserts and lookups into near-linear time; e.g., repeatedly adding sorted timestamps.
* For always retrieving the highest-priority item first, a *heap* gives O(1) peek and O(log n) updates, but without it you may rescan a list each time; think of scheduling the next job on a build server.
* Storing priorities in an array-backed *binary heap* enables O(n) build-heap and in-place heapsort, while not using it can increase memory use and sort time; e.g., turning a backlog into a sorted release order.
* When processing a tree by layers, using *level-order traversal* with a queue visits nodes breadth-first, whereas skipping it complicates tasks like shortest unweighted paths; for example, printing org-chart levels.
* Measuring *tree height* clarifies depth-related performance and balance, while omitting it hides skew that slows operations; e.g., monitoring API routing trees for growth after deployments.
* For pairwise relationships, computing the *lowest common ancestor* answers ancestor queries quickly via parent pointers or preprocessing, whereas not doing so forces repeated climbs; e.g., finding a shared manager in an org chart.
* Speeding prefix queries becomes easier with a *trie* that stores characters along edges for O(length) lookups, while alternatives may scan many strings; e.g., autocomplete for product codes.
* Handling many range updates and queries benefits from a *segment tree* that delivers O(log n) operations, whereas naive recomputation per query is slower; for example, maintaining rolling sales sums per day range.
* When you only need prefix sums, a *Fenwick tree* offers compact O(log n) updates and queries, while skipping it can force O(n) recomputation; e.g., live leaderboards that update scores.
* Representing hierarchical data with an *N-ary tree* models multiple children per node so traversals remain organized, whereas flattening loses parent–child context; e.g., folder structures with many subfolders.
* Viewing a structure as a *tree (graph)* highlights it is a connected acyclic graph with n−1 edges, while ignoring this view can block reuse of helpful DFS/BFS tools; e.g., validating a dependency tree has no cycles.
* To store or transmit structures, applying *serialization* via preorder with nulls or level-order arrays preserves shape, while omitting it risks reconstruction errors; e.g., saving a quiz logic tree between sessions.
* On disk-backed indexes, choosing a *B-Tree* (or B+ Tree) keeps nodes wide to reduce I/O so searches stay near logarithmic, whereas simple binary trees cause many random reads; e.g., database primary-key lookups.

#### Working with Graphs

Graphs consist of vertices (nodes) and edges connecting them, used to represent complex relationships.
I. *Graph Representations*:

* On sparse graphs, using an *adjacency list* reduces memory and speeds neighbor iteration, whereas choosing a dense structure wastes space and slows scans; for example, a road map where towns link to few highways.
* In dense networks, choosing an *adjacency matrix* enables O(1) edge checks, whereas relying on lists requires linear searches per check; for example, a tightly meshed data-center fabric.

II. *Graph Traversal Algorithms*:

* When exploring deep structures, applying *depth-first search* follows long paths with backtracking, whereas unguided exploration may revisit nodes and miss structure; for example, solving a maze with dead ends.
* For fewest-hop queries, running *breadth-first search* visits nodes level by level to return shortest unweighted paths, whereas depth-first order can yield longer routes; for example, finding minimal connections between users in a social network.

III. *Cycle Detection*:

* In directed graphs, implementing *cycle detection* via DFS with a recursion stack flags back edges, whereas skipping the stack conflates exploration with cycles; for example, validating package import orders.
* On undirected graphs, performing *cycle detection* by checking revisits to a non-parent neighbor reveals loops, whereas ignoring the parent test raises false alarms; for example, auditing redundant links in a LAN.

IV. *Shortest Path Algorithms*:

* With non-negative weights, using *Dijkstra’s algorithm* and a priority queue yields shortest paths efficiently, whereas arbitrary relaxation can be slower or incorrect; for example, computing fastest driving times.
* When negative edges are possible, selecting *Bellman–Ford* both finds shortest paths and reports negative cycles, whereas Dijkstra may return wrong distances; for example, detecting currency-exchange arbitrage.
* For all-pairs needs on moderately dense graphs, applying *Floyd–Warshall* precomputes every distance in O(n³), whereas repeating many single-source runs adds overhead; for example, planning shipping costs between warehouses and stores.

V. *Minimum Spanning Trees (MST)*:

* To grow a low-cost backbone, running *Prim’s algorithm* adds the cheapest edge to the current tree, whereas unguided choices can inflate total weight; for example, wiring campus buildings with minimal cable.
* When edges are easy to sort, employing *Kruskal’s algorithm* accepts lightest edges while Union-Find blocks cycles, whereas naive addition can create loops; for example, designing a minimal road network among towns.

VI. *Network Flow Algorithms*:

* In capacity networks, iterating augmenting paths with the *Ford–Fulkerson method* increases flow until none remain, whereas treating edges independently leaves throughput unused; for example, pushing more water through a pipe system.
* To control search effort, adopting *Edmonds–Karp* chooses shortest augmenting paths by BFS, whereas arbitrary choices may require many iterations; for example, allocating bandwidth across shared links.

VII. *Other Important Concepts*:

* For acyclic dependencies, performing *topological sorting* produces a valid task order, whereas ignoring it risks starting work before prerequisites; for example, scheduling courses with prerequisites.
* On directed graphs, computing *strongly connected components* via Kosaraju or Tarjan groups mutually reachable nodes, whereas skipping this step hides tightly coupled modules; for example, isolating service clusters in a microservice graph.
* For conflict separation, checking *bipartite graphs* via BFS/DFS enables 2-coloring and reveals odd cycles, whereas ad-hoc coloring may waste time and colors; for example, assigning exam slots so no shared-course students collide.

#### Working with Hash Tables

Hash tables store key-value pairs for efficient lookup, insertion, and deletion.

* When *choosing a good hash function*, ensure it distributes keys uniformly across the table to reduce the likelihood of collisions. For custom objects, it's important to override hash functions carefully, ensuring they are consistent and align with the object’s equality logic.
* To deal with *collisions*, two main methods are commonly used: *Chaining*, where multiple elements that hash to the same index are stored in a linked list or another structure at that index. *Open addressing*, which resolves collisions by finding another empty slot through probing methods, such as linear probing, quadratic probing, or double hashing.
* The *load factor and resizing* are important aspects of hash table management. The load factor, which is the ratio of the number of elements to the number of buckets, should be monitored. When the load factor exceeds a certain threshold (often around 0.7), it's time to resize and rehash the table to maintain performance.
* Always use *immutable keys* in a hash table to avoid complications from key mutation. If a key changes after insertion, it can corrupt the structure of the hash table and lead to retrieval failures.
* Hash tables have numerous *applications*, including frequency counting, caching, indexing, and implementing associative arrays like dictionaries or maps in various programming languages.
* While hash tables offer *$O(1)$ average-case time complexity*, it’s important to understand that the worst-case time complexity can degrade to $O(n)$ if the hash function leads to many collisions, particularly when the load factor is too high.

### Algorithms

Mastering algorithms is helpful for solving programming problems more efficiently by understanding patterns and techniques that reduce time and space usage.

#### Two-Pointer Technique

Use two pointers when:

* The data is **sorted** (or can be sorted), and you need **pairs/triplets** that satisfy a condition (e.g., sum to a target).
* The condition is **monotonic** as pointers move (moving one side predictably increases/decreases the value you’re comparing).

Typical uses: 2-Sum (sorted), 3-Sum (outer loop + two pointers), merging intervals, palindrome checks, removing duplicates, sliding-window constraints.

**How it works**

* Before searching for pairs in a sorted array, set the *pointers* `left` to index 0 and `right` to index n−1, which is useful because without this setup you may miss edge combinations or scan redundantly (e.g., starting at the ends of prices [1,2,9,11] for budget 13 quickly reveals 2+11).
* During the scan, continue while the *condition* `left < right` so that you stop before indices cross, whereas omitting this check can reuse the same element or cause an out-of-bounds access (e.g., halting when `left == right` prevents pairing one ticket price with itself).
* When the current sum equals the *target*, record the pair and move both pointers inward, but if the sum is too small move `left` rightward and if too large move `right` leftward, and skipping these directional moves would prolong the search or miss valid pairs (e.g., item prices [1,3,4,7,10] with budget 11 yield 1+10 then 3+7).
* After recording a valid pair, advance *indices* past duplicate values on both sides to avoid repeats, whereas failing to skip duplicates will emit the same pair multiple times (e.g., with prices [1,1,2,3,4,4] for 5 you keep {1,4} and {2,3} once each).
* In terms of performance, a single pass runs in linear *time* O(n) with O(1) extra space after an O(n log n) sort, whereas omitting sorting or pointer discipline often devolves into quadratic checks with nested loops (e.g., ~10,000 versus ~50,000,000 comparisons on 10,000 items).

**Walkthrough example — all pairs summing to 10**

Array (sorted): `[1, 2, 3, 4, 5, 6, 7, 8, 9]`

Start
`left → 1` … `right → 9` → `1 + 9 = 10` ✓ record `(1,9)` → move both inward

Next
`left → 2`, `right → 8` → `2 + 8 = 10` ✓ record `(2,8)` → move both

Next
`left → 3`, `right → 7` → `3 + 7 = 10` ✓ record `(3,7)` → move both

Next
`left → 4`, `right → 6` → `4 + 6 = 10` ✓ record `(4,6)` → move both

Stop when `left >= right`.

Two quick counter-examples for moves:

* **Too small:** `1 + 8 = 9 < 10` → move `left` rightward.
* **Too large:** `2 + 9 = 11 > 10` → move `right` leftward.

**Variants you’ll use often**

* When finding zero-sum triplets, apply the *3-sum* pattern by sorting and for each index scanning `i+1…n−1` with two pointers while skipping duplicates of `i` and inner pointers, which is useful because omitting sorting or duplicate skipping causes missed or repeated triplets (e.g., from `[-4,-1,-1,0,1,2]` you report `[-1,-1,2]` and `[-1,0,1]` once).
* If you only need to know whether any pair reaches the target, treat the task as an *existence* check and stop at the first hit, whereas continuing the scan enumerates all pairs and—without duplicate skipping—repeats results (e.g., with target `10` in `[1,3,7,7,9]` you may stop at `3+7` or keep scanning to list it once despite the second `7`).
* For range constraints over contiguous elements, use a *sliding window* by expanding `right` to grow and contracting `left` to restore the constraint, whereas moving pointers only in one direction can overshoot and miss beneficial ranges (e.g., counting subarrays with sum ≤ `8` in `[2,3,1,2,4,3]` or tracking at most `2` distinct items in a rolling shopping cart).

#### Recursion

I. *Recursion* works by breaking a problem into smaller instances of itself, with each call reducing the size of the problem.

II. Recursion process includes:

- Defining a clear *base case* to ensure that recursion terminates when the simplest version of the problem is solved.
- Ensuring that the *recursive case* moves toward the base case by reducing the problem’s size or complexity with each call.
- Verifying the *correctness* of your recursion logic to ensure it mirrors the structure of the problem.

III. Consider *stack overflow* when recursion depth is too great. You can either switch to an iterative approach or use tail recursion optimization (if supported by the language). *Memoization* is another technique to improve efficiency by caching results of recursive calls to avoid redundant computations.

```
factorial(4)
|
|---> 4 * factorial(3)
           |
           |---> 3 * factorial(2)
                      |
                      |---> 2 * factorial(1)
                                 |
                                 |---> 1 * factorial(0)
                                            |
                                            |---> Base case: 1
```

#### Backtracking

I. *Backtracking* is well-suited for problems that require exploring all potential configurations, such as puzzles like Sudoku, the N-Queens problem, or combinatorial tasks.

II. *Implementation tips* for backtracking include:

- Clearly defining how to represent the *current state* of the problem.
- Using *constraints checking* before progressing to ensure that the current path meets the problem's criteria, which helps prune invalid paths early.
- Recursively *exploring* valid options by modifying the state and recursively diving deeper into the solution space.
- After exploring each path, *backtracking* involves undoing the last change and trying the next alternative, ensuring all possible solutions are considered.
- Consider *optimizations* such as using heuristics to explore more promising paths first.

III. A classic example is solving the *N-Queens problem*, where queens are placed row by row, and conflicts are resolved by backtracking when necessary.

*Step 1: Start with an empty board.*

- Place a queen in Row 1, Column 1.
- Try placing queens row by row.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

*Step 2: Move to Row 2.*

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Conflict! (Diagonal from Queen in Row 1).
- Try Column 3 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   | Q |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

*Step 3: Move to Row 3.*

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   | Q |   |
+---+---+---+---+
|   | Q |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

*Step 4: Move to Row 4.*

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Conflict! (Same column as Queen in Row 3).
- Try Column 3 → Conflict! (Diagonal from Queen in Row 2).
- Try Column 4 → Conflict! (Diagonal from Queen in Row 1).
- No valid positions! (All columns conflict).
- Backtrack: Remove the queen from Row 3, Column 2.

*Step 5: Try other possibilities in Row 3.*

- Try Column 3 → Conflict! (Diagonal from Queen in Row 1).
- Try Column 4 → Conflict! (Diagonal from Queen in Row 2).
- No valid positions in Row 3.
- Backtrack: Remove the queen from Row 2, Column 3.

*Step 6: Try other possibilities in Row 2.*

- Try Column 4 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   | Q |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

*Step 7: Move to Row 3.*

- Try Column 1 → Conflict! (Same column as Queen in Row 1).
- Try Column 2 → Place Queen.

```
+---+---+---+---+
| Q |   |   |   |
+---+---+---+---+
|   |   |   | Q |
+---+---+---+---+
|   | Q |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
```

Continue exploring alternatives and backtracking as necessary until all solutions are found.

#### Dynamic Programming

I. *Dynamic programming* is used to solve optimization problems by breaking them down into overlapping subproblems with an optimal substructure, meaning solutions to smaller subproblems can be reused to solve larger problems.
  
II. There are two primary *approaches* to dynamic programming:

- The *top-down approach (memoization)* involves using recursion while caching the results of subproblems to avoid redundant computations.
- The *bottom-up approach (tabulation)* builds a solution iteratively by solving the smallest subproblems first and using their solutions to solve larger subproblems.
  
III. Some steps that might be taken in dynamic programming:

- *Defining the subproblems* to break the main problem into manageable parts.
- *Identifying the state variables* that uniquely define each subproblem.
- Establishing a *recurrence relation* to compute the solution of each subproblem based on smaller subproblems.
- Proper *initialization* of base cases in a table or memoization cache.
- Determining the correct *iteration order* to fill the DP table for bottom-up approaches.

IV. *Space optimization* is often possible by realizing that only a few recent states are needed, reducing space complexity.
  
V. Classic examples include problems like the Fibonacci sequence, the Knapsack problem, or calculating the minimum edit distance between two strings.

```
DP Table (Rows = Items, Columns = Knapsack Capacities):

  Capacity ->  0   1   2   3   4   5   6   7
  Item 0     [ 0   0   0   0   0   0   0   0 ]  (Base case: No items)
  Item 1     [ 0   1   1   1   1   1   1   1 ]  (Include Item 1)
  Item 2     [ 0   1   1   4   5   5   5   5 ]  (Include Item 2)
  Item 3     [ 0   1   1   4   5   6   6   9 ]  (Include Item 3)
  Item 4     [ 0   1   1   4   5   7   8  11 ]  (Include Item 4)
```

*How the Table Is Filled*

For each cell $DP[i][w]$ if the weight of the item $i$ is less than or equal to the current capacity $w$, choose the maximum of:

- Value without including the item ($DP[i-1][w]$).
- Value including the item ($DP[i-1][w-\text{weight}[i]] + \text{value}[i]$).

*Visualization of Choices*

I. For *Item 1* (Weight = 1, Value = 1):

```
Capacity = 0 → Can't include Item 1 → DP[1][0] = 0
Capacity = 1 → Include Item 1 → DP[1][1] = 1
Capacity = 2 → Include Item 1 → DP[1][2] = 1
...
Capacity = 7 → Include Item 1 → DP[1][7] = 1
```

II. For *Item 2* (Weight = 3, Value = 4):

```
Capacity = 0 → Can't include Item 2 → DP[2][0] = 0
Capacity = 3 → Include Item 2 → DP[2][3] = 4
Capacity = 4 → Include Item 2 → DP[2][4] = 5
...
Capacity = 7 → Include Item 2 → DP[2][7] = 5
```

III. Continue for all items, progressively updating the table.

*Extract the Solution*

To find the maximum value look at the last cell: $DP[4][7] = 11$.

To find the items included trace back from $DP[4][7]$, checking where values changed:

- $DP[4][7] → Include Item 4$
- $DP[3][3] → Include Item 3$

*Final Knapsack Contents:*

- Item 3 (Weight 4, Value 5)
- Item 4 (Weight 3, Value 7)
- Total Weight = 7, Total Value = 11

### Greedy Algorithms

I. *Greedy algorithms* are used when making a locally optimal choice at each step leads to a globally optimal solution.
  
II. The two *characteristics* of greedy algorithms are:

- *Optimal substructure*, meaning the overall solution incorporates optimal solutions to subproblems.
- The *greedy choice property*, where making the best local decision at each step results in the globally best solution.

III. Common *implementation tips* for greedy algorithms include:

- *Sorting* the input data according to a specific criterion before applying the greedy strategy.
- Always ensure the greedy choice leads to an optimal solution by providing a *proof of correctness* or counterexamples.

IV. Examples of greedy algorithms include the activity selection problem, Huffman coding, and algorithms for finding minimum spanning trees (Prim's and Kruskal's).

*Example Huffman coding Input*:

Characters: $[A, B, C, D, E, F]$  

Frequencies: $[5, 9, 12, 13, 16, 45]$

*Build a Min-Heap*

Create a priority queue (min-heap) with the characters and their frequencies.

```
Initial Min-Heap:
    5(A)  9(B)  12(C)  13(D)  16(E)  45(F)
```

*Build the Huffman Tree*

Combine the two smallest frequency nodes into a new node. Repeat until there is one tree.

I. Combine 5(A) and 9(B):

```
 (14)
 /  \
5(A) 9(B)
```

Updated Heap: $[12(C), 13(D), 14(AB), 16(E), 45(F)]$

II. Combine 12(C) and 13(D):

```
 (25)
 /  \
12(C) 13(D)
```

Updated Heap: $[14(AB), 16(E), 25(CD), 45(F)]$

III. Combine 14(AB) and 16(E):

```
 (30)
 /  \
14(AB) 16(E)
```

Updated Heap: $[25(CD), 30(ABE), 45(F)]$

IV. Combine 25(CD) and 30(ABE):

```
 (55)
 /  \
25(CD) 30(ABE)
```

Updated Heap: $[45(F), 55(CDABE)]$

V. Combine 45(F) and 55(CDABE):

```
Tree:
         (100)
         /    \
      45(F)  55(CDABE)
       /      \
    25(CD)   30(ABE)
    /   \     /    \
 12(C) 13(D) 14(AB) 16(E)
                  /   \
               5(A)   9(B)
```

*Assign Binary Codes*

Traverse the tree to assign codes:

- Left edge = `0`
- Right edge = `1`

```
Codes:
A = 000
B = 001
C = 100
D = 101
E = 01
F = 11
```

*Final Huffman Tree Diagram:*

```
Tree:
                        (100)
                       /     \
                    (45)     (55)
                   /         /    \
                (F)      (25)    (30)
                        /   \     /   \
                     (C)   (D) (14)  (E)
                                 /  \
                              (A)  (B)
```

#### Divide and Conquer

I. The *divide and conquer* strategy solves problems by dividing them into smaller subproblems, solving those independently, and then combining their solutions.
  
II. *Implementation tips* for divide and conquer:

- Use *recursion* to divide the problem, with each recursive call handling a subproblem.
- Pay attention to the *combine step*, as the efficiency of combining subproblem solutions can affect the overall performance.
- Define *base cases* for small subproblems that can be solved directly without further division.

III. Examples of divide and conquer algorithms include Merge Sort, Quick Sort, and Binary Search.

### Sorting Algorithms

Sorting algorithms are fundamental to computer science and programming. They are used to rearrange elements in a list or array so that they follow a specific order (ascending or descending). Efficient sorting is a first step for optimizing other algorithms (like search and merge algorithms) that require input data to be in sorted lists. Understanding the different sorting algorithms, their time and space complexities, stability, and suitable use cases is essential for problem-solving and technical interviews.

#### Overview of Common Sorting Algorithms

Below is a detailed comparison of commonly used sorting algorithms:

| *Algorithm*       | *Average Time Complexity* | *Worst-Case Time Complexity* | *Space Complexity* | *Stability* | *Best Use Case*                            | *Notes*                                   |
|---------------------|-----------------------------|-------------------------------|----------------------|---------------|----------------------------------------------|---------------------------------------------|
| *Bubble Sort*     | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Stable        | Educational purposes, small datasets         | Simple but inefficient for large datasets   |
| *Insertion Sort*  | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Stable        | Nearly sorted or small datasets              | Efficient for small or nearly sorted datasets |
| *Selection Sort*  | $O(n^2)$                | $O(n^2)$                  | $O(1)$           | Unstable      | Small datasets, when memory is limited       | Inefficient for large datasets             |
| *Merge Sort*      | $O(n \log n)$           | $O(n \log n)$             | $O(n)$           | Stable        | Large datasets, linked lists                 | Requires additional memory for merging     |
| *Quick Sort*      | $O(n \log n)$           | $O(n^2)$                  | $O(\log n)$      | Unstable      | Large datasets, general-purpose sorting      | Pivot selection strategy affects performance |
| *Heap Sort*       | $O(n \log n)$           | $O(n \log n)$             | $O(1)$           | Unstable      | Large datasets, in-place sorting             | Efficient with minimal memory usage        |
| *Radix Sort*      | $O(nk)$                 | $O(nk)$                   | $O(n + k)$       | Stable        | Large datasets with integer keys             | Non-comparative sorting algorithm          |
| *Counting Sort*   | $O(n + k)$              | $O(n + k)$                | $O(k)$           | Stable        | Small range of integer keys                  | Efficient when range $k$ is small      |
| *Tim Sort*        | $O(n \log n)$           | $O(n \log n)$             | $O(n)$           | Stable        | Real-world data, hybrid sorting              | Default sorting algorithm in Python        |
| *Bucket Sort*     | $O(n + k)$              | $O(n^2)$                  | $O(n)$           | Stable        | Uniformly distributed data                   | Divides elements into buckets              |
| *Shell Sort*      | $O(n \log n)$ to $O(n^2)$ | $O(n^2)$            | $O(1)$           | Unstable      | Medium-sized datasets                        | Improves upon Insertion Sort               |

#### General Tips for Sorting Algorithms

- It’s important to *understand the data* when selecting a sorting algorithm. Factors such as the size of the dataset, its distribution, and the data type being sorted can significantly influence the choice of algorithm.
- If the *stability requirement* is important, meaning the relative order of equal elements must be preserved, you should opt for stable sorting algorithms like Merge Sort or Tim Sort.
- When memory is a concern, *in-place sorting* algorithms, such as Quick Sort or Heap Sort, are preferable because they require minimal additional memory.
- Consider the *time complexity trade-offs* when choosing a sorting algorithm. While Quick Sort is generally fast, its performance can degrade to $O(n^2)$ in the worst case if not implemented carefully.
- *Hybrid approaches* like Tim Sort, which combines Merge Sort and Insertion Sort, are designed to optimize performance by leveraging the strengths of multiple sorting techniques.

#### Practical Applications

- *Merge Sort* is particularly useful for sorting linked lists since it does not require random access to the elements.
- *Quick Sort* is often chosen for general-purpose sorting due to its efficiency in the average case and its ability to sort in-place.
- *Counting Sort* and *Radix Sort* are effective when sorting integers within a known and limited range, offering linear-time complexity under the right conditions.
- *Heap Sort* is a good option when memory usage is restricted and a guaranteed $O(n \log n)$ time complexity is necessary.
- *Insertion Sort* is ideal for very small datasets or as a subroutine in more complex algorithms due to its simplicity and efficiency on nearly sorted data.

### Bit Manipulation

Bit manipulation involves algorithms that operate directly on bits, the basic units of data in computing. By leveraging bit-level operations, you can achieve performance optimizations, reduce memory usage, and solve certain problems more elegantly. Bit manipulation is particularly useful in systems programming, cryptography, graphics, and competitive programming.

#### Fundamental Concepts

- A solid grasp of *binary representation* is necessary for working with bitwise operations. In binary, each digit (or bit) represents a power of 2, starting with the least significant bit (LSB) on the right, which corresponds to $2^0$, and increasing as you move left.
- *Signed and unsigned integers* differ in how they represent numbers. *Unsigned integers* can only represent non-negative values, while *signed integers* use the most significant bit (MSB) as a sign bit, with 0 representing positive numbers and 1 representing negative numbers, typically using two's complement representation.
- *Bitwise operators* are tools for manipulating individual bits. The *AND (`&`)* operator produces 1 only when both corresponding bits are 1, making it useful for masking bits. The *OR (`|`)* operator sets a bit to 1 if at least one of the corresponding bits is 1, often used for setting bits.
- The *XOR (`^`)* operator produces 1 when the bits are different, useful for toggling bits or swapping values. The *NOT (`~`)* operator flips all bits, performing a bitwise negation.
- The *left shift (`<<`)* operation shifts bits to the left, filling with zeros from the right, effectively multiplying the number by powers of two. Conversely, *right shift (`>>`)* operations shift bits to the right, with two variations: *logical shifts*, which fill with zeros from the left (used for unsigned integers), and *arithmetic shifts*, which preserve the sign bit, used for signed integers.

#### Bit Manipulation Techniques

- To *set a bit* at position $n$ to 1, the operation `number |= (1 << n)` can be used. This works by left-shifting 1 by $n$ positions to create a mask with only the $n$-th bit set, and then applying bitwise OR to modify the original number.
- To *clear a bit* at position $n$, use the operation `number &= ~(1 << n)`. Here, 1 is left-shifted by $n$ and negated to form a mask where only the $n$-th bit is 0, and applying bitwise AND clears that bit.
- To *toggle a bit* at position $n$, the operation `number ^= (1 << n)` is used. By left-shifting 1 by $n$ and applying XOR, the target bit at $n$ is flipped.
- To *check if a bit* at position $n$ is set to 1, the operation `(number & (1 << n)) != 0` is employed. It works by left-shifting 1 by $n$ and applying bitwise AND; a non-zero result indicates the bit is set.
- To *clear the least significant bit (LSB)*, the operation `number &= (number - 1)` is effective. Subtracting 1 flips all bits from the LSB onward, and applying AND clears the lowest set bit.
- To *isolate the least significant bit*, the operation `isolated_bit = number & (-number)` is used. In two’s complement, `-number` is the bitwise complement plus one, so ANDing it with `number` isolates the LSB.
- To *count the set bits* (Hamming weight) in a number, Kernighan's Algorithm is applied using the following code:

```c
int count = 0;
while (number) {
    number &= (number - 1);
    count++;
}
```

This works by repeatedly clearing the LSB and incrementing the count.

- To *check if a number is a power of two*, the condition `(number != 0) && ((number & (number - 1)) == 0)` is used. This works because powers of two have only one set bit, and subtracting 1 flips all bits after that set bit, resulting in zero when ANDed.
- To *swap two variables* without using a temporary variable, the following sequence is used:

```c
a ^= b;
b ^= a;
a ^= b;
```

This sequence of XOR operations swaps the values of `a` and `b` without needing extra space.

- To *reverse the bits* in a number, bitwise operations and shifting can be used to swap bits from opposite ends, moving towards the center of the number. This is commonly achieved using a loop or bit manipulation techniques to systematically reverse bit positions.

#### Bit Masks

- A *bitmask* is a binary pattern used to select or manipulate specific bits within a byte or word, enabling efficient operations on particular bits of a number.
- *Common uses of bitmasks* include applications such as feature flags, where each bit represents a boolean option or setting, and permission sets in file systems, where bits represent different permissions like read, write, or execute.
- *State representation* is another common use, where multiple boolean states are stored in a single integer, allowing efficient space usage and manipulation of these states.
- To *create a bitmask* that selects specific bits, you can combine shifts and bitwise OR. For example, to create a mask for bits 0 and 3, the operation `mask = (1 << 0) | (1 << 3)` will set only those bits to 1.

#### Bit Shifting Tricks

- *Left shifting* (`<<`) is a useful technique for *multiplying by powers of two*. For instance, `number << 3` multiplies `number` by $2^3 = 8$, which is a fast alternative to regular multiplication.
- Similarly, *right shifting* (`>>`) can be used for *dividing by powers of two*. For example, `number >> 2` divides `number` by $2^2 = 4$, making it an efficient way to handle division for unsigned integers or logical shifts.
- To *extract specific bits* from a number, you can use a combination of shifting and masking. For instance, to extract bits from position $p$ to $p + n - 1$, the operation `(number >> p) & ((1 << n) - 1)` can be applied. This shifts the target bits to the right and uses a mask to isolate only those bits.

#### Cautions and Best Practices

- In programming, it is important to note that *bitwise operators* have lower precedence than arithmetic and relational operators, so parentheses should be used to ensure the correct order of operations.
- When working with shifts, be aware that *arithmetic shifts* (using `>>`) preserve the sign bit in signed integers, which is useful when working with negative numbers.
- Some languages, like Java, also support *logical shifts*, represented as `>>>`, which shift zeros into the high-order bits regardless of the sign of the number.
- *Portability* can be a concern in bit manipulation code because differences in integer sizes and endianness across various systems may affect how the code behaves.
- Be careful to avoid *overflow and underflow* when performing shifts, as shifting bits beyond the size of the data type can lead to unintended results.
- While bit manipulation can be powerful, excessive use can hurt *readability*. To make the code easier to maintain, it’s a good practice to include comments and, where appropriate, use macros or inline functions.

### List of problems

#### Minimum deletions to make valid parentheses

Given a string of parentheses, determine the minimum number of parentheses that need to be removed to make the string valid. This can be solved using a stack data structure to track the open parentheses as we iterate through the string. If we encounter an open parenthesis, we add it to the stack. If we encounter a closing parenthesis, we check if there is a matching open parenthesis on the top of the stack. If there is, we pop the open parenthesis from the stack. If there is not, we add the closing parenthesis to a list of characters to remove. After we have processed the entire string, we remove the remaining open parentheses from the stack.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/deletions_to_make_valid_parentheses)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/deletions_to_make_valid_parentheses)

#### Is palindrome after at most one char delete?

Determinine whether a string can be transformed into a palindrome by deleting at most one character. This can be solved using a two pointer approach, where we start from both ends of the string and move towards the middle. If we encounter a pair of characters that are not equal, we have three options: delete the character at the left pointer, delete the character at the right pointer, or delete both characters. We check if any of these options results in a palindrome and return the result.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/is_palindrome_after_char_deletion)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/is_palindrome_after_char_deletion)

#### K closest points to origin 	

Find the K points in a list of points that are closest to the origin (0, 0). This can be solved using a min heap data structure, where we store the K closest points so far. As we iterate through the list of points, we compute the distance from each point to the origin and add it to the heap if it is among the K closest points so far.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/k_closest_points)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/k_closest_points)

#### Subarray sum equals K 	

Find a contiguous subarray of an array that has a sum of K. This can be solved using a sliding window approach, where we maintain a running sum of the elements in the window and move the window through the array until we find a subarray with the desired sum.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/subarray_sum)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/subarray_sum)

#### Add numbers given as strings 	

Add two numbers represented as strings. This can be solved by treating the strings as arrays of digits and using a carry variable to keep track of the carryover from one place value to the next.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/add_string_numbers)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/add_string_numbers)

#### Dot product of two sparse vectors 	

Compute the dot product of two sparse vectors, where a vector is represented as a list of (index, value) pairs. This can be solved by iterating through both vectors and adding up the products of the values at the same index.
 
 
* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/sparse_vectors_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/sparse_vectors_product)

#### Range sum of BST 	

Compute the sum of the values of all the nodes in a binary search tree within a given range. This can be solved using a recursive in-order traversal of the tree, where we add the value of each node to the sum if it is within the range.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/range_sum_of_bst)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/range_sum_of_bst)

#### Product of array except self 	

Compute an array where each element is the product of all the other elements in the input array. This can be solved using two pass approach, where we first compute the product of all the elements before each index and then compute the product of all the elements after each index.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/array_product)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/array_product)

#### Convert BST to sorted doubly linked list 

Convert a binary search tree to a sorted doubly linked list. This can be solved using a recursive in-order traversal of the tree, where we build the linked list by adding each node to the end of the list as we visit it.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/bst_to_list)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/bst_to_list)

#### Lowest common ancestor of a binary tree

Find the lowest common ancestor (LCA) of two nodes in a binary tree. The LCA is the node in the tree that is the ancestor of both nodes and is the deepest node in the tree. To solve this problem, you can use a variety of techniques such as traversing the tree in a depth-first or breadth-first manner, or using a recursive approach to traverse the tree and find the LCA. You can also use a divide and conquer approach, where you split the tree into left and right subtrees and find the LCA in each subtree. Another approach is to use a hash table or a map to store the ancestors of each node and then use this information to find the LCA.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lowest_common_ancestor)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lowest_common_ancestor)

#### LRU Cache 	

Designing a cache data structure that stores a limited number of items and removes the least recently used items when the capacity is reached. This can be solved using a doubly linked list and a hash table. The doubly linked list is used to store the items in the cache in the order in which they were accessed, with the most recently accessed item at the front of the list and the least recently accessed item at the back. The hash table is used to store the keys and values of the items in the cache and to quickly retrieve items from the cache based on their keys.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/lru_cache)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/lru_cache)

#### Randomize An Array 	

Shuffle the elements of an array randomly. This can be solved using a random number generator and a Fisher-Yates shuffle algorithm. The Fisher-Yates shuffle algorithm works by starting at the end of the array and randomly swapping each element with an element preceding it. This results in a randomly shuffled array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/randomize_array)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/randomize_array)

#### Binary Tree Right Side View

Given a binary tree, return an array containing the values of the nodes on the right side of the tree, when viewed from the right. One way to solve this problem might be to perform a breadth-first search on the tree, keeping track of the maximum depth of each node as it is visited. When visiting a node at a particular depth for the first time, add its value to the result array.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/binary_tree_right_side_view)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/binary_tree_right_side_view)

#### Design Browser History

Implement a browser history system that supports the following operations: visit a URL, go back to the previous URL, and go forward to the next URL. One potential approach to this problem could involve using a doubly-linked list to store the URLs visited, with a pointer to the current URL. Going back or forward would simply involve moving the pointer to the previous or next URL in the list.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/design_browser_history)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/design_browser_history)

#### Score After Flipping Matrix

Given a matrix of 0s and 1s, flip the rows and columns of the matrix such that the maximum possible score is achieved. The score is calculated as the number of 1s in the matrix. One way to solve this problem might be to use dynamic programming to compute the maximum score for each submatrix of the original matrix, taking into account whether the rows and columns of the submatrix should be flipped.

* [C++](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/cpp/score_after_flipping_matrix)
* [Python](https://github.com/djeada/Algorithms-And-Data-Structures/tree/master/src/brain_teasers/python/score_after_flipping_matrix)
