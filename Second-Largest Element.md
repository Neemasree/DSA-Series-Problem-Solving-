<h1 align="center">🥈 Second Largest Element in an Array</h1>

<p align="center">
Find the <b>second largest element</b> from a given array.
</p>

---

## 📌 Problem

Given an integer array `arr`, return the **second largest element** present in the array.

### Example

```
Input  : [3, 7, 2, 9, 5]
Output : 7
```

---

# 🧠 Idea

The **largest element** is the maximum number in the array.

The **second largest element** is the largest number **smaller than the maximum**.

```
Array → [3,7,2,9,5]

Largest        = 9
Second Largest = 7
```

---

# 🚀 Approaches

| Approach | Method | Complexity |
|--------|--------|------------|
| 1 | Sorting | O(n log n) |
| 2 | Two Traversals | O(n) |
| 3 | Single Traversal | O(n) |

---

<details>
<summary>🔹 Approach 1 — Brute Force (Sorting)</summary>

### Idea
Sort the array and return the element before the largest.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int i = n-2; i >= 0; i--) {
        if(arr[i] != arr[n-1]) {
            return arr[i];
        }
    }

    return -1;
}
```

Time Complexity: `O(n log n)`

</details>

---

<details>
<summary>🔹 Approach 2 — Better (Two Traversals)</summary>

### Idea

1. Find the largest element  
2. Find the largest element smaller than it

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {

    int largest = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    int secondLargest = -1;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}
```

Time Complexity: `O(n)`

</details>

---

<details>
<summary>⭐ Approach 3 — Optimal (Single Traversal)</summary>

### Idea

Maintain two variables:

```
largest
secondLargest
```

Update them while traversing the array once.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {

    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 1; i < arr.size(); i++) {

        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}
```

Time Complexity: `O(n)`

</details>

---

# ⭐ Best Approach

The **optimal approach using a single traversal** is the most efficient.

```
Time Complexity  : O(n)
Space Complexity : O(1)
```

---
