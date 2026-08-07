
---

# 📘 README 3 — Find Minimum in Rotated Sorted Array  
**(LeetCode 153)**

```markdown
# 🔍 Find Minimum in Rotated Sorted Array

## 📌 Problem Link
LeetCode 153 — Find Minimum in Rotated Sorted Array

---

## 🧠 Problem Statement

Find the **minimum element** in a rotated sorted array.

All elements are **unique**.

---

## 🧩 Key Concept

Minimum element lies in **unsorted half**.

---

## 🚀 Approach

1. Compare `nums[mid]` and `nums[high]`
2. If `nums[mid] > nums[high]`
   → Minimum is right side
3. Else
   → Minimum is left side

---

## 💻 Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = (low + high) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;

            else
                high = mid;
        }

        return nums[low];
    }
};
