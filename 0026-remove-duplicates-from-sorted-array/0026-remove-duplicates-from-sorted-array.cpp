class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int>s(nums.begin(),nums.end());
        int i=0;
        for(int x:s){
            nums[i]=x;
            i++;
        }
        return s.size();
    }
};