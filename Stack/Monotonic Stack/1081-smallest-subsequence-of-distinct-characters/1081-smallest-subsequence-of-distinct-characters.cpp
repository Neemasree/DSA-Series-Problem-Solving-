class Solution {
public:
    string smallestSubsequence(string s) {
       int n=s.size();
       stack<char>st;
       vector<int>freq(26,0);
       vector<bool>used(26,false);
       string ans="";
       for(char ch:s){
          freq[ch-'a']++;
       }
       for(char ch:s){
          freq[ch-'a']--;
          if(used[ch-'a']){
            continue;
          }
          while(!st.empty() && st.top()>ch && freq[st.top()-'a']>0){
            used[st.top()-'a']=false;
            st.pop();
          }
            used[ch-'a']=true;
            st.push(ch);
       }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};