class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n)return false;
        vector<int>freq(26,0);
        vector<int>window(26,0);
        for(int i=0;i<m;i++){
            freq[s1[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            window[s2[i]-'a']++;
        }
        if(freq==window)return true;
        //sliding window
        for(int i=m;i<n;i++){
            window[s2[i-m]-'a']--;
            window[s2[i]-'a']++;
            if(freq==window)return true;
        }
        return false;
    }
};
