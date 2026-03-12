# 🚀 Union of Two Sorted Arrays

## 📌 Problem Statement

Given two **sorted arrays**, return the **union** of both arrays.

The **union** contains all **unique elements** from both arrays and must remain **sorted**.

---

# 🧠 Example

### Input

```
arr1 = [1,2,3,4,5]
arr2 = [2,3,4,6,7]
```

### Output

```
[1,2,3,4,5,6,7]
```

### Explanation

All elements from both arrays appear **only once** in the final result.

---

# 1️⃣ Brute Force Approach (Using Set)

## Idea

A **set** automatically stores elements in **sorted order** and **removes duplicates**.

Steps:

1. Insert all elements of `arr1` into a set.
2. Insert all elements of `arr2` into the same set.
3. Convert the set into a vector.

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b){

    set<int> st;

    for(int x : a){
        st.insert(x);
    }

    for(int x : b){
        st.insert(x);
    }

    vector<int> result;

    for(auto it : st){
        result.push_back(it);
    }

    return result;
}
```

---

## Complexity

| Type             | Complexity        |
| ---------------- | ----------------- |
| Time Complexity  | O((n+m) log(n+m)) |
| Space Complexity | O(n+m)            |

---

# 2️⃣ Optimal Approach (Two Pointer Technique)

Since the arrays are **already sorted**, we can traverse both arrays **simultaneously**.

## Idea

Use two pointers:

```
i → arr1
j → arr2
```

At each step:

* Compare elements
* Insert the smaller element
* Move the corresponding pointer
* Avoid duplicates

This works similarly to the **merge step in merge sort**.

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {

    int n1 = a.size();
    int n2 = b.size();

    int i = 0, j = 0;
    vector<int> unionArr;

    while(i < n1 && j < n2){

        if(a[i] <= b[j]){

            if(unionArr.size() == 0 || unionArr.back() != a[i])
                unionArr.push_back(a[i]);

            i++;
        }
        else{

            if(unionArr.size() == 0 || unionArr.back() != b[j])
                unionArr.push_back(b[j]);

            j++;
        }
    }

    while(i < n1){

        if(unionArr.size() == 0 || unionArr.back() != a[i])
            unionArr.push_back(a[i]);

        i++;
    }

    while(j < n2){

        if(unionArr.size() == 0 || unionArr.back() != b[j])
            unionArr.push_back(b[j]);

        j++;
    }

    return unionArr;
}
```

---

# ⏱ Complexity

| Type             | Complexity   |
| ---------------- | ------------ |
| Time Complexity  | **O(n + m)** |
| Space Complexity | O(n + m)     |

Where:

```
n = size of arr1
m = size of arr2
```

---

# 📊 Approach Comparison

| Approach              | Time              | Space  |
| --------------------- | ----------------- | ------ |
| Brute Force (Set)     | O((n+m) log(n+m)) | O(n+m) |
| Optimal (Two Pointer) | **O(n+m)**        | O(n+m) |

---

⭐ If this helped you understand the problem, consider starring the repository!
