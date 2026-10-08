Find Peak Element  
**(LeetCode 162)**

```markdown
# 🔍 Find Peak Element

## 📌 Problem Link
LeetCode 162 — Find Peak Element

---

## 🧠 Problem Statement

A peak element is greater than its neighbors.

Return index of any peak.

---

## 🧩 Key Concept

If:
nums[mid] > nums[mid+1]

Peak lies **left**.

Else → **right**

---

## 🚀 Approach

Binary Search on slope.

---

## 💻 Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = (low + high) / 2;

            if (nums[mid] > nums[mid + 1])
                high = mid;

            else
                low = mid + 1;
        }

        return low;
    }
};

⏱️ Complexity

Time:
O(log n)

Space:
O(1)
