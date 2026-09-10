class Solution {
private:
    void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, const vector<std::pair<int,int>>& directions, 
            std::pair<int,int> node, const std::pair<int,int>& end, const int emptySquares, int& paths, int count){
        if (node.first == end.first && node.second == end.second && count == emptySquares+1)
        {
            paths++;
            return;
        }
        for (const auto& [row, col] : directions)
        {
            int newRow = node.first + row;
            int newCol = node.second + col;

            if (newRow == grid.size() || newCol == grid[0].size() || newRow < 0 || newCol < 0 ||
                grid[newRow][newCol] == 1 || grid[newRow][newCol] == -1 || visited[newRow][newCol] )
            {
                continue;
            }
            visited[newRow][newCol] = true;
            dfs(grid,visited,directions,{newRow,newCol},end,emptySquares,paths,count+1);
            //backtrack
            visited[newRow][newCol] = false;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<bool>> visited(ROWS,vector<bool>(COLS));
        const vector<std::pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
        };

        int paths = 0;
        int emptySquares = 0;
        std::pair<int,int> start, end; //rows, cols

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    start = {i,j};
                    visited[i][j] = true;
                }
                else if (grid[i][j] == 2)
                {
                    end = {i,j};
                }
                else if (grid[i][j] == 0)
                {
                    emptySquares++;
                }
            }
        }
        dfs(grid,visited,directions,start,end,emptySquares,paths,0);
        return paths;
    }
};