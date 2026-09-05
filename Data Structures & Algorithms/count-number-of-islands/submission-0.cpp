class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;

                    dfs(i,j,grid);
                }
            }
        }
        return count;
        
    }

    void dfs(int row,int column,vector<vector<char>>& grid){
        stack<pair<int,int>> st;
        st.push({row,column});

        while(!st.empty()){
            auto[r,c]=st.top();
            st.pop();

            if(grid[r][c]=='0') continue;

            grid[r][c]='0';

            if(r>0 && grid[r-1][c]=='1') st.push({r-1,c});
            if(r<grid.size()-1 && grid[r+1][c]=='1') st.push({r+1,c});

            if(c>0 && grid[r][c-1]=='1') st.push({r,c-1});
            if(c<grid[0].size()-1 && grid[r][c+1]=='1') st.push({r,c+1});

        }


    }
};
