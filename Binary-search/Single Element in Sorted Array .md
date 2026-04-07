 Single Element in Sorted Array  
**(LeetCode 540)**

```markdown
# 🔍 Single Element in Sorted Array

## 📌 Problem Link
LeetCode 540 — Single Element in Sorted Array

---

## 🧠 Problem Statement

Every element appears **twice**, except **one element**.

Find that element.

---

## 🧩 Key Concept

Pairs:

Even index → start of pair

---

## 🚀 Approach

Use binary search and check index parity.

---

## 💻 Code

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = (low + high) / 2;

            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;

            else
                high = mid;
        }

        return nums[low];
    }
};


In simple way xor can be used logic(ans=ans^nums[i])
