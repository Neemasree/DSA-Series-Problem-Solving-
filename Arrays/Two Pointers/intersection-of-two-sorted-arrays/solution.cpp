#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> ans;
    while(i < (int)a.size() && j < (int)b.size()) {
        if(a[i] == b[j]) {
            ans.push_back(a[i]);
            ++i; ++j;
        } else if(a[i] < b[j]) ++i;
        else ++j;
    }
    return ans;
}