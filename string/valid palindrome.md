# Valid Palindrome – Two Pointer Approach (C++)

## Problem Statement

Given a string `s`, determine if it is a palindrome after:

- Ignoring spaces
- Ignoring symbols/punctuation
- Ignoring uppercase and lowercase differences

A palindrome reads the same forward and backward.

---

# Example 1

```txt
Input:
"A man, a plan, a canal: Panama"

Output:
true
```

Processed string:

```txt
amanaplanacanalpanama
```

---

# Example 2

```txt
Input:
"race a car"

Output:
false
```

Processed string:

```txt
raceacar
```

---

# C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            while(left < right && !isalnum(s[left])) {
                left++;
            }

            while(left < right && !isalnum(s[right])) {
                right--;
            }

            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

# Approach Used → Two Pointers

We use two pointers:

- `left` → starts from beginning
- `right` → starts from end

Both move toward the center while comparing characters.

---

# Step 1 → Initialize Pointers

```cpp
int left = 0;
int right = s.length() - 1;
```

Example:

```txt
m a d a m
0 1 2 3 4
```

So:

```txt
left = 0
right = 4
```

---

# Step 2 → Traverse Until Pointers Meet

```cpp
while(left < right)
```

Continue checking until both pointers cross or meet.

---

# Why `left < right`?

Because once both pointers meet, all comparisons are completed.

Example:

```txt
m a d a m
↑       ↑
```

Then:

```txt
  ↑   ↑
```

Then:

```txt
    ↑
```

Done.

---

# Step 3 → Skip Special Characters

```cpp
while(left < right && !isalnum(s[left])) {
    left++;
}
```

## What is `isalnum()`?

Checks whether a character is:

- alphabet (`a-z`, `A-Z`)
- number (`0-9`)

Returns:

- `true` → valid character
- `false` → special character

---

# What is `!isalnum()`?

`!` means NOT.

So:

```cpp
!isalnum(s[left])
```

means:

```txt
"If this character is NOT a letter or number"
```

Then we skip it.

---

# Example

```txt
s = "a,b"
```

At comma:

```cpp
isalnum(',')
```

returns:

```txt
false
```

So:

```cpp
!false = true
```

Therefore comma gets skipped.

---

# Right Side Skip

```cpp
while(left < right && !isalnum(s[right])) {
    right--;
}
```

This skips symbols from the right side.

---

# Step 4 → Compare Characters

```cpp
if(tolower(s[left]) != tolower(s[right])) {
    return false;
}
```

---

# What is `tolower()`?

Converts uppercase letters into lowercase.

Example:

```cpp
tolower('M')
```

becomes:

```txt
'm'
```

---

# Why Use `tolower()`?

Because:

```cpp
'M' != 'm'
```

is TRUE in C++.

But for palindrome checking:

```txt
'M' and 'm' should be treated as same
```

So we convert both characters to lowercase before comparing.

---

# Dry Run of Comparison

Example:

```cpp
s = "Madam"
```

Indexes:

```txt
M a d a m
0 1 2 3 4
```

Initial:

```txt
left = 0
right = 4
```

Characters:

```cpp
s[left]  = 'M'
s[right] = 'm'
```

Convert to lowercase:

```cpp
tolower('M') = 'm'
tolower('m') = 'm'
```

Comparison:

```cpp
if('m' != 'm')
```

Result:

```txt
false
```

So characters match.

---

# Move Both Pointers

```cpp
left++;
right--;
```

Now:

```txt
M a d a m
  ↑   ↑
```

Continue the same process.

---

# Example Where It Returns False

```cpp
s = "race a car"
```

Processed idea:

```txt
raceacar
```

Comparisons:

```txt
r == r
a == a
c == c
e != a
```

At:

```txt
e != a
```

Condition becomes TRUE.

So:

```cpp
return false;
```

---

# Important Operators

| Operator | Meaning |
|---|---|
| `!=` | Not Equal To |
| `&&` | AND |
| `!` | NOT |

---

# Important Functions

| Function | Meaning |
|---|---|
| `isalnum(ch)` | Checks if character is letter/number |
| `tolower(ch)` | Converts character to lowercase |

---

# Complete Dry Run

Input:

```txt
"A man, a plan, a canal: Panama"
```

Initial:

```txt
left → 'A'
right → 'a'
```

Lowercase:

```txt
a == a
```

Move inward.

---

# Skip Spaces

Left reaches `' '`.

This runs:

```cpp
!isalnum(' ')
```

TRUE → skip space.

---

# Continue Comparing

```txt
m == m
a == a
n == n
```

All characters match.

Finally:

```cpp
return true;
```

---

# Time Complexity

## Time

```txt
O(n)
```

Each character is visited at most once.

---

# Space Complexity

```txt
O(1)
```

No extra space used.

---

# Final Algorithm

```txt
1. Start one pointer from beginning
2. Start another pointer from end
3. Skip special characters
4. Convert both characters to lowercase
5. Compare characters
6. If mismatch → return false
7. Otherwise continue
8. If all matched → return true
```
