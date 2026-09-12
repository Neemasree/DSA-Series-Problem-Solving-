class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>list=tokens;
        while(list.size()>1){
            for(int i=0;i<list.size();i++){
            string t=list[i];
            if(t=="+" || t=="-" || t=="*" || t=="/"){
               int val=0;
               //stoi=converts string to int conversion
               int a=stoi(list[i-2]);
               int b=stoi(list[i-1]);
               if(t=="+"){
                val=a+b;
               }else if(t=="-"){
                val=a-b;
               }else if(t=="*"){
                val=a*b;
               }else{
                val=a/b;
            }
        list[i-2]=to_string(val);
        list.erase(list.begin()+i);
        list.erase(list.begin()+i-1);
        break;
        }
        }
        }
        return stoi(list[0]);
    }
};