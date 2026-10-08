class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int n=s.size();
        int m=t.size();
        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int startindex=0;
        int cnt=0;
        //stored freq of t value
        for(char c:t){
            hash[c]++;
        }
        while(r<n){
            //checl right element
            if(hash[s[r]]>0)
                cnt++;
                hash[s[r]]--;
                while(cnt==m){
                    if(r-l+1<minlen){
                        minlen=r-l+1;
                        startindex=l;
                    }
                    hash[s[l]]++;
                    if(hash[s[l]]>0){
                        cnt--;
                    }
                    l++;
                }
                r++;
            }
        if(minlen==INT_MAX){
            return "";
        }else{
            return s.substr(startindex,minlen);
        }
    }
};