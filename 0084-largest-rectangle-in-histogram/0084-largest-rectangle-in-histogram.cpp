class Solution {
public:
    //nxt smaller element
    vector<int>findnse(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    //preveious smaller element
    vector<int>findpse(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
               st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        vector<int>nse=findnse(heights);
        vector<int>pse=findpse(heights);
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int area=heights[i]*width;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};