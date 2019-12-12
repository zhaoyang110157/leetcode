class Solution {
public:
    vector<vector<char>>& res;
    bool show[3][9][9];
    bool isValid(int i,int j,int tmp) {
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
        return true;
    }
    bool enter(int i,int j){
        if(res[i][j] != '.'){
            if(j == 8){
                if(i == 8) return isValid(8,8,res[i][j]-'1');
                return enter(i+1,0);
            }else{
                return enter(i,j+1);
            }
        }else{
            for(int k = 0; k < 9; k++){
                res[i][j] = '1' + k;
                if(isValid(i,j,k)){
                    if(j == 8){
                        if(i == 8) if(enter(8,8)) return true;
                        if(enter(i+1,0)) return true;
                    }else{
                        if (enter(i,j+1)) return true;
                    }
                }
            } 
            return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<3;++i){
            for(int j = 0; j<9;j++){
                for(int k = 0; k < 9; k++){
                    show[i][j][k] = false;
                }
            }
        }
        res = board;
        enter(0,0);
        board = res;
    }
};