# 3019. Number of Changing Keys

🔗 **LeetCode:** https://leetcode.com/problems/number-of-changing-keys/

**Pattern:** String Traversal / Case-Insensitive Comparison

## Pattern Recognition Cue
Count changes between adjacent key presses, ignoring differences caused only by letter case.

## Approach 1 — Compare All Adjacent Pairs With Normalization
Visit each pair of neighboring characters, convert both to the same case, and compare them.
- **Time:** O(n)
- **Space:** O(1)

## Optimal Solution
The included solution performs one pass and uses `tolower` to compare adjacent characters without case sensitivity.
- **Time:** O(n)
- **Space:** O(1)

## Key Takeaway
Normalize case before comparing characters when the task is case-insensitive.