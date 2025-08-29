## Searching

Searching refers to the process of finding the location of a specific element within a collection of data, such as an array, list, tree, or graph. It underpins many applications, from databases and information retrieval to routing and artificial intelligence. Depending on the organization of the data, different search techniques are used—such as linear search for unsorted data, binary search for sorted data, and more advanced approaches like hash-based lookup or tree traversals for hierarchical structures. Efficient searching is important because it directly impacts the performance and scalability of software systems.

### 1. **Linear & Sequential Search**
- **Linear Search (Sequential Search)**
  - Checks each element one by one.
- **Sentinel Linear Search**
  - Uses a sentinel value to reduce comparisons.

### 2. **Divide & Conquer Search**
- **Binary Search**
  - Efficient on sorted arrays (O(log n)).
- **Ternary Search**
  - Divides array into three parts instead of two.
- **Jump Search**
  - Jumps ahead by fixed steps, then does linear search.
- **Exponential Search**
  - Finds range with exponential jumps, then does binary search.
- **Interpolation Search**
  - Estimates position based on value distribution.

### 3. **Tree-based Search**
- **Binary Search Tree (BST) Search**
  - Search in a binary search tree.
- **AVL Tree Search / Red-Black Tree Search**
  - Balanced BSTs for faster search.
- **B-Tree / B+ Tree Search**
  - Used in databases and file systems.
- **Trie (Prefix Tree) Search**
  - Efficient for searching words/prefixes.

### 4. **Hash-based Search**
- **Hash Table Search**
  - Uses hash functions for constant time lookups.
- **Open Addressing (Linear/Quadratic Probing, Double Hashing)**
  - Methods for collision resolution.
- **Separate Chaining**
  - Uses linked lists for collisions.
- **Cuckoo Hashing**
  - Multiple hash functions to resolve collisions.

### 5. **Probabilistic & Approximate Search**
- **Bloom Filter**
  - Probabilistic; fast membership test with false positives.
- **Counting Bloom Filter**
  - Supports deletion.
- **Cuckoo Filter**
  - Similar to Bloom filters but supports deletion.

### 6. **Graph-based Search Algorithms**
- **Breadth-First Search (BFS)**
  - Explores neighbors first in unweighted graphs.
- **Depth-First Search (DFS)**
  - Explores as far as possible along branches.
- **A* Search**
  - Heuristic-based best-first search.
- **Bidirectional Search**
  - Runs two simultaneous searches from source and target.

### 7. **String Search Algorithms**
- **Naive String Search**
- **Knuth-Morris-Pratt (KMP)**
- **Boyer-Moore**
- **Rabin-Karp**
