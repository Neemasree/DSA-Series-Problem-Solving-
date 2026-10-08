#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n){vector<int>a;for(int i=1;i<=n/i;++i)if(n%i==0){a.push_back(i);if(i!=n/i)a.push_back(n/i);}sort(a.begin(),a.end());return a;}