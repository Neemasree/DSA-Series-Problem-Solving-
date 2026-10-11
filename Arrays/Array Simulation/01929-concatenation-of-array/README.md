# 1929. Concatenation of Array

🔗 **LeetCode:** https://leetcode.com/problems/concatenation-of-array/

**Pattern:** Array Simulation

## Pattern Recognition Cue
The answer is the input array repeated twice in the same order.

## Approach 1 — Direct Copy
Create a result array of length 2n and fill its first half and second half from the input.
- **Time:** O(n)
- **Space:** O(n) for the result

## Approach 2 — Copy and Append
Copy the input array, then append the original elements to the end.
- **Time:** O(n)
- **Space:** O(n) for the result

## Key Takeaway
This is a direct simulation problem; no advanced data structure is needed.