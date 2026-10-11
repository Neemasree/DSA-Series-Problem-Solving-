# 2894. Divisible and Non-divisible Sums Difference

🔗 **LeetCode:** https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/

**Pattern:** Arithmetic / Divisibility

## Pattern Recognition Cue
Compute the sum of numbers in [1, n] that are not divisible by m, minus the sum of numbers that are divisible by m.

## Approach 1 — Direct Iteration
Iterate from 1 through n and add each number to the appropriate sum.
- **Time:** O(n)
- **Space:** O(1)

## Approach 2 — Arithmetic Series
The sum of all numbers is n(n + 1)/2. Let k = floor(n/m); the sum of multiples of m is m·k(k + 1)/2. The requested difference is totalSum − 2·divisibleSum.
- **Time:** O(1)
- **Space:** O(1)

Use a wide integer type for intermediate arithmetic.

## Key Takeaway
Arithmetic formulas can replace a loop when the values form a simple sequence.