class Solution {
public:
    vector<int>nextgreater(vector<int>&nums){
         int n=nums.size();
         stack<int>st;
         vector<int>nge(n);
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }else{
                nge[i]=st.top();
            }
            st.push(i);
         }
         return nge;
    }
     vector<int>previousgreater(vector<int>&nums){
         int n=nums.size();
         stack<int>st;
         vector<int>pge(n);
         for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }else{
                pge[i]=st.top();
            }
            st.push(i);
         }
         return pge;
    }
      vector<int>nextsmaller(vector<int>&nums){
         int n=nums.size();
         stack<int>st;
         vector<int>nse(n);
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
         }
         return nse;
    }
      vector<int>previoussmaller(vector<int>&nums){
         int n=nums.size();
         stack<int>st;
         vector<int>pse(n);
         for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
         }
         return pse;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        vector<int>nge=nextgreater(nums);
        vector<int>pge=previousgreater(nums);
        vector<int>nse=nextsmaller(nums);
        vector<int>pse=previoussmaller(nums);
        for(int i=0;i<n;i++){
            int left1=i-pge[i];
            int right1=nge[i]-i;
            int left2=i-pse[i];
            int right2=nse[i]-i;
            long long maxi=1LL*nums[i]*left1*right1;
            long long mini=1LL*nums[i]*left2*right2;
            sum+=maxi-mini;
        }
        return sum;
    }
};