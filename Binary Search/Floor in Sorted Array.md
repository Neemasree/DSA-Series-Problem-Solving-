# 🔍 Find Floor in Sorted Array (Binary Search)

## 📌 Problem

Given a **sorted array** `arr` and a number `x`,  
find the **floor** of `x`.

### 🔹 Floor Definition

The **floor** of `x` is:

```
The greatest element <= x
```

Return the **index** of the floor element.  
If floor does not exist, return **-1**.

---

## 🧠 Idea

We use **Binary Search**.

If:

```
arr[mid] <= x
```

That means:

- This **can be a floor**
- But there **may be a bigger valid floor**
- So move **RIGHT**

Store index and continue searching.

---

## 💻 C++ Code (Your Approach)

```cpp
class Solution {
public:
    int findFloor(vector<int>& arr, int x) {

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] <= x) {
                ans = mid;      // store possible floor
                low = mid + 1;  // search right
            }
            else {
                high = mid - 1; // search left
            }
        }

        return ans;
    }
};
```

---

## 📊 Example 1

**Input**

```
arr = [1,2,4,6,8]
x = 5
```

**Output**

```
2
```

Floor element:

```
arr[2] = 4
```

Largest value **<= 5**.

---

## 📊 Example 2

**Input**

```
arr = [1,2,4,6,8]
x = 0
```

**Output**

```
-1
```

No element **<= 0** exists.

---

## 🎯 Key Observation

| Condition | Action |
|----------|--------|
| `arr[mid] <= x` | Store index → Move RIGHT |
| `arr[mid] > x` | Move LEFT |

---

## 🧩 Pattern Recognition

This problem is:

```
Reverse of Lower Bound logic
```

| Problem | Condition |
|--------|-----------|
| Lower Bound | `>= target` |
| Floor | `<= x` |

---

## ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---

## 🔥 Related Problems

- Lower Bound
- Upper Bound
- Ceil in Sorted Array
- Search Insert Position (LC-35)
