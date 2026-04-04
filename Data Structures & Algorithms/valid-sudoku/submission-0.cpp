class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9),column(9),box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char num=board[i][j];
                int box_index=(i/3)*3+(j/3);
                if(rows[i].count(num)||column[j].count(num)||box[box_index].count(num)){
                    return false;
                }
                rows[i].insert(num);
                column[j].insert(num);
                box[box_index].insert(num);
            }
        }
        return true;
        
    }
};
