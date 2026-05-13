## Problem
Given a **1-indexed** array of integers `numbers` that is already sorted in non-decreasing order, find two numbers such that they add up to a specific `target` number.

Return the indices of the two numbers (1-indexed).

---

# Approach Used: Two Pointers

Since the array is already sorted, we can use the **Two Pointer Technique**.

- Start one pointer from the beginning (`l`)
- Start another pointer from the end (`r`)
- Calculate the sum:
  - If sum == target → answer found
  - If sum < target → move left pointer forward
  - If sum > target → move right pointer backward

This works because the array is sorted.

---

# C++ Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        int l = 0;
        int r = n - 1;

        while(l < r) {

            int sum = numbers[l] + numbers[r];

            if(sum == target) {
                return {l + 1, r + 1};
            }
            else if(sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return {};
    }
};
```

---

# Dry Run Example

## Input

```cpp
numbers = [2,7,11,15]
target = 9
```

---

## Step 1

```cpp
l = 0 -> 2
r = 3 -> 15

sum = 2 + 15 = 17
```

Since `17 > 9`, move `r--`

---

## Step 2

```cpp
l = 0 -> 2
r = 2 -> 11

sum = 13
```

Since `13 > 9`, move `r--`

---

## Step 3

```cpp
l = 0 -> 2
r = 1 -> 7

sum = 9
```

Target found.

---

## Output

```cpp
[1,2]
```

---

# Important Concepts

## Why `while(l < r)` ?

It means:

- Continue until left pointer is smaller than right pointer.
- If they become equal or cross each other, stop.

Example:

```cpp
l = 2
r = 2
```

Both pointers point to same element.

We cannot use same element twice.

So loop stops.

---

## Why `return {};` ?

```cpp
return {};
```

This returns an empty vector.

Meaning:

```cpp
return empty vector
```

Used when no valid pair is found.

Even though this problem guarantees an answer, C++ still requires a return statement.

---

# Time Complexity

```cpp
O(n)
```

Each pointer moves at most `n` times.

---

# Space Complexity

```cpp
O(1)
```

No extra space is used.

---

# When Should You Think About Two Pointers?

Use Two Pointers when:

- Array is sorted
- Need pair sum
- Need target sum
- Need optimal solution
- Need to reduce nested loops

---

# Common Two Pointer Problems

- Two Sum II
- Remove Duplicates
- Container With Most Water
- 3Sum
- Trapping Rain Water
- Valid Palindrome

---

# Key Idea

```text
Left pointer + Right pointer
Move intelligently based on condition
```

This helps reduce:

```text
O(n²)  →  O(n)
```

---
