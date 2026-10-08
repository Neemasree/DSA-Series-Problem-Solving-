#include <bits/stdc++.h>
using namespace std;

int lowerBoundIndex(vector<int>& a, int x) {
    int l=0,r=a.size(),ans=a.size();
    while(l<r){ int m=l+(r-l)/2; if(a[m]>=x) ans=m,r=m; else l=m+1; }
    return ans;
}
int upperBoundIndex(vector<int>& a, int x) {
    int l=0,r=a.size(),ans=a.size();
    while(l<r){ int m=l+(r-l)/2; if(a[m]>x) ans=m,r=m; else l=m+1; }
    return ans;
}
int countOccurrences(vector<int>& nums, int target) {
    int lb=lowerBoundIndex(nums,target), ub=upperBoundIndex(nums,target);
    return (lb == (int)nums.size() || nums[lb] != target) ? 0 : ub-lb;
}