# 🔢 Largest Prime Factor

## 📌 Problem Statement

Given a number `n`, find the **largest prime factor** of `n`.

A **prime factor** is a prime number that divides the number exactly.

---

# 🧠 Examples

### Example 1

```
Input : n = 5
Output : 5
```

Explanation

```
5 = 5
```

Prime factors → `5`

Largest prime factor → **5**

---

### Example 2

```
Input : n = 24
Output : 3
```

Explanation

```
24 = 2 × 2 × 2 × 3
```

Prime factors → `2, 3`

Largest prime factor → **3**

---

### Example 3

```
Input : n = 13195
Output : 29
```

Explanation

```
13195 = 5 × 7 × 13 × 29
```

Largest prime factor → **29**

---

# 💡 Key Idea

To find the largest prime factor:

1. Start checking from the smallest prime number `2`.
2. If `n` is divisible by that number, divide it.
3. Continue dividing until it is no longer divisible.
4. Move to the next number.
5. Repeat until `i * i > n`.

Any number left after this process is also a **prime factor**.

---

# 🔄 Dry Run

### Example

```
n = 24
```

Step 1

```
i = 2
24 % 2 = 0
```

```
largest = 2
n = 24 / 2 = 12
```

---

Step 2

```
12 % 2 = 0
```

```
largest = 2
n = 12 / 2 = 6
```

---

Step 3

```
6 % 2 = 0
```

```
largest = 2
n = 6 / 2 = 3
```

---

Step 4

Now

```
n = 3
```

Loop stops because

```
i * i > n
```

Since

```
n > 1
```

```
largest = 3
```

Final answer

```
3
```

---

# 💻 C++ Code

```cpp
class Solution {
  public:
    int largestPrimeFactor(int n) {
        
        int largest = -1;

        for(int i = 2; i * i <= n; i++){
            
            while(n % i == 0){
                largest = i;
                n = n / i;
            }
        }

        if(n > 1)
            largest = n;

        return largest;
    }
};
```

---

# ⏱ Complexity

| Complexity       | Value     |
| ---------------- | --------- |
| Time Complexity  | **O(√n)** |
| Space Complexity | **O(1)**  |

---

# 🎯 Key Insight

We only check factors up to:

```
√n
```

because factors appear in **pairs**.

Example:

```
36
```

Factor pairs

```
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

After `√36 = 6`, factors repeat.

---

# ⚡ Important Line

```
if(n > 1)
    largest = n;
```

This handles the case where a **prime factor larger than √n remains** after removing smaller factors.

Example

```
15 = 3 × 5
```

After removing `3`, the remaining number `5` is the **largest prime factor**.

---

⭐ This is a common **number theory / DSA problem** asked in coding interviews and competitive programming.
