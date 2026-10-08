# 🚀 Intersection of Two Sorted Arrays

## 📌 Problem Statement

Given two **sorted arrays**, find their **intersection**.

The **intersection** contains elements that are **present in both arrays**.

If an element appears multiple times in both arrays, it should appear in the result the **minimum number of times it occurs in both arrays**.

---

# 🧠 Example

### Input

```
arr1 = [1,2,2,3,4]
arr2 = [2,2,3,5]
```

### Output

```
[2,2,3]
```

### Explanation

The elements `2,2,3` appear in **both arrays**, so they form the intersection.

---

# 🛠 Brute Force Approach

## Idea

We compare **each element of the first array with every element of the second array**.

To avoid using the same element from the second array multiple times, we use a **visited array (`vis`)**.

### Steps

1. Traverse array `arr1`.
2. For each element in `arr1`, search in `arr2`.
3. If a match is found and the element in `arr2` is not used before:

   * Add it to the result.
   * Mark it as visited.
4. Stop searching early if `arr2[j] > arr1[i]` because arrays are **sorted**.

---

# 💻 C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {

    int n1 = a.size();
    int n2 = b.size();

    vector<int> ans;
    vector<int> vis(n2,0);

    for(int i = 0; i < n1; i++){

        for(int j = 0; j < n2; j++){

            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            if(b[j] > a[i]) break;
        }
    }

    return ans;
}
```

---

# ⏱ Complexity

| Type             | Complexity   |
| ---------------- | ------------ |
| Time Complexity  | **O(n × m)** |
| Space Complexity | **O(m)**     |

Where:

```
n = size of arr1
m = size of arr2
```

---

# 💡 Key Concepts

* Nested loops
* Visited array to prevent duplicate usage
* Optimization using sorted arrays

---

⭐ If this helped you understand the problem, consider giving the repository a star!
