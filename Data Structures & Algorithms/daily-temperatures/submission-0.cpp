class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*first we wanna store the index into a stack so we gotta define it*/
        stack<int> st;
        vector<int> result(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int x=i-st.top();
                result[st.top()]=x;
                st.pop();
                
            }
            st.push(i);
        }
        return result;
    
    }
};
