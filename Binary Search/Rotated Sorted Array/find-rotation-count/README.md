Find Rotation Count

```markdown
# 🔍 Find Rotation Count in Rotated Sorted Array

---

## 🧠 Problem Statement

Find how many times a sorted array is rotated.

Rotation count = **Index of minimum element**

---

## 🚀 Approach

Same as **Find Minimum**.

Return index instead.

---

## 💻 Code

```cpp
int findKRotation(vector<int>& nums) {

    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {

        int mid = (low + high) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;

        else
            high = mid;
    }

    return low;
}
