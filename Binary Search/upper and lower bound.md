# 🔍 Binary Search — Lower Bound & Upper Bound (LeetCode Style)

## 📌 Definitions

### 🔹 Lower Bound
The **first index** where  
```
nums[index] >= target
```

### 🔹 Upper Bound
The **first index** where  
```
nums[index] > target
```

If no such index exists, return **n (size of array)**.

---

# 🔹 Lower Bound

## 🧠 Idea

Find the **first position** where element is  
**greater than or equal to target**.

Even if target is not present,  
we return the position where it **can be inserted**.

---

## 💻 C++ Code — Lower Bound

```cpp
class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## 📊 Example — Lower Bound

**Input**

```
nums = [1,2,2,3,4]
target = 2
```

**Output**

```
1
```

First index where `>= 2`.

---

# 🔹 Upper Bound

## 🧠 Idea

Find the **first position** where element is  
**strictly greater than target**.

Used to find:
- Last occurrence
- Count of occurrences

---

## 💻 C++ Code — Upper Bound

```cpp
class Solution {
public:
    int upperBound(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## 📊 Example — Upper Bound

**Input**

```
nums = [1,2,2,3,4]
target = 2
```

**Output**

```
3
```

First index where `> 2`.

---

# 🎯 Key Differences

| Feature | Lower Bound | Upper Bound |
|--------|--------------|--------------|
| Condition | `>= target` | `> target` |
| Purpose | First position of target | Position after last target |
| Movement | Move LEFT when `>=` | Move LEFT when `>` |

---

# 🧩 Striver Pattern Tip

```
Lower Bound  → >= target
Upper Bound  → > target
```

---

# ⏱️ Complexity

| Type | Complexity |
|------|------------|
| Time | **O(log n)** |
| Space | **O(1)** |

---

# 🔥 Bonus: Count Occurrences Using Bounds

```
count = upperBound - lowerBound
```

Works in **O(log n)** time.
