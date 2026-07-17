class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>ans;
       int n=s.size();
       int k=p.size();
       if(p.size()>s.size()){
        return ans;
       }
        vector<int>freq(26,0);
        vector<int>curr(26,0);
        //freq of p
        for(char c:p){
            freq[c-'a']++;
        }
        //first set of values
        for(int i=0;i<p.size();i++){
            curr[s[i]-'a']++;
        }
        if(freq==curr){
            ans.push_back(0);
        }
        //sliding window
        for(int i=p.size();i<n;i++){
            //remove first char
            curr[s[i-k]-'a']--;
            //add next new char
            curr[s[i]-'a']++;
            if(curr==freq){
            ans.push_back(i-k+1);
          }
        }
          return ans;
    }
};