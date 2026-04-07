Search in Rotated Sorted Array II  
**(LeetCode 81 — duplicates allowed)**

```markdown
# 🔍 Search in Rotated Sorted Array II

## 📌 Problem Link
LeetCode 81 — Search in Rotated Sorted Array II

---

## 🧠 Problem Statement

Given a rotated sorted array that **may contain duplicates**, return `true` if target exists, otherwise return `false`.

---

## 🧩 Key Concept

Duplicates create ambiguity.

So when:
nums[low] == nums[mid] == nums[high]

We shrink search space.

---

## 🚀 Approach

1. Use Binary Search
2. Handle duplicate case
3. Then check sorted halves

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return true;

            // Remove duplicates
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {

                low++;
                high--;
                continue;
            }

            // Left sorted
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target &&
                    target < nums[mid])

                    high = mid - 1;

                else
                    low = mid + 1;
            }

            // Right sorted
            else {

                if (nums[mid] < target &&
                    target <= nums[high])

                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};

⏱️ Complexity

Time:
O(log n) average
O(n) worst (due to duplicates)

Space:
O(1)
