class Solution {
private:
    bool isValid(const vector<vector<char>>& board, int row, int col, char n){

        for (int i = 0; i < 9; ++i) {
            if(board[row][i] == n) return false; 
            if(board[i][col] == n) return false; 
        }
        
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        
        for (int i = startRow; i < startRow + 3; ++i)
            for (int j = startCol; j < startCol + 3; ++j)
                if(board[i][j] == n)
                    return false;
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[i][j] == '.'){
                    for (int n = 1; n <= 9; ++n) {
                        char num = n + '0';
                        if(isValid(board, i, j, num)){
                            board[i][j] = num;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false; //this path is wrong if no num works
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
