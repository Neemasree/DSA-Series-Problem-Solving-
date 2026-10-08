class Solution {
public:
    bool ispossible(vector<int>&nums,int split,int k){
      int n=nums.size();
      int sum=0;
      int part=1;
      for(int i=0;i<n;i++){
        if(sum+nums[i]<=split){
            sum+=nums[i];
        }else{
            part++;
            sum=nums[i];
        }
      }
      return part<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};