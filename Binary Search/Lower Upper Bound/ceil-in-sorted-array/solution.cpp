#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int x) {
    int l = 0, r = arr.size()-1, ans = -1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] >= x) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}