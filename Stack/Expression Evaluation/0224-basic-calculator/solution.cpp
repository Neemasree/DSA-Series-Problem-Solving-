class Solution {
public:
    int calculate(string s) {
        int res=0;
        long long num=0;
        int sign=1;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }else if(ch=='+'){
                res+=num*sign;
                num=0;
                sign=1;
            }else if(ch=='-'){
                res+=num*sign;
                num=0;
                sign=-1;
            }else if(ch=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }else if(ch==')'){
                res+=sign*num;
                num=0;
                res*=st.top();
                st.pop();
                res+=st.top();
                st.pop();
            }
        }
        res+=sign*num;
        return res;
    }
};