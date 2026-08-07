class Solution {
public:
    void findsubsets(int index,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        //base case
        ans.push_back(ds);
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            findsubsets(i+1,arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findsubsets(0,nums,ans,ds);
        return ans;
    }
};