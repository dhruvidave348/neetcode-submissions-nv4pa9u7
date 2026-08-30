class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0,nums,target);
        return result;
    }
    void backtrack(int i,vector<int>& nums,int target){
        if(target==0){
            result.push_back(subset);
            return;
        }
        if(i==nums.size()||target<0){
            return;
        }
        subset.push_back(nums[i]);
        backtrack(i,nums,target-nums[i]);

        subset.pop_back();
        backtrack(i+1,nums,target);
    }
};
