#include <bits/stdc++.h>
using namespace std;
long long largestPrimeFactor(long long n){long long ans=1;while(n%2==0){ans=2;n/=2;}for(long long p=3;p<=n/p;p+=2)while(n%p==0){ans=p;n/=p;}if(n>1)ans=n;return ans;}