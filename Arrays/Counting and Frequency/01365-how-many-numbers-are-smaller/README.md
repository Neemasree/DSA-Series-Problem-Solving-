# 1365. How Many Numbers Are Smaller Than the Current Number

Pattern: Counting / Frequency Prefix Sum

## Approach 1 - Brute Force
Compare every element with every other element and count smaller values.
- Time: O(n²)
- Space: O(1) excluding answer

## Approach 2 - Sorting + Lower Bound
Sort a copy. The first position of x is the number of values strictly smaller than x.
- Time: O(n log n)
- Space: O(n)

## Approach 3 - Counting + Prefix Sum
Because 0 <= nums[i] <= 100, count frequencies and build prefix sums.
- Time: O(n + 100)
- Space: O(100)

Key takeaway: a tiny value range makes counting extremely efficient.