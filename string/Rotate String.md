# Rotate String - LeetCode 796

## Problem

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.

A shift means:
- take the first character
- move it to the end

---

# Example 1

## Input
```text
s = "abcde"
goal = "cdeab"
```

## Shifts

```text
abcde
↓
bcdea
↓
cdeab
```

Now it matches `goal`.

## Output
```text
true
```

---

# Example 2

## Input
```text
s = "abcde"
goal = "abced"
```

After all possible rotations:

```text
bcdea
cdeab
deabc
eabcd
abcde
```

We never get:

```text
abced
```

## Output
```text
false
```

---

# Main Idea

If `goal` is a valid rotation of `s`,
then `goal` will always exist inside:

```cpp
s + s
```

---

# Example

```text
s = "abcde"
```

```cpp
s + s
```

becomes:

```text
abcdeabcde
```

Inside it:

```text
abcdeabcde
  ↑↑↑↑↑
  cdeab
```

So `"cdeab"` is a valid rotation.

---

# Algorithm

1. Check if lengths are equal
2. Create:
   ```cpp
   temp = s + s
   ```
3. Check whether `goal` exists inside `temp`
4. If found → `true`
5. Otherwise → `false`

---

# C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool rotateString(string s, string goal) {

        // Step 1:
        // If lengths differ,
        // rotation impossible
        if(s.size() != goal.size()) {
            return false;
        }

        // Step 2:
        // Join string with itself
        string temp = s + s;

        // Example:
        // abcdeabcde

        // Step 3:
        // Search goal inside temp
        if(temp.find(goal) != string::npos) {
            return true;
        }

        // Step 4:
        return false;
    }
};
```

---

# Understanding `find()`

```cpp
temp.find(goal)
```

Means:

```text
Search for goal inside temp
```

---

# Example

```cpp
string s = "abcdeabcde";
```

```cpp
s.find("cde")
```

Returns:

```text
2
```

because `"cde"` starts at index `2`.

---

# If Not Found

```cpp
s.find("xyz")
```

Returns:

```cpp
string::npos
```

Meaning:

```text
NOT FOUND
```

---

# Important Line

```cpp
temp.find(goal) != string::npos
```

Means:

```text
If goal exists inside temp
```

---

# Time Complexity

## Time
```text
O(n²)
```

## Space
```text
O(n)
```

---

# LeetCode Link

https://leetcode.com/problems/rotate-string/
