# 3300. Minimum Element After Replacement With Digit Sum

Pattern: Digit Extraction

## Approach 1 - Direct Simulation
Compute every digit sum, replace conceptually, and find the minimum.
- Time: O(n * d)
- Space: O(1)

## Approach 2 - Single Pass
Do not modify the array. Compute each digit sum and update the minimum immediately.
- Time: O(n * d)
- Space: O(1)

Key takeaway: if only the final aggregate is needed, avoid modifying the input.