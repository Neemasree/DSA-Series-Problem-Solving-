class Solution {
public:
    long long func(vector<int>&piles,int hourly){
           long long totalhours=0;
           for(int i=0;i<piles.size();i++){
            totalhours+=ceil((double)piles[i]/hourly);
           }
        return totalhours;   
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long requiredtime=func(piles,mid);
            if(requiredtime<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};