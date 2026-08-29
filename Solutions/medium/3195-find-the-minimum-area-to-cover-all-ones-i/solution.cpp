class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        int maxR = 0, maxC = 0, minR = INT_MAX, minC = INT_MAX;

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j]){
                    maxR = max(maxR, i);
                    maxC = max(maxC, j);
                    minR = min(minR, i);
                    minC = min(minC, j);
                }
            
        return (maxC - minC + 1) * (maxR - minR + 1);
    }
};