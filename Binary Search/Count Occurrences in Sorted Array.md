# 🔎 Count Occurrences in Sorted Array  
**Binary Search | Lower Bound & Upper Bound | Striver A2Z Sheet**

---

# 📌 Problem Statement

Given a **sorted array** `nums` of integers and a target value `x`,  
find the **total number of occurrences** of `x` in the array.

If the element is not present, return:

    0

---

# 🧾 Example

### Example 1

Input:  
nums = [1,1,1,2,2,3,3]  
x = 3  

Output:  
2  

Explanation:  
The number **3** appears **2 times** in the array.

---

### Example 2

Input:  
nums = [2,4,4,4,6,8]  
x = 4  

Output:  
3  

---

# 🧠 Intuition (Striver Style)

Instead of counting elements one by one (O(n)),  
we use **Binary Search**.

Steps:

1. Find **Lower Bound** → First index **≥ target**
2. Find **Upper Bound** → First index **> target**
3. Calculate:

    count = upperBound - lowerBound

---

# 📌 Key Concepts

## 🔹 Lower Bound

Returns:

    First index ≥ target

Example:

arr = [1,2,4,4,5]  
target = 4  

Lower Bound → 2  

---

## 🔹 Upper Bound

Returns:

    First index > target

Example:

arr = [1,2,4,4,5]  
target = 4  

Upper Bound → 4  

---

# 🧠 Core Formula

    count = upperBound - lowerBound

This works because:

- Lower Bound → First occurrence
- Upper Bound → Position after last occurrence

---

# 🚀 Approach — Binary Search (Optimal)

## ⏱ Time Complexity

    O(log n)

## 📦 Space Complexity

    O(1)

---

# 💻 LeetCode Style Code

    class Solution {
    public:

        // Lower Bound → First index >= target
        int lowerBound(vector<int>& arr, int target) {

            int low = 0;
            int high = arr.size() - 1;
            int ans = arr.size();

            while(low <= high) {

                int mid = (low + high) / 2;

                if(arr[mid] >= target) {
                    ans = mid;
                    high = mid - 1;
                }

                else {
                    low = mid + 1;
                }
            }

            return ans;
        }


        // Upper Bound → First index > target
        int upperBound(vector<int>& arr, int target) {

            int low = 0;
            int high = arr.size() - 1;
            int ans = arr.size();

            while(low <= high) {

                int mid = (low + high) / 2;

                if(arr[mid] > target) {
                    ans = mid;
                    high = mid - 1;
                }

                else {
                    low = mid + 1;
                }
            }

            return ans;
        }


        // Main Function → Count Occurrences
        int countOccurrences(vector<int>& nums, int target) {

            int lb = lowerBound(nums, target);
            int ub = upperBound(nums, target);

            // If element not present
            if(lb == nums.size() || nums[lb] != target)
                return 0;

            return ub - lb;
        }
    };

---

# 🔎 Dry Run Example

nums = [1,1,1,2,2,3,3]  
target = 3  

Step 1:

    lowerBound → 5

Step 2:

    upperBound → 7

Step 3:

    count = 7 - 5
           = 2

Correct Output ✅

---

# 🧪 Edge Cases

Always test:

nums = [] , target = 5  

nums = [1] , target = 1  

nums = [1,1,1,1] , target = 1  

nums = [2,4,6,8] , target = 10  

nums = [5,7,7,8,8,10] , target = 8  

---

# ⭐ Why This Approach is Best

✔ Very Fast  
✔ Uses Binary Search  
✔ Works in O(log n)  
✔ Reusable in many problems  

---

# 📚 Learning Outcome

This problem teaches:

- Binary Search Variants  
- Lower Bound  
- Upper Bound  
- Counting Frequency  
- Efficient Searching  

