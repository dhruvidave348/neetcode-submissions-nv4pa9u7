class Solution {
public:
    vector<int> subset;
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return result;
        
    }
    void backtrack(int i,vector<int>& nums){
        if(i==nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i+1,nums);

        subset.pop_back();
        backtrack(i+1,nums);
    }
};
