class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=high+(low-high)/2;
            //check if left is sorted
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){
                //check if target is btw that range
                if(target>=nums[low] && target<=nums[mid]){
                    //already mid is checked and we didnt find itt
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};