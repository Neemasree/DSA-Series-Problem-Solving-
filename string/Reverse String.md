# 344. Reverse String

## Problem
Write a function that reverses a character array `s`.

You must do it:
- in-place
- with `O(1)` extra memory

Example:
```text
Input:
s = ['h','e','l','l','o']

Output:
['o','l','l','e','h']
```

---

# Main Idea

We use:

- Two Pointers

Because:
- one pointer starts from left
- one pointer starts from right
- swap both characters
- move inward

---

# Visual Understanding

```text
h e l l o
L       R
```

Swap:
```text
o e l l h
```

Move pointers:
```text
o e l l h
  L   R
```

Swap again:
```text
o l l e h
```

Pointers meet → stop.

---

# Step 1 — Create Two Pointers

```cpp
int left = 0;
int right = s.size() - 1;
```

Example:
```text
s = ['h','e','l','l','o']

left = 0
right = 4
```

---

# Step 2 — Run Loop Until Pointers Cross

```cpp
while(left < right)
```

## Why?

Because:
- once pointers meet/cross
- array is fully reversed

---

# Step 3 — Swap Characters

```cpp
swap(s[left], s[right]);
```

This swaps:
- left character
- right character

---

# Step 4 — Move Pointers

```cpp
left++;
right--;
```

Why?
- left moves forward
- right moves backward
- continue reversing inside part

---

# Full Dry Run

## Initial Array

```text
h e l l o
L       R
```

---

## Iteration 1

Swap:
```text
h ↔ o
```

Array:
```text
o e l l h
```

Move:
```text
  L   R
```

---

## Iteration 2

Swap:
```text
e ↔ l
```

Array:
```text
o l l e h
```

Move:
```text
    L R
```

Now:
```text
left >= right
```

Stop.

---

# Final Reversed Array

```text
o l l e h
```

---

# Final Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right){

            // swap left and right characters
            swap(s[left], s[right]);

            // move pointers
            left++;
            right--;
        }
    }
};
```

---

# Why This Works

Every iteration:
- correct left character goes to correct right position
- correct right character goes to correct left position

Eventually entire array becomes reversed.

---

# Time Complexity

```text
O(n)
```

Because:
- each character visited once

---

# Space Complexity

```text
O(1)
```

Because:
- no extra array used
- reversal happens in-place

---

# Important Concept Used

## Two Pointer Technique

```text
left → ← right
```

Very important for:
- palindrome
- reverse array/string
- sorted array problems
- container problems

---
