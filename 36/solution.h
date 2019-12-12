class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool show[3][9][9];
        for(int i=0;i<3;++i){
            for(int j = 0; j<9;j++){
                for(int k = 0; k < 9; k++){
                    show[i][j][k] = false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                int tmp = board[i][j] - '1';
                if(show[0][i][tmp])
                    return false;
                else show[0][i][tmp] = true;
                if(show[1][j][tmp])
                    return false;
                else show[1][j][tmp] = true;
                int loc = i/3*3 + j/3;
                if(show[2][loc][tmp])
                    return false;
                else show[2][loc][tmp] = true;
            }
        }
        return true;
    }
};