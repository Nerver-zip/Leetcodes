class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        queue<array<int,3>> q; // {i,j, tempo}
        
        int total_oranges = 0;
        int rotten_oranges = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                    ++rotten_oranges;
                    ++total_oranges;
                }
                else if(grid[i][j] == 1){
                    ++total_oranges;
                }

            }
        }
                 
        while(!q.empty()){
            auto [i, j, t] = q.front();
            q.pop();
            
            for(const auto& [di, dj] : directions){
                int ni = i + di, nj = j + dj;

                if(isOutOfBounds(ni, nj, m, n))
                    continue;
                
                if(grid[ni][nj] == 1){
                    ++rotten_oranges;
                    if(total_oranges == rotten_oranges)
                        return t + 1;
                    grid[ni][nj] = 2;
                    q.push({ni, nj, t + 1});
                }
            }
        }

        return total_oranges != rotten_oranges ? -1 : 0;
    }

private:
    
    static bool isOutOfBounds(int x, int y, int m, int n) {
        return x < 0 || x == m || y < 0 || y == n;
    }

    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    }};
};