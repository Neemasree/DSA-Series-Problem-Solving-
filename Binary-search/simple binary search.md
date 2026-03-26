📌 Problem Statement

Given a sorted array arr[] and an element k, return the index of k.

If not found:

Return -1
🧠 Key Idea

Binary Search repeatedly divides the array into halves.

Sorted Array Required ✅
💻 C++ Code
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {

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
};
🎬 Animated Dry Run
Array
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

low = mid + 1
low = 3
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
⏱️ Complexity
Time  : O(log N)
Space : O(1)
