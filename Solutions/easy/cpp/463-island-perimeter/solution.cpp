class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        const int m = grid.size();
        const int n = grid[0].size();
            
        auto bfs = [&](int src_row, int src_col){
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            queue<pair<int,int>> q;
            q.push({src_row, src_col});
            visited[src_row][src_col] = true;

            int perimeter = 0;
            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();
                
                for(const auto& [i, j] : directions){
                    int new_row = row + i, new_col = col + j;
                    
                    
                    if(isOutOfBounds(m, n, new_row, new_col) || grid[new_row][new_col] == 0) // sitting in a land and seeing water
                        ++perimeter;
                    else if(visited[new_row][new_col])
                        continue;
                    else{
                        q.push({new_row, new_col});
                        visited[new_row][new_col] = true;
                    }
                }
            }

            return perimeter;
        };

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)
                    return bfs(i,j);
            }
        }
        
        return 0;
    }
private:
    static constexpr array<pair<int,int>, 4> directions = {
        {{0,1},
        {-1,0},
        {1,0},
        {0,-1}}
    };

    bool isOutOfBounds(int M, int N, int r, int c){
        return r < 0 || r == M || c < 0 || c == N;
    }
};