# 242. Valid Anagram

## Problem
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

An anagram means:
- same characters
- same frequencies
- order can be different

Example:
```text
s = "anagram"
t = "nagaram"

Output = true
```

---

# Main Idea

We use:

- Frequency Array

Because:
- Anagrams must contain same character counts

---

# Step 1 — Check Length

```cpp
if(s.length() != t.length()) return false;
```

## Why?

If lengths are different:
- frequencies can never match
- so not an anagram

Example:
```text
s = "abc"
t = "ab"

lengths:
3 != 2

return false
```

---

# Step 2 — Create Frequency Array

```cpp
vector<int> freq(26,0);
```

## Why size 26?

Because:
- lowercase English letters
- a to z

Each index stores frequency.

Example:
```text
index 0 -> a
index 1 -> b
index 2 -> c
...
```

---

# Step 3 — Count Characters of s

```cpp
for(char c : s){
    freq[c-'a']++;
}
```

Example:
```text
s = "abca"
```

Frequency becomes:
```text
a = 2
b = 1
c = 1
```

---

# Why `c-'a'`?

Suppose:
```text
c = 'c'
```

ASCII:
```text
'c' - 'a'
= 99 - 97
= 2
```

So:
```text
freq[2]
```

stores count of `'c'`.

---

# Step 4 — Remove Characters of t

```cpp
for(char c : t){
    freq[c-'a']--;
}
```

## Why `--`?

Because:
- we already counted characters from `s`
- now remove matching characters from `t`

If both strings are anagrams:
- all frequencies become 0

---

# Full Dry Run

```text
s = "ab"
t = "ba"
```

Initial:
```text
all freq = 0
```

After counting s:
```text
a = 1
b = 1
```

After removing t:

Remove `'b'`
```text
b = 0
```

Remove `'a'`
```text
a = 0
```

Final:
```text
all frequencies = 0
```

So:
```text
true
```

---

# Step 5 — Check Frequencies

```cpp
for(int x : freq){
    if(x != 0) return false;
}
```

## Why?

If any frequency is not 0:
- some character count did not match

So strings are not anagrams.

---

# Final Code

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // length check
        if(s.length() != t.length()) return false;

        // frequency array
        vector<int> freq(26,0);

        // count characters of s
        for(char c : s){
            freq[c-'a']++;
        }

        // remove characters using t
        for(char c : t){
            freq[c-'a']--;
        }

        // check frequencies
        for(int x : freq){
            if(x != 0) return false;
        }

        return true;
    }
};
```

---

# Time Complexity

```text
O(n)
```

Because:
- we traverse strings once

---

# Space Complexity

```text
O(1)
```

Because:
- frequency array size is fixed (26)
