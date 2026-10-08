# 1431. Kids With the Greatest Number of Candies

Pattern: Maximum + One-Pass Comparison

## Approach 1 - Brute Force
For each child, add extra candies and scan for the maximum.
- Time: O(n²)
- Space: O(1) excluding answer

## Approach 2 - Find Maximum First
Find the maximum once. A child qualifies when candies[i] + extraCandies >= max.
- Time: O(n)
- Space: O(1) excluding answer

Key takeaway: calculate a shared maximum once instead of repeatedly.