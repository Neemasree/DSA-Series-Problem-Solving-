# 🔢 Find All Factors of a Number

## 📌 Problem

Given an integer `n`, print **all the factors (divisors)** of `n`.

A **factor** of a number is a number that divides it **exactly without leaving a remainder**.

```
a is a factor of n if n % a == 0
```

---

# 🧠 Example

### Example 1

```
Input  : n = 12
Output : 1 2 3 4 6 12
```

Explanation

```
12 % 1 = 0
12 % 2 = 0
12 % 3 = 0
12 % 4 = 0
12 % 6 = 0
12 % 12 = 0
```

So the factors are:

```
1, 2, 3, 4, 6, 12
```

---

# 🟥 Approach 1: Brute Force (O(n))

## 💡 Idea

Check every number from:

```
1 → n
```

If the number divides `n`, it is a factor.

---

## 🔄 Dry Run

Example

```
n = 12
```

Check divisibility:

| i  | 12 % i | Factor? |
| -- | ------ | ------- |
| 1  | 0      | Yes     |
| 2  | 0      | Yes     |
| 3  | 0      | Yes     |
| 4  | 0      | Yes     |
| 5  | 2      | No      |
| 6  | 0      | Yes     |
| 7  | 5      | No      |
| 8  | 4      | No      |
| 9  | 3      | No      |
| 10 | 2      | No      |
| 11 | 1      | No      |
| 12 | 0      | Yes     |

Factors:

```
1 2 3 4 6 12
```

---

## 💻 Code (O(n))

```cpp
#include <iostream>
using namespace std;

void printFactors(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            cout << i << " ";
    }
}

int main()
{
    int n = 12;

    printFactors(n);
}
```

---

## ⏱ Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(1)  |

⚠️ Slow for large numbers.

---

# 🟩 Approach 2: Optimal (O√n)

## 💡 Key Observation

Factors always occur in **pairs**.

Example

```
36
```

Factor pairs:

```
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

After `√36 = 6`, the factors start repeating.

So we only need to check up to:

```
√n
```

---

## 🔄 Dry Run

Example

```
n = 36
```

```
√36 = 6
```

Check:

| i | Pair | Factors    |
| - | ---- | ---------- |
| 1 | 36   | 1,36       |
| 2 | 18   | 2,18       |
| 3 | 12   | 3,12       |
| 4 | 9    | 4,9        |
| 5 | —    | Not factor |
| 6 | 6    | 6          |

Factors:

```
1 36 2 18 3 12 4 9 6
```

---

## 💻 Code (O√n)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

void printFactors(int n)
{
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            cout << i << " ";

            if(i != n / i)
                cout << n / i << " ";
        }
    }
}

int main()
{
    int n = 36;

    printFactors(n);
}
```

---

## ⏱ Complexity

| Time  | Space |
| ----- | ----- |
| O(√n) | O(1)  |

✅ Much faster for large numbers.

---

# 📊 Comparison

| Approach    | Time Complexity | Space |
| ----------- | --------------- | ----- |
| Brute Force | O(n)            | O(1)  |
| Optimal     | O(√n)           | O(1)  |

---

# 🎯 Key Insight

To efficiently find factors:

```
Check divisibility from 1 → √n
```

Whenever `i` divides `n`, we get **two factors**:

```
i and n/i
```

This reduces the time complexity significantly.

---

⭐ This is a **very common number theory problem** asked in coding interviews and DSA practice.
