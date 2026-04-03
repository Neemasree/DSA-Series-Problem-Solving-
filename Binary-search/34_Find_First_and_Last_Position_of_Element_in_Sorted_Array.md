# 🔎 Find First and Last Position of Element in Sorted Array  
**LeetCode 34 | Binary Search | Striver A2Z Sheet**

---

# 📌 Problem Statement

Given a **sorted array** `nums` of integers, find the **starting and ending position** of a given `target`.

If the target is not found, return:

    [-1, -1]

You must write an algorithm with **O(log n)** runtime complexity.

---

# 🧾 Example

### Example 1

Input:  
nums = [5,7,7,8,8,10]  
target = 8  

Output:  
[3,4]

---

### Example 2

Input:  
nums = [5,7,7,8,8,10]  
target = 6  

Output:  
[-1,-1]

---

# 🧠 Intuition (Striver Style)

We need to find:

- **First Occurrence**
- **Last Occurrence**

There are **three approaches**:

1. Brute Force  
2. Binary Search Twice  
3. Lower Bound + Upper Bound (**Best Approach ⭐**)

---

# 🚀 Approach 1 — Brute Force (Linear Search)

## 💡 Idea

Traverse the entire array and record:

- First index where target appears  
- Last index where target appears  

---

## ⏱ Time Complexity

O(n)

## 📦 Space Complexity

O(1)

---

## 💻 Code

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {

            int first = -1;
            int last = -1;

            for(int i = 0; i < nums.size(); i++) {

                if(nums[i] == target) {

                    if(first == -1)
                        first = i;

                    last = i;
                }
            }

            return {first, last};
        }
    };

---

# 🚀 Approach 2 — Binary Search Twice  
(**Find First & Last Separately**)

---

## 💡 Idea

Run binary search **two times**:

1. Find **first occurrence**
2. Find **last occurrence**

For:

- First → Move Left  
- Last → Move Right  

---

## ⏱ Time Complexity

O(log n)

## 📦 Space Complexity

O(1)

---

## 💻 Code

    class Solution {
    public:

        int firstOccurrence(vector<int>& nums, int target) {

            int low = 0;
            int high = nums.size() - 1;
            int ans = -1;

            while(low <= high) {

                int mid = (low + high) / 2;

                if(nums[mid] == target) {
                    ans = mid;
                    high = mid - 1;
                }

                else if(nums[mid] < target) {
                    low = mid + 1;
                }

                else {
                    high = mid - 1;
                }
            }

            return ans;
        }

        int lastOccurrence(vector<int>& nums, int target) {

            int low = 0;
            int high = nums.size() - 1;
            int ans = -1;

            while(low <= high) {

                int mid = (low + high) / 2;

                if(nums[mid] == target) {
                    ans = mid;
                    low = mid + 1;
                }

                else if(nums[mid] < target) {
                    low = mid + 1;
                }

                else {
                    high = mid - 1;
                }
            }

            return ans;
        }

        vector<int> searchRange(vector<int>& nums, int target) {

            int first = firstOccurrence(nums, target);
            int last  = lastOccurrence(nums, target);

            return {first, last};
        }
    };

---

# 🚀 Approach 3 — Lower Bound + Upper Bound  
(**Striver Recommended Method ⭐**)

This is the **most important and reusable method**.

---

# 📌 Key Concepts

## 🔹 Lower Bound

Returns:

First index ≥ target

Example:

arr = [1,2,4,4,5]  
target = 4  

lowerBound → 2  

---

## 🔹 Upper Bound

Returns:

First index > target

Example:

arr = [1,2,4,4,5]  
target = 4  

upperBound → 4  

---

# 🧠 Why `ans = n` ?

Very important Striver concept.

We initialize:

int ans = n;

Because if element **doesn't exist**, lower bound returns:

index = n

Example:

arr = [2,4,6,8]  
target = 10  

lowerBound → 4  
(n = 4)

That helps detect:

if(lb == n)  
→ element not found  

---

# ⭐ Final Optimized Code (Striver Style)

    class Solution {
    public:

        // LOWER BOUND
        int lowerbound(vector<int> arr, int n, int x) {

            int low = 0;
            int high = n - 1;
            int ans = n;

            while(low <= high) {

                int mid = (low + high) / 2;

                if(arr[mid] >= x) {
                    ans = mid;
                    high = mid - 1;
                }

                else {
                    low = mid + 1;
                }
            }

            return ans;
        }

        // UPPER BOUND
        int upperbound(vector<int> arr, int n, int x) {

            int low = 0;
            int high = n - 1;
            int ans = n;

            while(low <= high) {

                int mid = (low + high) / 2;

                if(arr[mid] > x) {
                    ans = mid;
                    high = mid - 1;
                }

                else {
                    low = mid + 1;
                }
            }

            return ans;
        }

        vector<int> searchRange(vector<int>& arr, int target) {

            int n = arr.size();

            int lb = lowerbound(arr, n, target);

            if(lb == n || arr[lb] != target)
                return {-1, -1};

            return {lb, upperbound(arr, n, target) - 1};
        }
    };

---

# 📊 Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|----------|----------------|-----------------|
| Brute Force | O(n) | O(1) |
| Binary Search Twice | O(log n) | O(1) |
| Lower Bound + Upper Bound ⭐ | O(log n) | O(1) |

---

# 🧪 Important Edge Cases

nums = [] , target = 5  

nums = [1] , target = 1  

nums = [1,1,1,1] , target = 1  

nums = [2,4,6,8] , target = 10  

nums = [5,7,7,8,8,10] , target = 8  

---

# ⭐ Best Approach

Lower Bound + Upper Bound

✔ Clean  
✔ Fast  
✔ Reusable  
✔ Interview Friendly  

This problem helps understand:

- Binary Search Variants  
- Lower Bound  
- Upper Bound  
- First Occurrence  
- Last Occurrence  
- Range Finding  

Very important before:

- Count Occurrences in Sorted Array  
- Floor and Ceil in Sorted Array  
- Search Insert Position  
  
- Search Insert Position  

---
