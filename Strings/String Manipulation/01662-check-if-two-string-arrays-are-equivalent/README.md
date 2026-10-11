# 1662. Check If Two String Arrays are Equivalent

🔗 **LeetCode:** https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

**Pattern:** String concatenation / character traversal

## Pattern Recognition Cue
Two arrays of strings are equivalent when joining all strings in each array produces the same final string.

## Approach 1 — Brute Force
Join the words in each array into two strings, then compare them.
- **Time:** O(N + M), where N and M are total character counts
- **Space:** O(N + M) for the joined strings

## Approach 2 — Character-by-Character Comparison
Compare characters as if each word array were one continuous string, without building the joined strings. This avoids allocating the two full concatenated strings.
- **Time:** O(N + M)
- **Space:** O(1) extra

The included `solution.cpp` uses the straightforward concatenation approach for clarity.

## Key Takeaway
String-array boundaries do not matter; only the resulting character sequence matters.