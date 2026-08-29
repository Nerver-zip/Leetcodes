class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int ROWS = mat.size(), COLS = mat[0].size();
        vector<int> result;
        int i = 0, j = 0;
        bool up = true; // initial direction: moving up

        while(i != ROWS-1 || j != COLS-1) {
            result.push_back(mat[i][j]);

            if(up) { // moving up-right
                if(j == COLS - 1) { // reached the last column
                    i++;        // move down
                    up = false; // change direction
                } else if(i == 0) { // reached the first row
                    j++;        // move right
                    up = false; // change direction
                } else { // move diagonally up-right
                    i--;
                    j++;
                }
            } else { // moving down-left
                if(i == ROWS - 1) { // reached the last row
                    j++;        // move right
                    up = true;  // change direction
                } else if(j == 0) { // reached the first column
                    i++;        // move down
                    up = true;  // change direction
                } else { // move diagonally down-left
                    i++;
                    j--;
                }
            }
        }

        result.push_back(mat[ROWS-1][COLS-1]);

        return result;
    }
};