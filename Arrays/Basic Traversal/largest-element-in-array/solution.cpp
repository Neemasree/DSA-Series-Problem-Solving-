#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& arr) {
        return *max_element(arr.begin(), arr.end());
    }
};