# 🔍 LC-35 — Search Insert Position

## 📌 Problem

Given a **sorted array** of distinct integers `nums` and a **target**,  
return the **index** if the target is found.

If not found, return the **index where it would be inserted**  
to maintain sorted order.

You must write an algorithm with **O(log n)** runtime complexity.

---

## 🧠 Idea

This problem is solved using **Binary Search**.

It is exactly the same as finding the **Lower Bound**:

Find the **first index** where:

```
nums[index] >= target
```

If target exists → return its index  
If not → return the position where it should be inserted.

---

## 💻 C++ Code (Your Approach — Lower Bound Logic)

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## 📊 Example 1

**Input**

```
nums = [1,3,5,6]
target = 5
```

**Output**

```
2
```

Target found at index **2**.

---

## 📊 Example 2

**Input**

```
nums = [1,3,5,6]
target = 2
```

**Output**

```
1
```

Target not found → insert at index **1**.

---

## 📊 Example 3

**Input**

```
nums = [1,3,5,6]
target = 7
```

**Output**

```
4
```

Insert at the **end**.

---

## 🎯 Key Observation

This problem is exactly:

```
Lower Bound of target
```

Meaning:

```
First index where nums[index] >= target
```

---

## ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---

## 🧩 Pattern Recognition

| Problem | Pattern Used |
|--------|---------------|
| LC-35 Search Insert Position | Lower Bound |
| First Occurrence | Lower Bound |
| Last Occurrence | Upper Bound - 1 |
