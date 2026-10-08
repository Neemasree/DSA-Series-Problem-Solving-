#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < (int)nums.size(); ++i)
            if(nums[i] != 0) swap(nums[i], nums[j++]);
    }
};