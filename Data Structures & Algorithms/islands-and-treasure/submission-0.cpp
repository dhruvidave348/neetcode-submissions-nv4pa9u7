class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();

        queue<pair<int,int>> q;
        

        for(int r=0;r<rows;r++){
            for(int c=0;c<columns;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};

            for (int i = 0; i < 4; i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<rows && nc>=0 && nc<columns && grid[nr][nc]==INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                    
            }
        }
            }


            

        
        
    }
};
