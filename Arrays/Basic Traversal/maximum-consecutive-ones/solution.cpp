#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for(int x : nums) {
            if(x == 1) ans = max(ans, ++cnt);
            else cnt = 0;
        }
        return ans;
    }
};