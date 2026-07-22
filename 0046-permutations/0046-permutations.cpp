class Solution {
public:
    void combinations(vector<int>&freq,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ds.size()==arr.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(!freq[i]){
                ds.push_back(arr[i]);
                freq[i]=1;
                combinations(freq,arr,ans,ds);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        combinations(freq,nums,ans,ds);
        return ans;
    }
};