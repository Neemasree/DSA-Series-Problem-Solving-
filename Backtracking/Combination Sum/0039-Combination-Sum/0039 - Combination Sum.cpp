class Solution {
public:
    void findCombination(int index,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        //base condition
        if(index==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick element
        if(arr[index]<=target){
            //if found push into ds
            ds.push_back(arr[index]);
            findCombination(index,target-arr[index],arr,ans,ds);
            //backtrack and go back before that delete the value
            ds.pop_back();
        }
        //do not pic element
        findCombination(index+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};