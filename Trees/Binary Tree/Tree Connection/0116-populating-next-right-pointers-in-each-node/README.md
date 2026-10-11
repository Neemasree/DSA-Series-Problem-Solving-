# 116. Populating Next Right Pointers in Each Node

🔗 **LeetCode:** https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

**Pattern:** Binary Tree Level Connections

## Pattern Recognition Cue
Each node's `next` pointer should point to its immediate neighbor on the same level. The tree is perfect.

## Approach 1 — Level-Order Traversal
Use a queue to visit each level and connect neighboring nodes.
- **Time:** O(n)
- **Space:** O(n) for the queue

## Approach 2 — Traverse Using Existing Next Pointers
For each level, connect a node's left child to its right child, then connect its right child to the left child of its next neighbor. Move down through the leftmost child to process the next level.
- **Time:** O(n)
- **Space:** O(1) auxiliary

## Key Takeaway
Once one level is connected, its `next` pointers let us process the next level without a queue.