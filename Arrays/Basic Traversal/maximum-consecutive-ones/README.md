# 🔍 Maximum Consecutive Ones

## 📌 Problem Statement

Given a binary array `nums` containing only **0s and 1s**, find the **maximum number of consecutive 1s** in the array.

---

## 🧠 Example

### Input

```
nums = [1,1,0,1,1,1]
```

### Visualization

```
1 1 0 1 1 1
↑ ↑     ↑ ↑ ↑
2 ones   3 ones
```

### Output

```
3
```

Explanation:

The longest sequence of **continuous 1s** is:

```
1 1 1
```

So the answer is **3**.

---

# 💡 Intuition

We traverse the array and maintain two variables:

```
cnt  → current count of consecutive 1s
maxi → maximum count seen so far
```

### Rules

```
If nums[i] == 1
    increase count

If nums[i] == 0
    reset count to 0
```

Update the maximum whenever the count increases.

---

# 🔄 Dry Run

Example

```
nums = [1,1,0,1,1,1]
```

| Index | Value | Current Count | Max |
| ----- | ----- | ------------- | --- |
| 0     | 1     | 1             | 1   |
| 1     | 1     | 2             | 2   |
| 2     | 0     | 0             | 2   |
| 3     | 1     | 1             | 2   |
| 4     | 1     | 2             | 2   |
| 5     | 1     | 3             | 3   |

Final Answer:

```
3
```

---

# 💻 C++ Code

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == 1){
                cnt++;
                maxi = max(cnt, maxi);
            }
            else{
                cnt = 0;
            }
        }

        return maxi;
    }
};
```

---

# ⚙️ Algorithm Steps

1. Initialize

```
maxi = 0
cnt = 0
```

2. Traverse the array

3. If element is `1`

```
increase cnt
update maxi
```

4. If element is `0`

```
reset cnt = 0
```

5. Return `maxi`

---

# ⏱ Complexity

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

Only **one pass through the array** is required.

---

# 📊 Example Cases

### Case 1

```
nums = [1,0,1,1,0,1]
```

Output

```
2
```

---

### Case 2

```
nums = [1,1,1,1]
```

Output

```
4
```

---

### Case 3

```
nums = [0,0,0]
```

Output

```
0
```

---

# ⭐ Key Takeaway

To solve problems involving **continuous sequences**:

```
Use a running counter
Reset when condition breaks
Track maximum value
```

This pattern appears frequently in **array and sliding window problems** in coding interviews.
