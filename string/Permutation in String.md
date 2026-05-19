# 567. Permutation in String

## Problem
Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, otherwise return `false`.

A permutation means:
- same characters
- same frequencies
- order can change

Example:
```text
s1 = "ab"

Permutations:
ab
ba
```

---

# Main Idea

We use:

- Sliding Window
- Frequency Array

Because:
- Every permutation of `s1` has same length as `s1`
- So we only check windows of size `m`

---

# Step 1 — Variables

```cpp
int m = s1.length();
int n = s2.length();
```

Example:

```text
s1 = "ab"
m = 2

s2 = "eidbaooo"
n = 8
```

---

# Important Edge Case

```cpp
if(m > n) return false;
```

## Why?

Suppose:

```text
s1 = "abcd"
s2 = "ab"
```

`m = 4`
`n = 2`

A 4-length permutation cannot exist inside a 2-length string.

Without this check:

```cpp
for(int i=0;i<m;i++)
```

tries to access:

```cpp
s2[2]
s2[3]
```

which do not exist.

This causes:
- Runtime Error
- Invalid Memory Access

So we return false immediately.

---

# Frequency Arrays

```cpp
vector<int> need(26,0), window(26,0);
```

- `need` stores frequency of `s1`
- `window` stores frequency of current window in `s2`

Size is 26 because:
- lowercase English letters
- a to z

---

# Step 2 — Store Frequency of s1

```cpp
for(char c : s1){
    need[c-'a']++;
}
```

Example:

```text
s1 = "ab"

need:
a = 1
b = 1
```

---

# Step 3 — Build First Window

```cpp
for(int i=0;i<m;i++){
    window[s2[i]-'a']++;
}
```

## Why `0 to m`?

Because window size must equal length of `s1`.

Example:

```text
s1 = "ab"
m = 2
```

So first window takes first 2 characters of `s2`.

```text
s2 = "eidbaooo"

[e i] d b a o o o
```

Current window:

```text
"ei"
```

---

# Step 4 — Compare First Window

```cpp
if(window == need) return true;
```

If frequencies match:
- current window is a permutation
- return true

---

# Step 5 — Sliding Window

```cpp
for(int r=m;r<n;r++)
```

`r` = right pointer

This loop slides window to the right.

---

# Add New Right Character

```cpp
window[s2[r]-'a']++;
```

When window moves:
- new character enters
- increase frequency

Example:

```text
[e i] d b a
```

Move right:

```text
e [i d] b a
```

`d` entered window.

So:

```cpp
++
```

---

# Remove Old Left Character

```cpp
window[s2[r-m]-'a']--;
```

This is the most important line.

## Why `r-m`?

`r` = current right index
`m` = window size

So:

```text
r - m
```

gives index of old left character.

---

## Example

Current:

```text
[e i]
```

New window:

```text
[i d]
```

`e` left the window.

So decrease frequency of `e`.

That is why we use:

```cpp
--
```

because count is decreasing.

---

# Why `--`?

Before move:

```text
e = 1
i = 1
```

After move:

```text
e = 0
i = 1
d = 1
```

`e` disappeared from window.

So frequency decreases.

---

# Full Dry Run

## Initial Window

```text
[e i] d b a o o o
```

Window = `"ei"`

---

## Slide 1

Add `d`
Remove `e`

```text
e [i d] b a o o o
```

Window = `"id"`

---

## Slide 2

Add `b`
Remove `i`

```text
e i [d b] a o o o
```

Window = `"db"`

---

## Slide 3

Add `a`
Remove `d`

```text
e i d [b a] o o o
```

Window = `"ba"`

`"ba"` is permutation of `"ab"`

Return true.

---

# Final Code

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        if(m > n) return false;

        vector<int> need(26,0), window(26,0);

        // frequency of s1
        for(char c : s1){
            need[c-'a']++;
        }

        // first window
        for(int i=0;i<m;i++){
            window[s2[i]-'a']++;
        }

        // check first window
        if(window == need) return true;

        // slide window
        for(int r=m;r<n;r++){

            // add new right character
            window[s2[r]-'a']++;

            // remove old left character
            window[s2[r-m]-'a']--;

            // compare frequencies
            if(window == need) return true;
        }

        return false;
    }
};
```

---

# Time Complexity

```text
O(n)
```

because:
- each character processed once

---

# Space Complexity

```text
O(1)
```

because frequency arrays are fixed size 26.
