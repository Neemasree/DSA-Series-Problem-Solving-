# 🔍 Binary Search — Last Occurrence (LeetCode Style)

## 📌 Problem

Given a **sorted array `nums`** and a **target**,  
return the **last occurrence** of the target.

If the target is not found, return **-1**.

---

## 🧠 Idea (LeetCode Approach)

- Use **Binary Search**
- When `nums[mid] == target`:
  - Store index
  - Move to the **right** to find later occurrence
- Continue until search ends
- Return stored index

---

## 💻 C++ Code (LeetCode Style)

```cpp
class Solution {
public:
    int lastOccurrence(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;          // store index
                low = mid + 1;      // search right
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## 📊 Example

**Input**

```
nums = [1,2,2,2,3,4]
target = 2
```

**Output**

```
3
```

---

## 🎯 Key Observation

| Case | Move |
|------|------|
| `nums[mid] == target` | Move **Right** |
| `nums[mid] < target` | Move **Right** |
| `nums[mid] > target` | Move **Left** |

---

## ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---
