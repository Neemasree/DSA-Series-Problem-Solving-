🚀 Check Whether a Number is Prime or Not
📌 Problem

Given an integer n, determine whether the number is Prime or Not Prime.

A prime number is a natural number greater than 1 that has exactly two factors:

1

The number itself

🧠 Example
Example 1

Input

n = 7

Output

Prime

Explanation
7 has only two factors: 1 and 7

Example 2

Input

n = 9

Output

Not Prime

Explanation
9 has factors 1, 3, and 9, so it is not a prime number.

❗ Important Points

A prime number must be greater than 1

It must have exactly two factors

If any number between 2 and n-1 divides n, it is not prime

🛠 Approach 1 — Brute Force
Idea

Check if any number from 2 to n-1 divides n.

If we find a divisor, the number has more than two factors and therefore is not prime.

If no divisor is found, the number is prime.

💻 C++ Implementation
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    if(n <= 1){
        cout << "Not Prime";
        return 0;
    }

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cout << "Not Prime";
            return 0;
        }
    }

    cout << "Prime";

}
⏱ Complexity
Type	Complexity
Time Complexity	O(n)
Space Complexity	O(1)
🛠 Approach 2 — Optimized Approach (Square Root Method)
Idea

Factors of a number always appear in pairs.

Example:

36

Factor pairs:

1 × 36
2 × 18
3 × 12
4 × 9
6 × 6

Notice that all factor pairs meet around √36 = 6.

So instead of checking all numbers up to n, we only need to check up to √n.

This significantly reduces the number of operations.

💻 C++ Implementation
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    if(n <= 1){
        cout << "Not Prime";
        return 0;
    }

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            cout << "Not Prime";
            return 0;
        }
    }

    cout << "Prime";

}
⏱ Complexity
Type	Complexity
Time Complexity	O(√n)
Space Complexity	O(1)
📊 Approach Summary
Approach	Time	Space
Brute Force	O(n)	O(1)
Optimized (√n)	O(√n)	O(1)
💡 Key Concepts

Divisibility check using %

Understanding factors

Optimization using square root

Reducing unnecessary iterations

⭐ If this repository helped you understand the problem, consider giving it a star!
