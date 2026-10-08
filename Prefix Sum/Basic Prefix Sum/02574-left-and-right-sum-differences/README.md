# 2574. Left and Right Sum Differences

Pattern: Prefix Sum / Running Sum

## Approach 1 - Brute Force
For each index, separately calculate the left and right sums.
- Time: O(n²)
- Space: O(1) excluding answer

## Approach 2 - Total Sum + Running Left Sum
Compute total once. right = total - left - nums[i], then update left.
- Time: O(n)
- Space: O(1) excluding answer

Key takeaway: total sum lets us derive the right-side sum in O(1).