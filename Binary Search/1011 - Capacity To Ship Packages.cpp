class Solution {
public:
    int findweights(vector<int>&weights,int cap){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                day++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
           //maximum element
           int low=*max_element(weights.begin(),weights.end());
           //sum of all the elements
           int high=accumulate(weights.begin(),weights.end(),0);
           while(low<=high){
            int mid=low+(high-low)/2;
            int requireddays=findweights(weights,mid);
            if(requireddays<=days){
                  high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};