# Aggressive Cows

## Pattern
Binary Search on Answer

## Approach 1 — Brute Force
Try every possible minimum distance and greedily check whether all cows can be placed.

## Approach 2 — Optimal
Binary search the minimum distance. For each candidate distance, greedily place cows from left to right.

## Complexity
- Sorting: O(n log n)
- Each feasibility check: O(n)
- Binary search over the answer range: O(log range)
- Overall: O(n log n + n log range)
- Extra space: O(1) excluding sorting

## Key Takeaway
When a numeric answer has a monotonic feasibility condition, think Binary Search on Answer.