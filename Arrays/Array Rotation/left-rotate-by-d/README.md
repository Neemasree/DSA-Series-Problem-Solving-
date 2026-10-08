# 🔄 Left Rotate an Array by *D* Places

## 📌 Problem Statement

Given an array `arr` of size `n` and an integer `d`, rotate the array **to the left by `d` positions**.

When we rotate left, the **first `d` elements move to the end** of the array.

---

## 🧠 Example

### Input

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Output

```
[4,5,6,7,1,2,3]
```

### Explanation

Original array

```
1 2 3 4 5 6 7
```

First `3` elements move to the end

```
4 5 6 7 1 2 3
```

---

# ⚠️ Important Step

Before rotating, always do:

```cpp
d = d % n;
```

Why?

Example:

```
n = 7
d = 10
```

```
10 % 7 = 3
```

So rotating **10 times = rotating 3 times**.

---

# 🟥 Approach 1: Brute Force

## Idea

Rotate the array **one step at a time** and repeat this process `d` times.

---

## Steps

1. Store the first element.
2. Shift all elements one position to the left.
3. Put the stored element at the end.
4. Repeat this `d` times.

---

## Code

```cpp
class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {

        int n = arr.size();

        for(int j = 0; j < d; j++)
        {
            int temp = arr[0];

            for(int i = 1; i < n; i++)
            {
                arr[i-1] = arr[i];
            }

            arr[n-1] = temp;
        }
    }
};
```

---

## Complexity

| Time     | Space |
| -------- | ----- |
| O(n × d) | O(1)  |

❌ Slow when `d` is large.

---

# 🟨 Approach 2: Better Approach (Using Temporary Array)

## Idea

Instead of rotating one-by-one:

1. Store the **first `d` elements** in a temporary array.
2. Shift the remaining elements **left**.
3. Place the stored elements **at the end**.

---

## Dry Run

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Step 1 — Store first `d` elements

```
temp = [1,2,3]
```

### Step 2 — Shift remaining elements left

```
4 5 6 7 _ _ _
```

### Step 3 — Place temp at end

```
4 5 6 7 1 2 3
```

---

## Code

```cpp
class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {

        int n = arr.size();
        d = d % n;

        vector<int> temp;

        for(int i = 0; i < d; i++)
            temp.push_back(arr[i]);

        for(int i = d; i < n; i++)
            arr[i-d] = arr[i];

        for(int i = 0; i < d; i++)
            arr[n-d+i] = temp[i];
    }
};
```

---

## Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(d)  |

Better than brute force, but uses extra space.

---

# 🟩 Approach 3: Optimal Approach (Reversal Algorithm)

This is the **most efficient method used in interviews**.

It works using **3 array reversals**.

---

## Idea

Instead of shifting elements, we rearrange them using reversals.

---

## Steps

1️⃣ Reverse the **first `d` elements**
2️⃣ Reverse the **remaining `n-d` elements**
3️⃣ Reverse the **entire array**

---

## Dry Run

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Step 1 — Reverse first `d`

```
[3,2,1,4,5,6,7]
```

### Step 2 — Reverse remaining

```
[3,2,1,7,6,5,4]
```

### Step 3 — Reverse whole array

```
[4,5,6,7,1,2,3]
```

Correct result ✔

---

## Code

```cpp
class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {

        int n = arr.size();
        d = d % n;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};
```

---

## Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(1)  |

✅ Fastest solution.

---

# 📊 Summary

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute Force | O(n × d)        | O(1)             |
| Better      | O(n)            | O(d)             |
| Optimal     | O(n)            | O(1)             |

---

# 🎯 Key Takeaway

To rotate an array **left by `d` places efficiently**, use the **Reversal Algorithm**.

```
reverse(0 → d-1)
reverse(d → n-1)
reverse(0 → n-1)
```

This achieves the rotation in **linear time with constant space**.
