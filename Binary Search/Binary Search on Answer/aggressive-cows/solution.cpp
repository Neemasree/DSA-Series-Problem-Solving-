class Solution {
  public:
    bool canweplace(vector<int>&arr,int cows,int dist){
        int n=arr.size();
        int cntcows=1;
        int last=arr[0];
        for(int i=1;i<=n-1;i++){
            if(arr[i]-last>=dist){
                cntcows++;
                last=arr[i];
            }
        }
        return cntcows>=cows;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low=1;
        int high=arr[n-1]-arr[0];
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canweplace(arr,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};