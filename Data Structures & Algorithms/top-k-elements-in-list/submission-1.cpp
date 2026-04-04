class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> bucket(n + 1);
        unordered_map<int,int>freq;
       
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
              
            
        }
        for(auto it:freq){
            int num=it.first;
            int f=it.second;
            bucket[f].push_back(num);
    } 
        vector<int> result;
        for(int i=n;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                result.push_back(bucket[i][j]);
                if(result.size()==k){
                    return result;
                }
            }
        }  
        return result;
        


    }
};
