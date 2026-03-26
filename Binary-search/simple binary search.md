🔍 Binary Search — Normal & First Occurrence

This repository contains implementations of:

🔹 Binary Search (Normal Search)
🔹 First Occurrence Binary Search
📚 Based on GeeksforGeeks (GFG) Binary Search problems
🚀 Fundamental topic in DSA & Striver A2Z Sheet
📌 Problem 1 — Binary Search (Normal Search)
🧾 Problem Statement

Given a sorted array arr[] and an integer k, return the index of k if present.

If k is not found, return -1.

🧠 Intuition

Binary Search repeatedly divides the array into halves:

Find the middle element
Compare with target
Move left or right
Repeat until found

Works only on:

✅ Sorted Arrays

💻 Implementation — C++
class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {

        int l = 0;
        int r = arr.size() - 1;

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(arr[mid] == k)
                return mid;

            else if(arr[mid] < k)
                l = mid + 1;

            else
                r = mid - 1;
        }

        return -1;
    }
};
📊 Complexity Analysis
Type	Complexity
⏱ Time	O(log n)
💾 Space	O(1)
📌 Problem 2 — First Occurrence Binary Search
🧾 Problem Statement

Given a sorted array arr[] and integer k, return the smallest index where k appears.

If k is not found, return -1.

🧠 Intuition

When the target is found:

Store the index
Continue searching LEFT
This ensures the first occurrence
💻 Implementation — C++
class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {

        int l = 0;
        int r = arr.size() - 1;
        int ans = -1;

        while(l <= r){

            int mid = l + (r - l) / 2;

            if(arr[mid] == k){
                ans = mid;
                r = mid - 1;   // move LEFT
            }

            else if(arr[mid] < k){
                l = mid + 1;
            }

            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};
⚠️ Common Mistakes

❌ Wrong:

l = mid - 1;

✅ Correct:

r = mid - 1;

❌ Unsafe:

int mid = (l + r) / 2;

✅ Safe:

int mid = l + (r - l) / 2;
🧠 Memory Tricks

Normal Binary Search

arr[mid] < k → l = mid + 1
arr[mid] > k → r = mid - 1

First Occurrence

arr[mid] == k → store index → r = mid - 1
📈 Summary
Problem	Key Idea	Time
Binary Search	Return when found	O(log n)
First Occurrence	Store index & move LEFT	O(log n)
