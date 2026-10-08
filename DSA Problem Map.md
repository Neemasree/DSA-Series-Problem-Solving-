# DSA Problem Map

This is my personal DSA revision map.

Structure:

**Topic → Pattern → Solved Problems**

I keep my original solution files in the repository, while this map groups them by the problem-solving pattern I used.

---

## 1. Arrays

### Two Pointers
- [0026 - Remove Duplicates from Sorted Array](../blob/main/Arrays/0026%20-%20Remove%20Duplicates%20from%20Sorted%20Array.cpp)

---

## 2. Binary Search

### Basic Binary Search
- [0704 - Binary Search](../blob/main/Binary%20Search/0704%20-%20Binary%20Search.cpp)

### Boundary / Lower Bound / Upper Bound
- [0034 - Find First and Last Position of Element in Sorted Array](../blob/main/Binary%20Search/0034%20-%20Find%20First%20and%20Last%20Position.cpp)
- [0035 - Search Insert Position](../blob/main/Binary%20Search/0035%20-%20Search%20Insert%20Position.cpp)
- [1539 - Kth Missing Positive Number](../blob/main/Binary%20Search/1539%20-%20Kth%20Missing%20Positive%20Number.cpp)

### Rotated Sorted Array
- [0033 - Search in Rotated Sorted Array](../blob/main/Binary%20Search/0033%20-%20Search%20in%20Rotated%20Sorted%20Array.cpp)
- [0081 - Search in Rotated Sorted Array II](../blob/main/Binary%20Search/0081%20-%20Search%20in%20Rotated%20Sorted%20Array%20II.cpp)

### Binary Search on Answer
- [0875 - Koko Eating Bananas](../blob/main/Binary%20Search/0875%20-%20Koko%20Eating%20Bananas.cpp)
- [1011 - Capacity To Ship Packages](../blob/main/Binary%20Search/1011%20-%20Capacity%20To%20Ship%20Packages.cpp)
- [1283 - Smallest Divisor Given Threshold](../blob/main/Binary%20Search/1283%20-%20Smallest%20Divisor%20Given%20Threshold.cpp)
- [1482 - Minimum Days To Make M Bouquets](../blob/main/Binary%20Search/1482%20-%20Minimum%20Days%20To%20Make%20M%20Bouquets.cpp)

---

## 3. Sliding Window

### Fixed Window
- [0438 - Find All Anagrams in a String](../blob/main/Sliding%20Window/0438%20-%20Find%20All%20Anagrams.cpp)
- [0567 - Permutation in String](../blob/main/Sliding%20Window/0567%20-%20Permutation%20in%20String.cpp)

### Variable Window
- [0713 - Subarray Product Less Than K](../blob/main/Sliding%20Window/0713%20-%20Subarray%20Product%20Less%20Than%20K.cpp)
- [0904 - Fruit Into Baskets](../blob/main/Sliding%20Window/0904%20-%20Fruit%20Into%20Baskets.cpp)

### Minimum / Constraint Window
- [0076 - Minimum Window Substring](../blob/main/Sliding%20Window/0076%20-%20Minimum%20Window%20Substring.cpp)

### Monotonic Deque
- [0239 - Sliding Window Maximum](../blob/main/Sliding%20Window/0239%20-%20Sliding%20Window%20Maximum%20-%20README.md)

---

## 4. Strings

### Basic String Manipulation
- [0008 - String to Integer (atoi)](../blob/main/Strings/0008%20-%20String%20to%20Integer%20(atoi).cpp)
- [0344 - Reverse String](../blob/main/Strings/0344%20-%20Reverse%20String.cpp)

---

## 5. Hashing

### Frequency / Counting
- [3731 - Find Missing Elements](../blob/main/Hashing/3731%20-%20Find%20Missing%20Elements.cpp)

---

## 6. Backtracking

### Subsets
- [0078 - Subsets](../blob/main/Backtracking/0078%20-%20Subsets.cpp)
- [0090 - Subsets II](../blob/main/Backtracking/0090%20-%20Subsets%20II.cpp)

### Permutations
- [0046 - Permutations](../blob/main/Backtracking/0046%20-%20Permutations.cpp)

### Combination Sum
- [0039 - Combination Sum](../blob/main/Backtracking/0039%20-%20Combination%20Sum.cpp)
- [0040 - Combination Sum II](../blob/main/Backtracking/0040%20-%20Combination%20Sum%20II.cpp)
- [0216 - Combination Sum III](../blob/main/Backtracking/0216%20-%20Combination%20Sum%20III.cpp)

---

## 7. Trees

### DFS Traversal
- [0094 - Inorder Traversal](../blob/main/Trees/Binary%20Tree/0094%20-%20Inorder%20Traversal.cpp)
- [0144 - Preorder Traversal](../blob/main/Trees/Binary%20Tree/0144%20-%20Preorder%20Traversal.cpp)
- [0145 - Postorder Traversal](../blob/main/Trees/Binary%20Tree/0145%20-%20Postorder%20Traversal.cpp)

### BFS / Level Order
- [0102 - Level Order Traversal](../blob/main/Trees/Binary%20Tree/0102%20-%20Level%20Order%20Traversal.cpp)

---

## 8. Dynamic Programming

### Minimax / Game DP
- [0486 - Predict The Winner](../blob/main/Dynamic%20Programming/0486%20-%20Predict%20The%20Winner.cpp)
- [1406 - Stone Game III](../blob/main/Dynamic%20Programming/1406%20-%20Stone%20Game%20III.cpp)

---

## 9. Stack / Monotonic Stack

### Monotonic Stack
Several stack/monotonic-stack solutions are currently stored in the legacy root-style folders. They should be grouped here as the collection grows.

---

## 10. Math

### Binary Exponentiation
- [0050 - Pow(x,n)](../blob/main/Math/0050%20-%20Pow(x,n).cpp)

---

## How I will add future problems

Use:

```
Topic/
└── Pattern/
    └── Problem/
        ├── solution.cpp
        └── README.md
```

Example:

```
Arrays/
└── Two Pointers/
    └── 0026-remove-duplicates-from-sorted-array/
        ├── solution.cpp
        └── README.md
```

Each README should contain:
- Problem
- Pattern
- My thought process
- Brute force
- Optimal solution
- Time complexity
- Space complexity
- Key takeaway
