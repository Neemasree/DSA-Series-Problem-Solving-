# 58. Length of Last Word

## Problem
Given a string `s` consisting of words and spaces, return the length of the **last word**.

A word is:
- a sequence of non-space characters

---

# Example 1

```text
Input:
s = "Hello World"

Output:
5
```

Because:
```text
Last word = "World"
Length = 5
```

---

# Example 2

```text
Input:
s = "   fly me   to   the moon  "

Output:
4
```

Because:
```text
Last word = "moon"
Length = 4
```

---

# Main Idea

We start from the **end of the string** because:
- we only need the last word
- the last word is closest to the end

---

# Steps

1. Skip trailing spaces
2. Count characters of last word
3. Stop when space appears

---

# Step 1 — Start From End

```cpp
int i = s.length() - 1;
```

Example:
```text
s = "Hello World"

Index:
0 1 2 3 4 5 6 7 8 9 10

Characters:
H e l l o   W o r l  d
```

`i` starts at:
```text
d
```

---

# Step 2 — Skip Trailing Spaces

```cpp
while(i >= 0 && s[i] == ' '){
    i--;
}
```

## Why?

Sometimes string ends with spaces.

Example:
```text
"Hello World   "
```

We must ignore them first.

---

# Dry Run

```text
s = "Hello World   "
```

Start:
```text
i -> ' '
```

Skip:
```text
i--
i--
i--
```

Now:
```text
i -> 'd'
```

---

# Step 3 — Count Last Word

```cpp
int len = 0;

while(i >= 0 && s[i] != ' '){
    len++;
    i--;
}
```

## Why?

Keep counting until:
- start of string OR
- space appears

---

# Full Dry Run

```text
s = "Hello World"
```

After skipping spaces:
```text
i -> 'd'
```

Count:

```text
d -> len = 1
l -> len = 2
r -> len = 3
o -> len = 4
W -> len = 5
```

Next character:
```text
space
```

Stop.

Answer:
```text
5
```

---

# Final Code

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.length() - 1;

        // skip trailing spaces
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        // count last word
        int len = 0;

        while(i >= 0 && s[i] != ' '){
            len++;
            i--;
        }

        return len;
    }
};
```

---

# Why This Works

We:
- ignore ending spaces
- then count only the final word

So answer becomes length of last word.

---

# Time Complexity

```text
O(n)
```

Because:
- in worst case we traverse whole string once

---

# Space Complexity

```text
O(1)
```

Because:
- only variables used
- no extra array/string

---

# Important Concept Used

## Reverse Traversal

```text
End → Start
```

Useful for:
- last word problems
- trimming spaces
- suffix-based questions

---
