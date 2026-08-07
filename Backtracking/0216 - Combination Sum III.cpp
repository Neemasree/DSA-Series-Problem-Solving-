class Solution {
public:
    void findcombinations(int k,int target,int index,vector<vector<int>>&ans,vector<int>&ds){
         if(ds.size()==k){
            if(target==0){
                ans.push_back(ds);
            }
            return;
         }
         for(int i=index;i<=9;i++){
            ds.push_back(i);
            findcombinations(k,target-i,i+1,ans,ds);
            ds.pop_back();
         }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombinations(k,n,1,ans,ds);
        return ans;
    }
};