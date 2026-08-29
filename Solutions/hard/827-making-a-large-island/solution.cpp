//Idea: Pre compute every island area (BFS or DFS). Assign each island area to a key
//From each 0, go in each direction and use the island map to increment the area if there's one
//Use hashset so you dont visit same island twice (look for same keys)
//If grid is all 0 return 1
//If grid is all 1, return n * n; (grid is guaranteed to be a square)

class Solution {
private:
    int dfs(vector<vector<int>>& grid, std::unordered_map<int,int>& islandMap, int key, const vector<std::pair<int,int>> directions,
            int row, int col, const int SIZE){
        
        int sum = grid[row][col];
        grid[row][col] = key;
        for (const auto& neighbor : directions)
        {
            int newRow = row + neighbor.first;
            int newCol = col + neighbor.second;
            if (isOutOfBounds(newRow,newCol,SIZE) || grid[newRow][newCol] == 0 || grid[newRow][newCol] > 1)
            {
                continue;
            }
            sum += dfs(grid,islandMap,key,directions,newRow,newCol,SIZE);
        }
        return sum;
    }

    int connect(vector<vector<int>>& grid,const vector<std::pair<int,int>> directions, std::unordered_map<int,int>& islandMap,
                int row, int col, const int SIZE){
        
        std::unordered_set<int> visited;
        grid[row][col] = 1;
        int sum = 1;

        for (const auto& neighbor : directions)
        {
            int newRow = row + neighbor.first;
            int newCol = col + neighbor.second;
            int key = isOutOfBounds(newRow,newCol,SIZE) ? 0 : grid[newRow][newCol];
            if (key == 0 || visited.find(key) != visited.end())
            {
                continue;
            }
            visited.insert(key);
            sum += islandMap[key];
        }
        return sum;
    }

    bool isOutOfBounds(int row, int col, int SIZE){
        return row < 0 || col < 0 || row == SIZE || col == SIZE;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int SIZE = grid.size();
        std::unordered_map<int,int> islandMap;
        std::queue<std::pair<int,int>> nonIsland;
        int key = 2;

        vector<std::pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
        };

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (grid[i][j] == 1)
                {
                    islandMap[key] = dfs(grid,islandMap,key,directions,i,j,SIZE);
                    key++;
                }
                else if(grid[i][j] == 0){
                    nonIsland.push({i,j});
                }      
            }    
        }
        int max = 0;
        while (!nonIsland.empty())
        {
            auto [currRow, currCol] = nonIsland.front();
            nonIsland.pop();
            max = std::max(max,connect(grid,directions,islandMap,currRow,currCol,SIZE));
        }
       //if grid is full of 1, max will be 0 here, so we should return the total number of cells 
       return max == 0 ? SIZE * SIZE : max;
    }
};