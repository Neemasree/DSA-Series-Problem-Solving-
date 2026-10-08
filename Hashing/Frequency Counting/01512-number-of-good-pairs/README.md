# 1512. Number of Good Pairs

🔗 **LeetCode:** https://leetcode.com/problems/number-of-good-pairs/

Pattern: Frequency Counting

## Approach 1 - Brute Force
Check every pair i < j and count equal values.
- Time: O(n²)
- Space: O(1)

## Approach 2 - Frequency Map
If x has appeared k times before, the current x creates k new good pairs.
- Time: O(n) average
- Space: O(n)

Key takeaway: ans += freq[x] counts all previous equal elements at once.