class Solution {
public:
    int characterReplacement(string s, int k) {
        /*ok so basically we can perform at most k operarions so we check for the condition 
        of a valid window length that is k>=window len- max freq */
        int l=0;
        int maxfreq=0;
        int ans=0;
        unordered_map<char,int> freq;
        
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            maxfreq=max(maxfreq,freq[s[r]]);
            if(k<(r-l+1-maxfreq)){
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            
        }
        return ans;

        
        
        
    }
};
