class Solution {
public:
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
        for(string& token: tokens){
            
            if(token=="-"||token=="+"||token=="*"||token=="/"){
                int a=st.top();st.pop();
                int b=st.top();st.pop();  
                if      (token == "+") st.push(a + b);
                else if (token == "-") st.push(b - a);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(b / a);
            }
            else{
                st.push(stoi(token));
            }

        }
        return st.top();
    }
};
