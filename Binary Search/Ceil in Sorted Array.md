# 🔍 Find Ceil in Sorted Array (Binary Search)

## 📌 Problem

Given a **sorted array** `arr` and a number `x`,  
find the **ceil** of `x`.

### 🔹 Ceil Definition

The **ceil** of `x` is:

```
The smallest element >= x
```

Return the **index** of the ceil element.  
If ceil does not exist, return **-1**.

---

## 🧠 Idea

We use **Binary Search**.

If:

```
arr[mid] >= x
```

That means:

- This **can be a ceil**
- But there **may be a smaller valid ceil**
- So move **LEFT**

Store index and continue searching.

---

## 💻 C++ Code (Your Approach)

```cpp
class Solution {
public:
    int findCeil(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] >= x) {
                ans = mid;      // store possible ceil
                high = mid - 1; // search left
            }
            else {
                low = mid + 1;  // search right
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
arr = [1,2,4,6,8]
x = 5
```

**Output**

```
3
```

Ceil element:

```
arr[3] = 6
```

Smallest value **>= 5**.

---

## 📊 Example 2

**Input**

```
arr = [1,2,4,6,8]
x = 9
```

**Output**

```
-1
```

No element **>= 9** exists.

---

## 🎯 Key Observation

| Condition | Action |
|----------|--------|
| `arr[mid] >= x` | Store index → Move LEFT |
| `arr[mid] < x` | Move RIGHT |

---

## 🧩 Pattern Recognition

This problem is:

```
Same as Lower Bound logic
```

| Problem | Condition |
|--------|-----------|
| Lower Bound | `>= target` |
| Ceil | `>= x` |

---

## ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---
