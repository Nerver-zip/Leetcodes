class Solution {
private:
    int dfs(const vector<std::pair<int,int>>& neighbors, vector<vector<int>>& grid, int row, int col, const int ROWS, const int COLS){
        int sum = grid[row][col];
        grid[row][col] = 0;
        for (const auto& neighbor : neighbors)
        {
            int newRow = row + neighbor.first;
            int newCol = col + neighbor.second;
            if (newCol < 0 || newRow < 0 || newRow == ROWS || newCol == COLS || grid[newRow][newCol] == 0)
            {
                continue;
            }
            sum = sum + dfs(neighbors,grid,newRow,newCol,ROWS,COLS);
        }
        return sum;
    }            
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxFish = 0;
        vector<std::pair<int,int>> neighbors = {
            {0,1},
            {0,-1},
            {-1, 0},
            {1, 0}
        };

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] != 0)
                {
                    maxFish = std::max(maxFish,dfs(neighbors,grid,i,j,ROWS,COLS));
                }
            }
        }
        return maxFish;    
    }
};