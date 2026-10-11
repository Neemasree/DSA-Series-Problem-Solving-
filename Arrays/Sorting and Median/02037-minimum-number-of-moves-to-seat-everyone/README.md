# 2037. Minimum Number of Moves to Seat Everyone

🔗 **LeetCode:** https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

**Pattern:** Sorting + Greedy

## Pattern Recognition Cue
Every student must be assigned one seat, and the total movement distance should be minimized.

## Approach 1 — Brute Force
Try every possible assignment of students to seats and choose the assignment with the smallest total distance.
- **Time:** O(n! · n) in a direct permutation search
- **Space:** O(n) for the assignment/permutation state

## Approach 2 — Sort Both Arrays
Sort the seat positions and student positions. Pair them in sorted order and add each absolute distance.
- **Time:** O(n log n)
- **Space:** O(1) auxiliary space beyond the sorting implementation

## Key Takeaway
In one dimension, pairing sorted positions minimizes the total distance. Crossed assignments can be uncrossed without increasing the total movement.