# 🔄 Right Rotate an Array by *D* Places

## 📌 Problem Statement

Given an array `arr` of size `n` and an integer `d`, rotate the array **to the right by `d` positions**.

When we rotate right, the **last `d` elements move to the front** of the array.

---

# 🧠 Example

### Input

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Output

```
[5,6,7,1,2,3,4]
```

### Explanation

Original array

```
1 2 3 4 5 6 7
```

Last `3` elements move to the front

```
5 6 7 1 2 3 4
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

Rotate the array **one position to the right**, and repeat this process `d` times.

---

## Steps

1. Store the last element.
2. Shift all elements to the right.
3. Place the stored element at the front.
4. Repeat this `d` times.

---

## Code

```cpp
class Solution {
public:
    void rightRotate(vector<int>& arr, int d) {

        int n = arr.size();

        for(int j = 0; j < d; j++)
        {
            int temp = arr[n-1];

            for(int i = n-1; i > 0; i--)
            {
                arr[i] = arr[i-1];
            }

            arr[0] = temp;
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

1. Store the **last `d` elements** in a temporary array.
2. Shift the remaining elements **to the right**.
3. Place the stored elements **at the beginning**.

---

## Dry Run

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Step 1 — Store last `d` elements

```
temp = [5,6,7]
```

### Step 2 — Shift remaining elements right

```
_ _ _ 1 2 3 4
```

### Step 3 — Place temp at beginning

```
5 6 7 1 2 3 4
```

---

## Code

```cpp
class Solution {
public:
    void rightRotate(vector<int>& arr, int d) {

        int n = arr.size();
        d = d % n;

        vector<int> temp;

        for(int i = n-d; i < n; i++)
            temp.push_back(arr[i]);

        for(int i = n-d-1; i >= 0; i--)
            arr[i+d] = arr[i];

        for(int i = 0; i < d; i++)
            arr[i] = temp[i];
    }
};
```

---

## Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(d)  |

Better than brute force but uses extra memory.

---

# 🟩 Approach 3: Optimal Approach (Reversal Algorithm)

This is the **most efficient method used in interviews**.

---

## Idea

We rotate the array using **three reversals**.

---

## Steps

1️⃣ Reverse the **entire array**
2️⃣ Reverse the **first `d` elements**
3️⃣ Reverse the **remaining `n-d` elements**

---

## Dry Run

```
arr = [1,2,3,4,5,6,7]
d = 3
```

### Step 1 — Reverse whole array

```
[7,6,5,4,3,2,1]
```

### Step 2 — Reverse first `d`

```
[5,6,7,4,3,2,1]
```

### Step 3 — Reverse remaining

```
[5,6,7,1,2,3,4]
```

Correct result ✔

---

## Code

```cpp
class Solution {
public:
    void rightRotate(vector<int>& arr, int d) {

        int n = arr.size();
        d = d % n;

        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
    }
};
```

---

# 📊 Summary

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute Force | O(n × d)        | O(1)             |
| Better      | O(n)            | O(d)             |
| Optimal     | O(n)            | O(1)             |

---

# 🎯 Key Insight

For **Right Rotation**:

```
reverse(0 → n-1)
reverse(0 → d-1)
reverse(d → n-1)
```

This rotates the array efficiently in **O(n) time and O(1) space**.
