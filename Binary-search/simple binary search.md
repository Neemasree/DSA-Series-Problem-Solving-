
## 📌 Topic
Binary Search

## 🎯 Aim

To search for an element in a **sorted array** using:

- 🔹 Normal Binary Search  
- 🔹 Binary Search — First Occurrence  

---

# 📖 What is Binary Search?

**Binary Search** is an efficient searching algorithm used on **sorted arrays**.

Instead of checking every element, it:

1. Finds the **middle element**
2. Compares with target
3. Eliminates half of the array
4. Repeats until found

---

## ⚡ Why Binary Search?

| Method | Time Complexity |
|--------|----------------|
| Linear Search | O(n) |
| Binary Search | O(log n) 🚀 |

Binary Search is **much faster** for large datasets.

---

# 🧠 Key Condition

✅ **Array must be sorted**

Without sorting, Binary Search **will not work correctly**.

---

# 🔎 Problem 1 — Normal Binary Search

## 📌 Problem Statement

Given a **sorted array** and a **target element**, return the **index of the target**.

If the element is not found, return **-1**.

---

## 🧾 Example


Array: [1, 3, 5, 7, 9, 11]
Target: 7

Output: 3


---

# 💡 Algorithm — Normal Binary Search

1. Initialize:
   - `low = 0`
   - `high = n-1`

2. Repeat while `low <= high`:

   Find middle:

mid = low + (high - low) / 2


If:
- `arr[mid] == target` → return `mid`
- `arr[mid] < target` → search right  
  `low = mid + 1`
- `arr[mid] > target` → search left  
  `high = mid - 1`

3. If not found → return **-1**

---

# 💻 C++ Code — Normal Binary Search

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {

 int low = 0;
 int high = n - 1;

 while (low <= high) {

     int mid = low + (high - low) / 2;

     if (arr[mid] == target) {
         return mid;
     }

     else if (arr[mid] < target) {
         low = mid + 1;
     }

     else {
         high = mid - 1;
     }
 }

 return -1;
}

int main() {

 int arr[] = {1, 3, 5, 7, 9, 11};
 int n = 6;
 int target = 7;

 int result = binarySearch(arr, n, target);

 cout << "Index: " << result;

 return 0;
}
🎬 Dry Run — Normal Binary Search
Array: [1,3,5,7,9,11]
Target: 7

low=0 high=5
mid=2 → arr[2]=5 < 7 → search right

low=3 high=5
mid=4 → arr[4]=9 > 7 → search left

low=3 high=3
mid=3 → arr[3]=7 ✅ Found
🎞️ Visual Animation — Normal Binary Search
[1 3 5 7 9 11]

Step 1:
       ↑
      mid (5)

Step 2:
           ↑
          mid (9)

Step 3:
         ↑
        mid (7) ✅
⏱️ Time & Space Complexity
Complexity	Value
Time	O(log n)
Space	O(1)
