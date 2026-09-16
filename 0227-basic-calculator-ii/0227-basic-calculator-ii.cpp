class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int res=0;
        int num=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            if(!isdigit(ch) && ch!=' ' || i==s.size()-1){
                if(sign=='+'){
                    st.push(num);
                }else if(sign=='-'){
                    st.push(-num);
                }else if(sign=='*'){
                    int x=st.top();
                    st.pop();
                    st.push(x*num);
                }else if(sign=='/'){
                    int x=st.top();
                    st.pop();
                    st.push(x/num);
                }
                sign=ch;
                num=0;
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};