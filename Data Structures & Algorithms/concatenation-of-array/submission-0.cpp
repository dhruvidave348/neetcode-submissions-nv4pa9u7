class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> c(2 * n);
        for(int i=0;i<n;i++){
            c[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            c[i+n]=nums[i];
        }
        return c;


    }
};