class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        //ignore spaces
        while(i<n && s[i]==' '){
            i++;
        }
        //check sign
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')sign=-1;
            i++;
        } 
        //skip leading zeros
        long long num=0;
        while(i<n && isdigit(s[i])){
           int digit=s[i]-'0';
           num=num*10+digit;
           if(sign*num >INT_MAX){
             return INT_MAX;
           }
           if(sign*num <INT_MIN){
            return INT_MIN;
           }
           i++;
        }
        return sign*num;
    }
};