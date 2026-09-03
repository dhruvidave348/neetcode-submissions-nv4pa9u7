class Solution {
public:
    vector<string> subset;
    vector<vector<string>> result;
    
    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return result;
        
    }

    void backtrack(int start,string& s){
        
            if(start==s.size()){
                result.push_back(subset);
                return;
            }
            for(int i=start;i<s.size();i++){
                if(isPalindrome(s,start,i)){
                    subset.push_back(s.substr(start,i-start+1));

                    backtrack(i+1,s);
                    subset.pop_back();
                }

        }
    }
    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }


    
};
