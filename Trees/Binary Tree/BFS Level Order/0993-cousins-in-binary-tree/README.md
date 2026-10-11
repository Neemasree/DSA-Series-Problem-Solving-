# 993. Cousins in Binary Tree

🔗 **LeetCode:** https://leetcode.com/problems/cousins-in-binary-tree/

**Pattern:** BFS / Level Order + Parent Tracking

## Pattern Recognition Cue
Two nodes are cousins when they are at the same depth but have different parents.

## Approach 1 — Separate Depth and Parent Searches
Find each target's depth and parent, then check whether depths match and parents differ.
- **Time:** O(n)
- **Space:** O(h) recursive stack, where h is tree height

## Approach 2 — Level-Order BFS
Process one level at a time while recording each target's parent. When either target is found at a level, return true only if both were found at that same level and their parent pointers differ.
- **Time:** O(n)
- **Space:** O(w), where w is the maximum tree width

## Key Takeaway
Level order checks depth naturally; tracking parent pointers lets us distinguish cousins from siblings.