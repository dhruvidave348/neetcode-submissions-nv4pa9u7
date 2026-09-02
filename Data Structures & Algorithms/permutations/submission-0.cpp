class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return result;      
    }
    void backtrack(vector<int>& nums){
        if(subset.size()==nums.size()){
            result.push_back(subset);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;

            used[i]=true;
            subset.push_back(nums[i]);
        

            backtrack(nums);

            subset.pop_back();
            used[i]=false;
            }
        
    }
};
