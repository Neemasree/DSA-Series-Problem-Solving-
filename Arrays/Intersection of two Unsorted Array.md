# 🚀 Intersection of Two Arrays (Unsorted Arrays)

## 📌 Problem

Given two integer arrays `nums1` and `nums2`, return an array of their **intersection**.

Each element in the result must be **unique**, and you may return the result **in any order**.

🔗 LeetCode Problem: **349. Intersection of Two Arrays**

---

# 🧠 Example

### Example 1

Input

```
nums1 = [1,2,2,1]
nums2 = [2,2]
```

Output

```
[2]
```

---

### Example 2

Input

```
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
```

Output

```
[9,4]
```

Explanation
`[4,9]` is also a valid answer.

---

# ❗ Important Points

* Arrays are **not sorted**
* Result must contain **unique elements only**
* Order of output **does not matter**

---

# 🛠 Approach 1 — Brute Force

## Idea

Compare every element of `nums1` with every element of `nums2`.

If a match is found:

* Insert it into the result
* Ensure duplicates are not inserted again.

---

## C++ Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){

                if(nums1[i] == nums2[j]){

                    if(ans.empty() || ans.back() != nums1[i])
                        ans.push_back(nums1[i]);

                    break;
                }
            }
        }

        return ans;
    }
};
```

---

## Complexity

| Type             | Complexity                  |
| ---------------- | --------------------------- |
| Time Complexity  | **O(n × m)**                |
| Space Complexity | **O(1)** (excluding output) |

---

# 🚀 Approach 2 — Optimal (Using Hash Set)

## Idea

Use a **set** to store elements of the first array.

Then traverse the second array:

* If the element exists in the set
* Add it to the answer
* Remove it from the set to avoid duplicates.

---

## C++ Code

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int x : nums2){
            if(s.count(x)){
                ans.push_back(x);
                s.erase(x);
            }
        }

        return ans;
    }
};
```

---

# ⏱ Complexity

| Type             | Complexity   |
| ---------------- | ------------ |
| Time Complexity  | **O(n + m)** |
| Space Complexity | **O(n)**     |

Where

```
n = size of nums1
m = size of nums2
```

---

# 📊 Approach Comparison

| Approach           | Time         | Space |
| ------------------ | ------------ | ----- |
| Brute Force        | O(n × m)     | O(1)  |
| Hash Set (Optimal) | **O(n + m)** | O(n)  |

---

# 💡 Key Concepts

* Hash Set
* Duplicate removal
* Array traversal

---

⭐ If this helped you understand the problem, consider starring the repository!
