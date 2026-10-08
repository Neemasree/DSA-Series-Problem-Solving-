#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {
        int n = arr.size();
        if(n == 0) return;
        d %= n;
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};