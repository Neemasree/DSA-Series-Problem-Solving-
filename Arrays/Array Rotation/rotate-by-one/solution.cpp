#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void leftRotate(vector<int>& arr) {
        if(arr.empty()) return;
        int first = arr[0];
        for(int i = 1; i < (int)arr.size(); ++i) arr[i-1] = arr[i];
        arr.back() = first;
    }

    void rightRotate(vector<int>& arr) {
        if(arr.empty()) return;
        int last = arr.back();
        for(int i = (int)arr.size()-1; i > 0; --i) arr[i] = arr[i-1];
        arr[0] = last;
    }
};