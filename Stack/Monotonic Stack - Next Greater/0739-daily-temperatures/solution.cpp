class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n=temperatures.size();
       stack<int>st;
       vector<int>ans(n,0);
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
            st.pop();
           }
           if(!st.empty()){
              ans[i]=st.top()-i;
       }
       st.push(i);
        }
       return ans;
    }
};

//brute force
//  int n=temperatures.size();
//         vector<int>ans(n,0);
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(temperatures[j]>temperatures[i]){
//                    ans[i]=j-i;
//                    break;
//                 }
//             }
//         }
//         return ans;