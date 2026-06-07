class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0;
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;
        for(int i=0;i<s1.size();i++){
            f1[s1[i]]++;
            f2[s2[i]]++;
        }
        if(f1==f2) return true;
        for(int r=s1.size();r<s2.size();r++){
            f2[s2[r]]++;
            f2[s2[l]]--;
            if(f2[s2[l]]==0) f2.erase(s2[l]);
            if(f1==f2){
                return true;
            }
            l++;

        }
        return false;
    
        
    }
};
