# 🔍 Search in Rotated Sorted Array I

## 📌 Problem Link
LeetCode 33 — Search in Rotated Sorted Array

---

## 🧠 Problem Statement

Given a rotated sorted array `nums` of **unique elements** and a target value `target`, return its index if found. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** runtime complexity.

---

## 🧩 Key Concept

At least **one half of the array is always sorted**.

So:
- Check which half is sorted
- Decide whether target lies there
- Move accordingly

---

## 🚀 Approach (Binary Search)

1. Set `low = 0`, `high = n-1`
2. Find `mid`
3. Check:
   - If `nums[mid] == target` → return mid
4. Check which half is sorted:
   - If `nums[low] <= nums[mid]` → Left sorted
   - Else → Right sorted
5. Decide movement

---

## 💻 Code (C++ — LeetCode Style)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half sorted
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half sorted
            else {

                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
