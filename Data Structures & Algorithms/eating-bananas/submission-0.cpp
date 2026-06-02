class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*to find min value of k, where k is the rate of eating bananas per hour*/
        /*cannot move on to the next pile if pile[i]<k in the same hour*/
        /*return min k such that u finish eating the pile < h */
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=ceil(double(piles[i])/mid);

            }
            if(hours<=h){
                result=mid;
                right=mid-1;
            }
            else{
                
                left=mid+1;
            }
        }
        return result;

        

        
    }
};
