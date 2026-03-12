<h1 align="center">🧹 Remove Duplicates from Sorted Array</h1>

<p align="center">
Remove duplicates from a <b>sorted array</b> and return the number of unique elements.
</p>

---

## 📌 Problem

Given a **sorted array `arr`**, remove the duplicates **in-place** such that each element appears only once.

Return the **number of unique elements**.

---

### Example

```
Input  : [1,1,2,2,2,3,3]
Output : [1,2,3]
Length : 3
```

Explanation

```
Original Array
[1,1,2,2,2,3,3]

After Removing Duplicates
[1,2,3]
```

---

# 🧠 Idea

Since the array is **sorted**, duplicates will always appear **next to each other**.

We can use the **two-pointer technique**.

```
i → tracks unique elements
j → scans the array
```

---

# 🚀 Approach

1. Start with `i = 0`
2. Traverse the array using `j`
3. If `arr[j] != arr[i]`, move `i` forward and update value

---

### Visualization

```
Array → [1,1,2,2,3]

i = 0
j = 1 → duplicate

j = 2 → new element
move i → place 2

Result
[1,2,3]
```

---

<details>
<summary>💻 C++ Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {

    int i = 0;

    for(int j = 1; j < arr.size(); j++) {

        if(arr[j] != arr[i]) {

            i++;
            arr[i] = arr[j];

        }
    }

    return i + 1;
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

# ⭐ Key Concept

This problem is a classic example of the **Two Pointer Technique**.

```
Efficient ✔
In-place ✔
Single traversal ✔
```

---
