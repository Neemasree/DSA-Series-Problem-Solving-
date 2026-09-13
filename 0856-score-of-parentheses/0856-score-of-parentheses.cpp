class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }
            else{
                //curr stack top will be 0
                int inside=st.top();
                //if match found we wil pop
                st.pop();
                int score=0;
                if(inside==0){
                    score=1;
                }else{
                    score=2*inside;
                }
                st.top()+=score;
            }
        }
     return st.top();
    }
};