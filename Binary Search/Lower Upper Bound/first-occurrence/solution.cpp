#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int target) {
    int l=0,r=arr.size()-1,ans=-1;
    while(l<=r){ int m=l+(r-l)/2; if(arr[m]>=target){ if(arr[m]==target) ans=m; r=m-1; } else l=m+1; }
    return ans;
}