<p align="center"> <b>📂 Topic:</b> Binary Search <br> <b>📘 Platform:</b> GeeksforGeeks (GFG) <br> <b>🚀 Difficulty:</b> Easy </p>
📌 Problem 1 — Binary Search (Normal Search)
🧾 Problem Statement

Given a sorted array arr[] and an integer k, return the index of k if present.
If the element is not found, return -1.

🔹 Example
Input:
arr = [1, 3, 5, 7, 9]
k = 7

Output:
3
💻 Implementation (C++)
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
⏱ Time Complexity	O(log n)
💾 Space Complexity	O(1)
