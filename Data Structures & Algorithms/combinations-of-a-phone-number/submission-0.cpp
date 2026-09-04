class Solution {
public: 
    vector<char> current;
    vector<string> result;

    unordered_map<char,string> phone={
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        backtrack(0,digits);
        return result;

        
    }
    void backtrack(int index,string& digits){
        if(index==digits.size()){
            result.push_back(string(current.begin(),current.end()));
            return;

        } 
        for(char letter:phone[digits[index]]){
            current.push_back(letter);
            backtrack(index+1,digits);
            current.pop_back();

        }

        

    }

};
