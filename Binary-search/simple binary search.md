📌 Problem Statement

Given a sorted array, search for a target element k.

Return:

The index of k if present
Otherwise return:
-1
🧠 Example
Input
arr = [1,3,5,7,9]
k = 7
Output
3
Explanation

The element 7 is present at index 3.

🛠 Binary Search Approach
Idea

Since the array is sorted, we:

Find the middle element
Compare it with k
Move left or right accordingly

This reduces search space by half each time.

🎬 Dry Run Animation
Initial Array
arr = [1,3,5,7,9]
k = 7
Step 1
low = 0
high = 4

            mid
             ↓
[1] [3] [5] [7] [9]
 0   1   2   3   4

arr[mid] = 5

Since:

5 < 7

Move RIGHT →

low = mid + 1 = 3
Step 2
low = 3
high = 4

                mid
                 ↓
[1] [3] [5] [7] [9]
 0   1   2   3   4

arr[mid] = 7

🎯 Found!

Return index = 3
💻 C++ Implementation
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int k) {

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] == k){
            return mid;
        }

        else if(arr[mid] < k){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    return -1;
}
⏱ Complexity
Type	Complexity
Time Complexity	O(log N)
Space Complexity	O(1)
💡 Key Concepts
Divide and conquer
Mid calculation
Sorted array requirement
Reducing search space
