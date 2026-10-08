# 567. Permutation in String

🔗 **LeetCode:** https://leetcode.com/problems/permutation-in-string/

## Pattern
Fixed Sliding Window + Frequency Counting

## Approach 1 — Brute Force
Check every substring of length m and compare its character frequencies with s1.

## Approach 2 — Optimal
Maintain a fixed-size window of length m in s2. Add the incoming character, remove the outgoing character, and compare the 26-frequency arrays.

## Complexity
- Time: O(n)
- Space: O(1), using fixed-size frequency arrays.

## Key Takeaway
A permutation has the same length and the same character frequencies, so a fixed sliding window is the natural pattern.