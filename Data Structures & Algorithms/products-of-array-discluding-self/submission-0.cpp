class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> s(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            s[i]=s[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
            s[i]=s[i]*right;
            right=right*nums[i];
        }
        return s;
    }
};
