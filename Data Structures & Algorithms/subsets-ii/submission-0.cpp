class Solution {
public:
    vector<int> subset;
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums);
       
        return result;

        
    }

    void backtrack(int start,vector<int>& nums){
        result.push_back(subset);
        for (int i = start; i < nums.size(); i++) {

           
            if (i > start && nums[i] == nums[i - 1])
                continue;

           
            subset.push_back(nums[i]);

        
            backtrack(i + 1, nums);

            
            subset.pop_back();
        
    }
    }
};
