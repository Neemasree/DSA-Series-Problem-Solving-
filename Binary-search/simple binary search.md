
📌 Problem Statement

Given a sorted array arr[] and an integer k, return the index of k if it exists in the array. Otherwise return -1.

If duplicates exist, returning any index is allowed.

🧠 Intuition

Binary Search works by:

Finding the middle element
Comparing with target
Eliminating half of the search space
Repeating until found

Works only on sorted arrays.

🐢 Approach — Brute Force (Linear Search)
💡 Idea

Check each element one by one.

💻 Code (C++)
class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == k) {
                return i;
            }
        }

        return -1;
    }
};
⚡ Approach — Optimal (Binary Search)
💡 Steps
Set l = 0
Set r = n-1
Find mid
Compare:
Equal → return mid
Smaller → move right
Larger → move left
💻 Code (C++)
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
🔍 Dry Run
arr = [1,3,5,7,9]
k = 7

Step 1:

l=0 r=4
mid=2 → 5

5 < 7 → move right
l=3

Step 2:

l=3 r=4
mid=3 → 7

FOUND → return 3
⏱️ Complexity
Type	Value
Time	O(log n)
Space	O(1)
