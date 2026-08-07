class Solution {
public:
    bool possible(vector<int>&bloomday,int days,int m,int k){
        int cnt=0;
        int bouquet=0;
        for(int i=0;i<bloomday.size();i++){
            if(bloomday[i]<=days){
                cnt++;
            }else{
                bouquet+=(cnt/k);
                cnt=0;
            }
        }
        bouquet+=(cnt/k);
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        int n=bloomday.size();
        int mini=*min_element(bloomday.begin(),bloomday.end());
        int maxi=*max_element(bloomday.begin(),bloomday.end());
        if((long long)m*k>n)return -1;
        int low=mini;
        int high=maxi;
        while(low<=high){
          int mid=low+(high-low)/2;
          if(possible(bloomday,mid,m,k)){
            high=mid-1;
          }else{
            low=mid+1;
          }
        }   
        return low;   
    }
};