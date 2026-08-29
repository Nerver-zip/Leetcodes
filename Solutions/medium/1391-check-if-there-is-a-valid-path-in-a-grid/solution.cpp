class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<array<int,3>> q;
        q.push({0,0, grid[0][0]});
        visited[0][0] = true;    

        while (!q.empty()) {
            auto [r, c, street] = q.front();
            q.pop();
            
            for(int originDir = 0; originDir < 4; ++originDir){
                
                int nr = r + directions[originDir].first, nc = c + directions[originDir].second;
    
                if(isOutOfBounds(nr, nc) || !allowedDirections[street][originDir])
                    continue;
                
                int newStreet = grid[nr][nc];
                int newDir = originDir == RIGHT ? LEFT 
                           : originDir == DOWN ? UP 
                           : originDir == UP ? DOWN 
                           : RIGHT;

                    if(allowedDirections[newStreet][newDir] && !visited[nr][nc]){
                        q.push({nr, nc, newStreet});
                        visited[nr][nc] = true;
                    }
                }
            }

        return visited[m-1][n-1];
    }
private:
    int m, n;
    
    enum cardinals {
        RIGHT,
        DOWN,
        UP,
        LEFT
    };

    static inline constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    }};
    
    // x[street][cardinal] = true/false
    static inline constexpr array<array<bool,4>, 7> allowedDirections = {{
        {0,0,0,0},
        {1,0,0,1},
        {0,1,1,0},
        {0,1,0,1},
        {1,1,0,0},
        {0,0,1,1},
        {1,0,1,0}
    }};
    
    bool isOutOfBounds(int r, int c) const {
        return r < 0 || r == m || c < 0 || c == n;
    }
};