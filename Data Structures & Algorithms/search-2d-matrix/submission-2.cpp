class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); /*num of rows*/
        int n=matrix[0].size(); /*num of columns*/
        
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]<=target && target<=matrix[i][n-1]){
                int left=0,right=n-1;
                while(left<=right){
                        int mid=left+(right-left)/2;
                        if(target==matrix[i][mid]){
                            return true;
                        }
                        else if(target<matrix[i][mid]){
                            right=mid-1;
                        }
                        else{
                            left=mid+1;
                        }

            }
            }
            
        }
        return false;
        }
    
};
