#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> ans;
    auto add = [&](int x) {
        if(ans.empty() || ans.back() != x) ans.push_back(x);
    };
    while(i < (int)a.size() && j < (int)b.size()) {
        if(a[i] <= b[j]) add(a[i++]);
        else add(b[j++]);
    }
    while(i < (int)a.size()) add(a[i++]);
    while(j < (int)b.size()) add(b[j++]);
    return ans;
}