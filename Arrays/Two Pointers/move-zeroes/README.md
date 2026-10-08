# 🚀 Move Zeroes to End

## 📌 Problem Statement

Given an integer array `nums`, move all `0`s to the **end of the array** while maintaining the **relative order of the non-zero elements**.

You must perform the operation **in-place** if possible.

---

## 🧠 Example

### Input

```
nums = [1,0,2,3,0,4,0,1]
```

### Output

```
[1,2,3,4,1,0,0,0]
```

### Explanation

All non-zero elements keep their **original order**, and all `0`s are pushed to the **end of the array**.

---

# 🛠 Approaches

---

# 1️⃣ Brute Force Approach

### Idea

1. Create a **temporary array**.
2. Store all **non-zero elements** in the temporary array.
3. Copy them back to the original array.
4. Fill the remaining positions with `0`.

### Complexity

```
Time Complexity  : O(N)
Space Complexity : O(N)
```

### C++ Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }

        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
        }

        for(int i = temp.size(); i < n; i++){
            nums[i] = 0;
        }
    }
};
```

---

# 2️⃣ Better Approach (Shift Non-Zeros)

### Idea

Instead of using an extra array:

* Move all **non-zero elements to the front**
* Then fill the rest of the array with `0`.

### Complexity

```
Time Complexity  : O(N)
Space Complexity : O(1)
```

### C++ Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int index = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[index] = nums[i];
                index++;
            }
        }

        for(int i = index; i < n; i++){
            nums[i] = 0;
        }
    }
};
```

---

# 3️⃣ Optimal Approach (Two Pointer Technique)

### Idea

Use **two pointers**:

* `j` → position of the first zero
* `i` → scans the array for non-zero elements

Whenever a **non-zero element appears after a zero**, swap them.

### Complexity

```
Time Complexity  : O(N)
Space Complexity : O(1)
```

### C++ Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int j = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i = j + 1; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

---

# 📊 Approach Comparison

| Approach    | Time | Space | Notes                    |
| ----------- | ---- | ----- | ------------------------ |
| Brute Force | O(N) | O(N)  | Uses extra array         |
| Better      | O(N) | O(1)  | Shifts non-zero elements |
| Optimal     | O(N) | O(1)  | Two pointer technique    |

---

# 💡 Key Learning

* Understand how **two pointers help optimize array problems**
* Maintain **relative order of elements**
* Learn **in-place array manipulation**

---

⭐ If you found this helpful, consider starring the repository!
