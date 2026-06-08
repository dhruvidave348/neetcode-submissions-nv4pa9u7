class Solution {
public:
    string minWindow(string s, string t) {
        /*ok understanding the ques first what its asking is that we have a string s
        and a substring t so we have to find the smallest substring that contains all
        the characters from t, there can be multiple sub strings but we have to get the 
        smallest one and return that and if it doesnt contain the subtring we return ""
        APPROACH:1)find freq map for the count of the substring t
                 2)find freq map for current window in s
                 3)expand to the right to find valid window
                 4)move left to find minimum window
                 so we need a NEED and CURRENT WINDOW table*/


        unordered_map<char,int> need;
        unordered_map<char,int> window;
        
        int l=0;
        int len=INT_MAX;
        int ans=0;
        int valid=0;
        for(int i=0;i<t.size();i++){
            need[t[i]]++;
        }
        int total=need.size();
        
        
        for(int r=0;r<s.size();r++){
            window[s[r]]++;
            if(need.count(s[r]) && window[s[r]]==need[s[r]]){
                    valid++;
            
            while(valid==total){
                if(r-l+1<len){
                    len=r-l+1;
                    ans=l;
                }
                
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]]<need[s[l]]){
                    valid--;
                }
                l++;
                
                    
                        
                    
                }
            }
        }
        return len==INT_MAX?"":s.substr(ans,len);
        
    }
};
