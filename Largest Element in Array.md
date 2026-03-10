<h1 align="center">🏆 Largest Element in an Array</h1>

<p align="center">
Find the <b>largest element</b> present in a given array.
</p>

---

## 📌 Problem

Given an integer array `arr`, return the **largest element** in the array.

### Example

```
Input  : [3, 7, 2, 9, 5]
Output : 9
```

---

# 🧠 Idea

The **largest element** is simply the **maximum value** in the array.

Example:

```
Array → [3,7,2,9,5]

Compare numbers one by one

Largest = 9
```

---

# 🚀 Approaches

| Approach | Method | Complexity |
|--------|--------|------------|
| 1 | Sorting | O(n log n) |
| 2 | Linear Scan | O(n) |
| 3 | Using STL | O(n) |

---

<details>
<summary>🔹 Approach 1 — Brute Force (Sorting)</summary>

### Idea

Sort the array and return the **last element**.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr) {
    
    sort(arr.begin(), arr.end());
    
    return arr[arr.size()-1];
}
```

Time Complexity: `O(n log n)`

</details>

---

<details>
<summary>🔹 Approach 2 — Better (Linear Traversal)</summary>

### Idea

Traverse the array and keep updating the **largest element**.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr) {

    int largest = arr[0];

    for(int i = 1; i < arr.size(); i++) {

        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}
```

Time Complexity: `O(n)`

</details>

---

<details>
<summary>⭐ Approach 3 — Using STL</summary>

### Idea

Use the C++ STL function **max_element()**.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr) {

    return *max_element(arr.begin(), arr.end());

}
```

Time Complexity: `O(n)`

</details>

---

# ⭐ Best Approach

The **linear traversal approach** is efficient and simple.

```
Time Complexity  : O(n)
Space Complexity : O(1)
```

---
