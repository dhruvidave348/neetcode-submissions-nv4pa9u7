class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*the window size is fixed so u find max of window and return a list 
        with all these maximum elements and keep moving thr window use deque*/

        deque<int> dq;
        vector<int> ans;

        int l=0;
        int r=nums.size();
        for(int r=0;r<nums.size();r++){
            
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
                
            }
            dq.push_back(r);
            if(dq.front()<l){
                dq.pop_front();
            }
           
            if(r>=k-1){
                ans.push_back(nums[dq.front()]);
                l++;
            }



        }
        return ans;

        
    }
};
