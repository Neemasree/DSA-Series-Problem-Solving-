class Solution {
public:
    int findsum(vector<int>&nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=*max_element(nums.begin(),nums.end());
        //divisor
        int low=1;
        int high=maxi;
        int ans=-1;
        while(low<=high){
          int mid=low+(high-low)/2;
           if(findsum(nums,mid)<=threshold){
              ans=mid;
              high=mid-1;
           }else{
            low=mid+1;
           }
        }
        return low;
    }
};