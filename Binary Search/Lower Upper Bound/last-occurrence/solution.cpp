#include <bits/stdc++.h>
using namespace std;
int lastOccurrence(vector<int>& nums,int target){int l=0,r=nums.size()-1,ans=-1;while(l<=r){int m=l+(r-l)/2;if(nums[m]<=target){if(nums[m]==target)ans=m;l=m+1;}else r=m-1;}return ans;}