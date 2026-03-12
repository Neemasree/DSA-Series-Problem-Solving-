# 🔄 Rotate Array by One Place

This file explains how to rotate an array by **one position** in both directions.

---

# ⬅️ Left Rotate by One

## Problem

Rotate the array **one position to the left**.

### Example

```
Input  : [1,2,3,4,5]
Output : [2,3,4,5,1]
```

### Idea

* Store the **first element**
* Shift all elements **one position left**
* Place the stored element at the **last position**

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &arr) {

        int n = arr.size();
        int temp = arr[0];

        for(int i = 1; i < n; i++){
            arr[i-1] = arr[i];
        }

        arr[n-1] = temp;
    }
};
```

### Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |

---

# ➡️ Right Rotate by One (Clockwise)

## Problem

Rotate the array **one position to the right**.

### Example

```
Input  : [1,2,3,4,5]
Output : [5,1,2,3,4]
```

### Idea

* Store the **last element**
* Shift all elements **one position right**
* Place the stored element at the **first position**

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &arr) {

        int n = arr.size();
        int temp = arr[n-1];

        for(int i = n-1; i > 0; i--){
            arr[i] = arr[i-1];
        }

        arr[0] = temp;
    }
};
```

### Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |

---

# 🧠 Key Concept

| Rotation Type | Result                      |
| ------------- | --------------------------- |
| Left Rotate   | First element moves to end  |
| Right Rotate  | Last element moves to front |

---

⭐ This is a **basic array manipulation problem commonly asked in interviews and coding platforms like GeeksforGeeks and LeetCode.**
