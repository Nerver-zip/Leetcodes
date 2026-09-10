class Solution {
private:
    int subCount(const vector<vector<int>>& matrix, int r, int c, int maxSize){
        int res = 0, s = 0;
        while (s < maxSize) {
            int row = r + s;
            int col = c + s;

            if (row >= matrix.size() || col >= matrix[0].size())
                return res;

            // checar a nova linha adicionada
            for (int j = c; j <= col; j++) {
                if (matrix[row][j] == 0)
                    return res;
            }

            // checar a nova coluna adicionada
            for (int i = r; i <= row; i++) {
                if (matrix[i][col] == 0)
                    return res;
            }
            ++res;
            ++s;
        }
        return res;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                ans += subCount(matrix, i, j, min(ROWS - i, COLS-j));
            }
        }

        return ans;
    }
};
