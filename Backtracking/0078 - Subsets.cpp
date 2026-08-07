class Solution {
public:
    void findSubsets(int index,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(index==arr.size()){
        //empty[]
        ans.push_back(ds);
            return;
        }
       ds.push_back(arr[index]);
       //take
       findSubsets(index+1,arr,ans,ds);
       //backtrack
       ds.pop_back();
       //do not take
       findSubsets(index+1,arr,ans,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        findSubsets(0,nums,ans,ds);
        return ans;
    }
};