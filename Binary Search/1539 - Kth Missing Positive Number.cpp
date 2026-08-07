class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st(arr.begin(),arr.end());
        int cnt=0;
        //positive integers start from 1
        int num=1;
        while(true){
            if(st.find(num)==st.end()){
                cnt++;
                if(cnt==k)return num;
            }
            num++;
        }
    }
};