# 🔢 Check Whether a Number is Prime or Not

## 📌 Problem

Given an integer `n`, determine whether the number is **Prime** or **Not Prime**.

### Definition

A **Prime Number** is a number **greater than 1** that has **exactly two divisors**:

* `1`
* the number itself

---

# 🧠 Examples

### Example 1

```
Input  : n = 7
Output : Prime
```

Divisors of 7:

```
1, 7
```

Only two divisors → Prime ✅

---

### Example 2

```
Input  : n = 8
Output : Not Prime
```

Divisors of 8:

```
1, 2, 4, 8
```

More than two divisors → Not Prime ❌

---

# 🟥 Approach 1: O(n) Solution

## 💡 Idea

Check every number from:

```
1 → n
```

Count how many numbers divide `n`.

If the divisor count is **exactly 2**, then the number is **Prime**.

---

## 🔄 Dry Run

Example:

```
n = 7
```

Check divisibility:

| i | 7 % i | Divisible? |
| - | ----- | ---------- |
| 1 | 0     | Yes        |
| 2 | 1     | No         |
| 3 | 1     | No         |
| 4 | 3     | No         |
| 5 | 2     | No         |
| 6 | 1     | No         |
| 7 | 0     | Yes        |

Divisors:

```
1,7
```

Count = 2 → Prime

---

## 💻 Code (O(n))

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }

    if(count == 2)
        return true;

    return false;
}

int main()
{
    int n = 7;

    if(isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";
}
```

---

## ⏱ Complexity

| Time | Space |
| ---- | ----- |
| O(n) | O(1)  |

⚠️ This method is slow for large numbers.

---

# 🟩 Approach 2: O(√n) Solution (Better)

## 💡 Key Observation

Divisors always occur in **pairs**.

Example:

```
36
```

Divisors:

```
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

After `√36 = 6`, divisors repeat.

So we only check up to:

```
√n
```

---

## 🔄 Dry Run

Example:

```
n = 29
```

```
√29 ≈ 5
```

Check:

| i | 29 % i |
| - | ------ |
| 2 | 1      |
| 3 | 2      |
| 4 | 1      |
| 5 | 4      |

No divisors found → Prime

---

## 💻 Code (O√n)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n = 29;

    if(isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";
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

| Approach | Time Complexity | Space |
| -------- | --------------- | ----- |
| O(n)     | O(n)            | O(1)  |
| Better   | O(√n)           | O(1)  |

---

# 🎯 Key Takeaway

Efficient prime checking uses:

```
Check divisibility from 2 → √n
```

If any number divides `n`, then:

```
Not Prime
```

Otherwise:

```
Prime
```

---

⭐ This is a **fundamental number theory problem** commonly asked in coding interviews and competitive programming.
