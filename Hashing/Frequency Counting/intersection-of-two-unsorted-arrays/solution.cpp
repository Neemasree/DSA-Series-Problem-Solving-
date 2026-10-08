#include <bits/stdc++.h>
using namespace std;
class Solution{public:vector<int> intersection(vector<int>& a,vector<int>& b){unordered_set<int>s(a.begin(),a.end()),out;for(int x:b)if(s.count(x))out.insert(x);return vector<int>(out.begin(),out.end());}};