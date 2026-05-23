class Solution {
public:
    
        bool isoperator(string s){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                return true;
            }
        return false;
        }
    
        int operate(string op,int a,int b){
            if(op=="+") return a+b;
            if(op=="-") return a-b;
            if(op=="*") return a*b;
            if(op=="/") return a/b;
            }
        int evalRPN(vector<string>& tokens){
            stack<int> st;
            for(int i=0;i<tokens.size();i++){
                if(!isoperator(tokens[i])){
                    st.push(stoi(tokens[i]));
                }
                else{
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    int x=operate(tokens[i],b,a);
                    st.push(x);
                }
            }
            return st.top();
            
        }
};
