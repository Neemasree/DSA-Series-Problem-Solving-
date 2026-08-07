# 1021. Remove Outermost Parentheses

## Problem
A valid parentheses string is given.

Remove the **outermost parentheses** of every primitive string and return the result.

---

# What is a Primitive Parentheses String?

A primitive string:
- is non-empty
- is valid
- cannot be split into smaller valid parentheses strings

Example:
```text
(()())(())
```

Primitives:
```text
(()())
(())
```

---

# Example

```text
Input:
s = "(()())(())"

Output:
"()()()"
```

---

# Why?

Primitive 1:
```text
(()())
```

Remove outermost:
```text
()()
```

Primitive 2:
```text
(())
```

Remove outermost:
```text
()
```

Final:
```text
()()()
```

---

# Main Idea

We use:

- Balance Counter

Because:
- `(` increases balance
- `)` decreases balance

Outermost parentheses are:
- first `(` when balance becomes 1
- last `)` when balance becomes 0

We skip those.

---

# Step 1 — Create Answer String

```cpp
string ans = "";
```

Stores final result.

---

# Step 2 — Create Balance Variable

```cpp
int balance = 0;
```

## Meaning

```text
balance =
number of open brackets not closed yet
```

---

# Step 3 — Traverse String

```cpp
for(char c : s)
```

Check every bracket.

---

# Case 1 — Opening Bracket `(`

```cpp
if(c == '(')
```

---

## Important Logic

```cpp
if(balance > 0)
    ans += c;
```

## Why?

If balance is already greater than 0:
- this bracket is NOT outermost
- so include it

Then:

```cpp
balance++;
```

because one new open bracket appeared.

---

# Case 2 — Closing Bracket `)`

First:

```cpp
balance--;
```

because one bracket closed.

Then:

```cpp
if(balance > 0)
    ans += c;
```

## Why?

If balance is still greater than 0:
- this bracket is NOT outermost
- so include it

If balance became 0:
- this is outermost closing bracket
- skip it

---

# Full Dry Run

```text
s = "(()())"
```

---

## Initial

```text
balance = 0
ans = ""
```

---

## Character 1 → '('

```text
balance = 0
```

Condition:
```text
balance > 0 ? NO
```

Don't add.

Now:
```text
balance++
balance = 1
```

---

## Character 2 → '('

```text
balance = 1
```

Condition:
```text
balance > 0 ? YES
```

Add `'('`

```text
ans = "("
```

Now:
```text
balance++
balance = 2
```

---

## Character 3 → ')'

First:
```text
balance--
balance = 1
```

Condition:
```text
balance > 0 ? YES
```

Add `')'`

```text
ans = "()"
```

---

## Character 4 → '('

```text
balance = 1
```

Add `'('`

```text
ans = "()("
```

Then:
```text
balance = 2
```

---

## Character 5 → ')'

```text
balance--
balance = 1
```

Add `')'`

```text
ans = "()()"
```

---

## Character 6 → ')'

```text
balance--
balance = 0
```

Condition:
```text
balance > 0 ? NO
```

Skip it.

---

# Final Answer

```text
()()
```

---

# Final Code

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int balance = 0;

        for(char c : s){

            // opening bracket
            if(c == '('){

                // not outermost
                if(balance > 0){
                    ans += c;
                }

                balance++;
            }

            // closing bracket
            else{

                balance--;

                // not outermost
                if(balance > 0){
                    ans += c;
                }
            }
        }

        return ans;
    }
};
```

---

# Why This Works

Outermost brackets are:
- first opening bracket of primitive
- last closing bracket of primitive

We skip only those.

All inner brackets are added.

---

# Time Complexity

```text
O(n)
```

Because:
- we traverse string once

---

# Space Complexity

```text
O(n)
```

Because:
- answer string stores result

---

# Important Concept Used

## Balance Counter

```text
'(' -> balance++
')' -> balance--
```

Very important for:
- valid parentheses
- stack problems
- bracket matching

---
