# 🔍 Binary Search — First Occurrence

## 📌 Problem Statement

Given a **sorted array** of integers and a **target value**,  
find the **first occurrence** of the target using **Binary Search**.

If the target is not present, return **-1**.

---

## 🧠 Idea

Normal Binary Search stops when target is found.  
But for **first occurrence**, we:

- Store the index when target is found
- Continue searching on the **left side**
- Return the **leftmost index**

---

## ⚙️ Algorithm Steps

1. Initialize:
   - `low = 0`
   - `high = n - 1`
   - `ans = -1`

2. While `low <= high`:
   - Find `mid = low + (high - low) / 2`
   - If `arr[mid] == target`  
     → Store `mid` in `ans`  
     → Move left → `high = mid - 1`
   - Else if `arr[mid] < target`  
     → Move right → `low = mid + 1`
   - Else  
     → Move left → `high = mid - 1`

3. Return `ans`

---

## 💻 C++ Code

```cpp
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;          // store index
            high = mid - 1;     // move left
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4};
    int n = 6;
    int target = 2;

    int result = firstOccurrence(arr, n, target);

    if (result != -1)
        cout << "First Occurrence Index: " << result;
    else
        cout << "Element not found";

    return 0;
}
```

---

## 📊 Example

**Input**

```
arr = [1, 2, 2, 2, 3, 4]
target = 2
```

**Output**

```
First Occurrence Index: 1
```

---

## ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---

## 🎯 Key Point

When target is found:

```
Store index
Move LEFT
Keep searching
```

That guarantees the **first occurrence**.
