class Solution {
public:

    bool isValid(int i, int j, vector<vector<char>>&board){

        for(int row=0;row<9;row++){
            if(row!=i && board[row][j]==board[i][j]) return false;
        }

        for(int col=0;col<9;col++){
            if(col!=j && board[i][col]==board[i][j]) return false;
        }

        for(int block=0;block<9;block++){
            if((i/3)*3 + block/3 != i && (j/3)*3 + block%3 !=j && board[(i/3)*3 + block/3][(j/3)*3 + block%3] == board[i][j]) return false;
        }

        return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(i,j, board)){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};