class Solution {
public:
     vector<int>nse(vector<int>&arr){
        int n=arr.size();
         stack<int>st;
         vector<int>nse(n);
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
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
     vector<int>pse(vector<int>&arr){
         int n=arr.size();
         stack<int>st;
         vector<int>pse(n);
         for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
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
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>next=nse(arr);
        vector<int>prev=pse(arr);
        long long mod=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++){
           int left=i-prev[i];
           int right=next[i]-i;
           sum=(sum+(long long)arr[i]*left*right)%mod;
        }
    return sum;
    }
};