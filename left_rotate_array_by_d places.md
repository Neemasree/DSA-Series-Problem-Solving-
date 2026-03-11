# 🔄 Left Rotate Array by D Places

## Problem

Given an array, rotate the array to the **left by `d` positions**.

### Example

```
Input  : [1,2,3,4,5,6,7], d = 3
Output : [4,5,6,7,1,2,3]
```

Explanation:
The first `d` elements move to the end of the array.

---

# 🟥 Approach 1: Brute Force

### Idea

Rotate the array **one step at a time** and repeat the process **d times**.

### Steps

1. Store the first element.
2. Shift all elements to the left.
3. Put the stored element at the end.
4. Repeat this process `d` times.

### Code

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

### Complexity

| Time     | Space |
| -------- | ----- |
| O(n × d) | O(1)  |

---

# 🟨 Approach 2: Better Approach (Using Temporary Array)

### Idea

1. Store the first `d` elements in a temporary array.
2. Shift the remaining elements left.
3. Place the stored elements at the end.

### Example

```
arr = [1,2,3,4,5,6,7]
d = 3
```

Step 1:

```
temp = [1,2,3]
```

Step 2:

```
[4,5,6,7,_,_,_]
```

Step 3:

```
[4,5,6,7,1,2,3]
```

### Code

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

### Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(d)  |

---

# 🟩 Approach 3: Optimal Approach (Reversal Algorithm)

This is the **most optimal solution** used in interviews.

### Idea

Rotate using **three array reversals**.

### Steps

1. Reverse the first `d` elements
2. Reverse the remaining `n-d` elements
3. Reverse the whole array

### Example

```
arr = [1,2,3,4,5,6,7]
d = 3
```

Step 1:

```
[3,2,1,4,5,6,7]
```

Step 2:

```
[3,2,1,7,6,5,4]
```

Step 3:

```
[4,5,6,7,1,2,3]
```

### Code

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

### Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(1)  |

---

# 📊 Summary

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Brute Force        | O(n × d)        | O(1)             |
| Better             | O(n)            | O(d)             |
| Optimal (Reversal) | O(n)            | O(1)             |

---

# 💡 Key Insight

```
Left Rotate by d

reverse(0 → d-1)
reverse(d → n-1)
reverse(0 → n-1)
```

This technique avoids shifting elements repeatedly and makes the algorithm optimal.
