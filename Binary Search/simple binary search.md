# 🔍 Binary Search

## 📌 Problem Statement

Given a **sorted array** and a **target element**, return the **index** of the target.  
If the element is not found, return **-1**.

---

## 🧾 Example

```
Input:
arr = [1, 3, 5, 7, 9, 11]
target = 7

Output:
3
```

---

## 💡 Approach

Binary Search works by repeatedly dividing the search space into half.

Steps:

1. Set `low = 0`, `high = n-1`
2. Find middle:
   ```
   mid = low + (high - low) / 2
   ```
3. Compare:
   - If `arr[mid] == target` → return `mid`
   - If `arr[mid] < target` → search right half  
     `low = mid + 1`
   - If `arr[mid] > target` → search left half  
     `high = mid - 1`
4. If not found → return `-1`

---

## 💻 C++ Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;
    int target = 7;

    cout << binarySearch(arr, n, target);

    return 0;
}
```

---

## 🎯 Time Complexity

| Case | Complexity |
|------|-----------|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

---

## 📦 Space Complexity

```
O(1)
```

---

## ⚠️ Key Points

- Array **must be sorted**
- Very efficient for large datasets
- Reduces search space by half each step


- Search Insert Position
