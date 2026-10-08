#include <bits/stdc++.h>
using namespace std;
class Solution{public:int missingNum(vector<int>& arr){int n=arr.size()+1,x=0;for(int i=1;i<=n;++i)x^=i;for(int v:arr)x^=v;return x;}};