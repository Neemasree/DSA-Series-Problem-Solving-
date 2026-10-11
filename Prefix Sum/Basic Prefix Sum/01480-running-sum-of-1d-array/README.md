# 1480. Running Sum of 1d Array

🔗 **LeetCode:** https://leetcode.com/problems/running-sum-of-1d-array/

**Pattern:** Prefix Sum

## Pattern Recognition Cue
Each output position should contain the sum of every element from index 0 through that position.

## Approach 1 — Brute Force
For every index, sum all elements from the beginning up to that index.
- **Time:** O(n²)
- **Space:** O(1) extra, excluding output

## Approach 2 — Running Prefix Sum
Keep the running sum in the array: add the previous prefix value to the current element.
- **Time:** O(n)
- **Space:** O(1) extra (the input array is updated)

## Key Takeaway
A prefix sum reuses the work from the previous position instead of recalculating the same range.