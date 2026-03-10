<h1 align="center">✅ Check if an Array is Sorted</h1>

<p align="center">
Determine whether a given array is sorted in <b>non-decreasing order</b>.
</p>

---

## 📌 Problem

Given an array `arr`, check whether the array is **sorted in non-decreasing order**.

Return **true** if the array is sorted, otherwise return **false**.

---

### Example

```
Input  : [1,2,3,4,5]
Output : true
```

```
Input  : [1,3,2,4,5]
Output : false
```

---

# 🧠 Idea

An array is **sorted** if every element is **greater than or equal to the previous element**.

Example:

```
Array → [1,2,3,4,5]

1 ≤ 2 ≤ 3 ≤ 4 ≤ 5

Sorted ✅
```

Example:

```
Array → [1,3,2,4]

3 > 2 ❌

Not Sorted
```

---

# 🚀 Approach

Traverse the array and compare **each element with the next element**.

If any element is **greater than the next element**, the array is **not sorted**.

---

<details>
<summary>💻 C++ Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {

    for(int i = 1; i < arr.size(); i++) {

        if(arr[i] < arr[i-1]) {
            return false;
        }

    }

    return true;
}
```

</details>

---

# ⏱ Complexity

```
Time Complexity  : O(n)
Space Complexity : O(1)
```

---

# ⭐ Key Point

Only **one traversal** is needed to determine if the array is sorted.

```
Efficient ✔
Simple ✔
```

---
