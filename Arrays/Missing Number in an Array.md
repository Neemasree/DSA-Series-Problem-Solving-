# 🔍 Missing Number in an Array

## 📌 Problem Statement

Given an array `arr[]` of size **n−1** containing **distinct integers from 1 to n**, exactly **one number is missing**.

Your task is to **find the missing number**.

---

## 🧠 Example

### Input

```
arr = [1, 2, 4, 5]
```

### Expected Numbers

```
1 2 3 4 5
      ↑
   missing
```

### Output

```
3
```

---

# 🚀 Approaches

We can solve this problem using **five approaches**:

1️⃣ Brute Force
2️⃣ Sorting Approach
3️⃣ Hashing (Better)
4️⃣ Sum Formula (Optimal)
5️⃣ XOR (Optimal)

---

# 1️⃣ Brute Force Approach

## 💡 Idea

Check every number from **1 → n** and search for it in the array.

If a number is **not found**, then it is the **missing number**.

---

## 🔄 Dry Run

Example

```
arr = [1, 2, 4, 5]
```

Numbers that should exist:

```
1 2 3 4 5
```

Steps:

```
Check 1 → found ✔
Check 2 → found ✔
Check 3 → NOT found ❌
```

Missing number:

```
3
```

---

## 💻 Code

```cpp
class Solution {
public:
    int missingNum(vector<int>& arr) {

        int n = arr.size() + 1;

        for(int i = 1; i <= n; i++) {

            bool found = false;

            for(int j = 0; j < arr.size(); j++) {
                if(arr[j] == i) {
                    found = true;
                    break;
                }
            }

            if(!found) return i;
        }

        return -1;
    }
};
```

---

## ⏱ Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n²) |
| Space Complexity | O(1)  |

⚠️ Very slow for large arrays.

---

# 2️⃣ Sorting Approach

## 💡 Idea

Sort the array first. Then check if the **difference between consecutive elements is greater than 1**.

If the difference is not `1`, the missing number lies between them.

---

## 🔄 Dry Run

Example

```
arr = [1,2,4,5]
```

After sorting:

```
1 2 4 5
```

Check differences:

```
2 - 1 = 1 ✔
4 - 2 = 2 ❌
```

So the missing number is:

```
3
```

---

## 💻 Code

```cpp
class Solution {
public:
    int missingNum(vector<int>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        if(arr[0] != 1)
            return 1;

        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] != 1){
                return arr[i] - 1;
            }
        }

        return n + 1;
    }
};
```

---

## ⏱ Complexity

| Metric           | Value      |
| ---------------- | ---------- |
| Time Complexity  | O(n log n) |
| Space Complexity | O(1)       |

Sorting makes it slower than optimal methods.

---

# 3️⃣ Hashing Approach (Better)

## 💡 Idea

Use a **hash array** to mark which numbers are present.

Steps:

1. Create a hash array of size `n+1`
2. Mark each element present in the array
3. The index that remains unmarked is the missing number

---

## 🔄 Visualization

Example

```
arr = [1,2,4,5]
```

Hash array initially:

```
Index : 0 1 2 3 4 5
Value : 0 0 0 0 0 0
```

Mark numbers:

```
arr[0] = 1 → hash[1] = 1
arr[1] = 2 → hash[2] = 1
arr[2] = 4 → hash[4] = 1
arr[3] = 5 → hash[5] = 1
```

Result:

```
Index : 0 1 2 3 4 5
Value : 0 1 1 0 1 1
```

Check:

```
3 → not marked
```

Missing number:

```
3
```

---

## 💻 Code

```cpp
class Solution {
public:
    int missingNum(vector<int>& arr) {

        int n = arr.size() + 1;

        vector<int> hash(n+1,0);

        for(int i=0;i<arr.size();i++){
            hash[arr[i]] = 1;
        }

        for(int i=1;i<=n;i++){
            if(hash[i]==0)
                return i;
        }

        return -1;
    }
};
```

---

## ⏱ Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(n)  |

---

# 4️⃣ Sum Formula Approach (Optimal)

## 💡 Idea

The sum of the first **n natural numbers** is:

```
n(n+1)/2
```

Steps:

1. Calculate **expected sum**
2. Calculate **actual sum of array**
3. Missing number = **Expected − Actual**

---

## 🔄 Dry Run

Example

```
arr = [1,2,4,5]
```

Expected numbers:

```
1 2 3 4 5
```

Expected sum:

```
1 + 2 + 3 + 4 + 5 = 15
```

Actual sum:

```
1 + 2 + 4 + 5 = 12
```

Difference:

```
15 - 12 = 3
```

Missing number:

```
3
```

---

## 💻 Code

```cpp
class Solution {
public:
    int missingNum(vector<int>& arr) {

        long long n = arr.size() + 1;

        long long total = n*(n+1)/2;

        long long sum = 0;

        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }

        return total - sum;
    }
};
```

---

## ⏱ Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

⚠️ Can overflow if numbers are extremely large.

---

# 5️⃣ XOR Approach (Optimal)

## 💡 Idea

XOR properties:

```
a ^ a = 0
a ^ 0 = a
```

Steps:

1. Compute XOR of numbers **1 → n**
2. Compute XOR of array elements
3. XOR both results

Duplicate numbers cancel out.

---

## 🔄 Dry Run

Example

```
arr = [1,2,4,5]
```

Numbers should be:

```
1 2 3 4 5
```

Step 1

```
1 ^ 2 ^ 3 ^ 4 ^ 5
```

Step 2

```
1 ^ 2 ^ 4 ^ 5
```

Combine:

```
(1^2^3^4^5) ^ (1^2^4^5)
```

Cancel common numbers:

```
1 ^ 1 = 0
2 ^ 2 = 0
4 ^ 4 = 0
5 ^ 5 = 0
```

Remaining:

```
3
```

Missing number:

```
3
```

---

## 💻 Code

```cpp
class Solution {
public:
    int missingNum(vector<int>& arr) {

        int n = arr.size() + 1;

        int xor1 = 0;
        int xor2 = 0;

        for(int i=1;i<=n;i++)
            xor1 ^= i;

        for(int i=0;i<arr.size();i++)
            xor2 ^= arr[i];

        return xor1 ^ xor2;
    }
};
```

---

# 📊 Comparison of Approaches

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute Force | O(n²)           | O(1)             |
| Sorting     | O(n log n)      | O(1)             |
| Hashing     | O(n)            | O(n)             |
| Sum Formula | O(n)            | O(1)             |
| XOR         | O(n)            | O(1)             |

---

# 🏆 Best Approach

The **XOR approach** is usually preferred because:

✔ **O(n) time**
✔ **O(1) space**
✔ No overflow issues
✔ Elegant mathematical trick

---

# ⭐ Key Takeaway

If you see a problem like:

```
Numbers from 1 → n
Exactly one number missing
```

Immediately think of:

```
Sum Formula
or
XOR Trick
```

Both provide **optimal solutions with O(n) time and O(1) space**.
