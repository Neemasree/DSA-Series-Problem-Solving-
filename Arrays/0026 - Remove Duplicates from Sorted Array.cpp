class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointer
        int slow=0;
        for(int fast=1;fast<nums.size();fast++){
            if(nums[fast]!=nums[slow]){
                //update and track
                 slow++;
                 nums[slow]=nums[fast];
            }
        }
        return slow+1;
    }
};