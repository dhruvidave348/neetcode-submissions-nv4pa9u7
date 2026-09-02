class Solution {
public:
    vector<string> result;
    string subset;

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return result;
    }

    void backtrack(int open, int close, int n) {

        
        if (open == n && close == n) {
            result.push_back(subset);
            return;
        }

       
        if (open < n) {
            subset.push_back('(');
            backtrack(open + 1, close, n);
            subset.pop_back();
        }

       
        if (close < open) {
            subset.push_back(')');
            backtrack(open, close + 1, n);
            subset.pop_back();
        }
    }
};