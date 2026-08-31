class Solution {
public:
    vector<int> subset;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return result;

        
    }
    void backtrack(vector<int>& candidates,int target,int start){
        if(target==0){
            result.push_back(subset);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }

            subset.push_back(candidates[i]);

            backtrack(candidates,target-candidates[i],i+1);

            subset.pop_back();
        }
        
    }
    
};
