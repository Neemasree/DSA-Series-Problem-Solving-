class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int leftsum=0;
            //till i-1 element(left calculation)
            for(int j=0;j<i;j++){
                leftsum+=nums[j];
            }
            int rightsum=0;
            //i+1 to end right sum
            for(int k=i+1;k<n;k++){
                rightsum+=nums[k];
            }
            if(leftsum==rightsum){
                return i;
            }
        }
        return -1;
    }
};