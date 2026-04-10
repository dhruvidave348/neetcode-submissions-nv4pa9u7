class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxwater=0;
        while(left<right){
            int h=min(heights[left],heights[right]);
            int width=right-left;
            maxwater=max(maxwater,width*h);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxwater;
    }
};
