class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();
        int minutes=0;
        int fresh=0;

        queue<pair<int,int>> q;

        for(int r=0;r<rows;r++){
            for(int c=0;c<columns;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
                else if(grid[r][c] == 1){
                    fresh++;
}
                

            }
        }
        
        
        
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;j++){
                
                auto[r,c]=q.front();
                q.pop();

                int dr[]={-1,1,0,0};
                int dc[]={0,0,-1,1};

                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                   
                    

                    if(nr>=0 && nr<rows && nc>=0 && nc<columns && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                        
                    }

                    
                    
            }
        }
        minutes++;
        }
        if(fresh>0) return -1;
        if(minutes>0) minutes--;

        return minutes;
        
        

        

        
    }
};
