# 📈 Best Time to Buy and Sell Stock — Code Explanation

## 🧩 Problem Overview

You are given an array called `prices`.

- `prices[i]` represents the stock price on day `i`
- You must **buy once**
- You must **sell once**
- You must **buy before selling**
- Your goal is to **find the maximum profit**
- If profit is not possible → return **0**

---

# 💻 Given Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxprofit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            int profit=prices[i]-mini;
            if(profit>maxprofit){
                maxprofit=profit;
            }
        }
        return maxprofit;
    }
};
🧠 Main Idea of This Code

This code works using three main ideas:

Keep track of the minimum price
Calculate profit every day
Store the maximum profit

So basically:

Buy at lowest price
Sell at highest possible price later
🔍 Line-by-Line Explanation
Step 1 — Get number of days
int n = prices.size();

This finds how many prices are given.

Example:

prices = [7,1,5,3,6,4]

n = 6

So there are 6 days.

Step 2 — Store minimum price
int mini = prices[0];

This stores the minimum price so far.

Initially:

mini = first day's price
mini = 7

We assume first day is minimum at the beginning.

Step 3 — Store maximum profit
int maxprofit = 0;

This stores the maximum profit.

Initially:

maxprofit = 0

Because no profit yet.

Step 4 — Traverse all days
for(int i=0;i<n;i++)

This loop checks:

Day 0 → Day n-1

For every day, we:

Check minimum price
Calculate profit
Update maximum profit
Step 5 — Update minimum price
if(prices[i] < mini){
    mini = prices[i];
}

If today's price is smaller, update mini.

Meaning:

We found a better day to buy.

Example:

Current mini = 7
Today's price = 1

1 < 7 → YES

mini = 1

Now buying at 1 is better.

Step 6 — Calculate profit
int profit = prices[i] - mini;

Formula:

Profit = Selling Price − Buying Price

Example:

Selling price = 5
Buying price = 1

profit = 5 − 1 = 4

This checks:

What if we sell today?
Step 7 — Update maximum profit
if(profit > maxprofit){
    maxprofit = profit;
}

If today's profit is bigger:

Store it.

Example:

profit = 4
maxprofit = 0

4 > 0 → YES

maxprofit = 4

Now best profit is 4.

Step 8 — Return final answer
return maxprofit;

Return the maximum profit found.

🧪 Dry Run Example

Input:

prices = [7,1,5,3,6,4]

We track values step by step:

i	price	mini	profit	maxprofit
0	7	7	0	0
1	1	1	0	0
2	5	1	4	4
3	3	1	2	4
4	6	1	5	5
5	4	1	3	5

Final Answer:

maxprofit = 5

Meaning:

Buy at price 1
Sell at price 6
Profit = 5
🎯 Why This Code Works

This code always:

Finds the lowest price
Checks profit every day
Keeps the best profit

So it automatically:

Buys low
Sells high
⚡ Time Complexity
O(n)

Why?

Because:

We loop through array only once
💾 Space Complexity
O(1)

Why?

Because:

Only few variables used
No extra memory needed
🔑 Important Keywords

These are useful for interviews:

Minimum Price Tracking
Maximum Profit Calculation
Single Pass Traversal
Greedy Approach
Array Processing
🏁 Final Summary

This solution works by:

Tracking minimum price
Calculating profit daily
Updating maximum profit
Returning final answer

It is:

Fast → O(n)
Efficient → O(1)
Optimal Solution
bro one complete markdown file fr ths problem

Got you 👍 — you want one complete Markdown file for the whole problem, not just code explanation.
That means: problem + intuition + brute force + optimal + dry run + complexity + key points — all in one single markdown file.

You can copy this and save as:

Best_Time_To_Buy_Sell_Stock.md
# 📈 Best Time to Buy and Sell Stock (LeetCode 121)

## 🧩 Problem Statement

You are given an array `prices` where:

- `prices[i]` represents the stock price on day `i`
- You want to **buy one stock**
- Then **sell it later**
- You must **buy before selling**
- Return the **maximum profit**
- If no profit is possible → return **0**

---

## 📌 Example 1


Input:
prices = [7,1,5,3,6,4]

Output:
5


### Explanation:

- Buy at price **1**
- Sell at price **6**
- Profit = **6 − 1 = 5**

---

## 📌 Example 2


Input:
prices = [7,6,4,3,1]

Output:
0


### Explanation:

Prices always decrease → No profit possible.

---

# 🎯 Understanding the Problem

We want:


Maximum Profit = Sell Price − Buy Price


Rules:

- Buy first
- Sell later
- Only one transaction allowed

---

# 🧠 Intuition (Main Thinking)

We try to:

1. Find **minimum price so far**
2. Calculate profit every day
3. Store **maximum profit**

So:


Buy at lowest price
Sell at highest price after it


---

# 🐢 Brute Force Approach (Slow Method)

Try all possible buy and sell combinations.

---

## Code — Brute Force

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int profit = prices[j] - prices[i];

                if(profit > maxprofit) {
                    maxprofit = profit;
                }

            }

        }

        return maxprofit;
    }
};
Time Complexity
O(n²)

Very slow for large inputs.

⚡ Optimal Approach (Greedy — Best Method)

Instead of checking all combinations:

Track minimum price
Calculate profit daily
Update maximum profit
✅ Optimal Code
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int mini = prices[0];

        int maxprofit = 0;

        for(int i = 0; i < n; i++) {

            if(prices[i] < mini) {
                mini = prices[i];
            }

            int profit = prices[i] - mini;

            if(profit > maxprofit) {
                maxprofit = profit;
            }

        }

        return maxprofit;
    }
};
🔍 Line-by-Line Explanation
Step 1 — Get size of array
int n = prices.size();

Stores number of days.

Example:

prices = [7,1,5,3,6,4]

n = 6
Step 2 — Store minimum price
int mini = prices[0];

Stores minimum price seen so far.

Initially:

mini = 7
Step 3 — Store maximum profit
int maxprofit = 0;

Stores best profit.

Initially:

maxprofit = 0
Step 4 — Traverse array
for(int i = 0; i < n; i++)

Check every day.

Step 5 — Update minimum price
if(prices[i] < mini) {
    mini = prices[i];
}

If today's price is smaller:

Update buying price
Step 6 — Calculate profit
int profit = prices[i] - mini;

Formula:

Profit = Selling Price − Buying Price
Step 7 — Update maximum profit
if(profit > maxprofit) {
    maxprofit = profit;
}

Store best profit.

Step 8 — Return answer
return maxprofit;

Return maximum profit.

🧪 Dry Run Example

Input:

prices = [7,1,5,3,6,4]
i	price	mini	profit	maxprofit
0	7	7	0	0
1	1	1	0	0
2	5	1	4	4
3	3	1	2	4
4	6	1	5	5
5	4	1	3	5

Final:

maxprofit = 5
✌️ Two Pointer View (Alternative Thinking)

We can think of:

left  → Buy day
right → Sell day

Rules:

If price drops → move buy pointer
If price increases → calculate profit
Two Pointer Code
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int left = 0;
        int right = 1;

        int maxprofit = 0;

        while(right < prices.size()) {

            if(prices[right] > prices[left]) {

                int profit =
                prices[right] - prices[left];

                maxprofit =
                max(maxprofit, profit);

            }
            else {

                left = right;

            }

            right++;
        }

        return maxprofit;
    }
};
⚡ Time Complexity
O(n)

Why:

Loop runs once.
💾 Space Complexity
O(1)

Why:

Only few variables used.
🔑 Key Concepts Used
Arrays
Greedy Algorithm
Minimum Tracking
Maximum Profit
Single Traversal
Two Pointer Logic
🎯 Interview Tips

Important things to say:

"We track minimum price so far."
"Calculate profit at each step."
"Update maximum profit."
"This gives O(n) time complexity."
🏁 Final Summary

This problem teaches:

How to track minimum value
How to calculate profit
How to optimize using greedy method
How to solve in one pass

Final Best Complexity:

Time  : O(n)
Space : O(1)
