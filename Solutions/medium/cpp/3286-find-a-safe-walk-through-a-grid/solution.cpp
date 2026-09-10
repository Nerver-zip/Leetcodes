class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<vector<bool>>> canReach(m, 
               vector<vector<bool>>(n, 
               vector<bool>(health+1, false)));
    
        
        queue<array<int,3>> q;
        canReach[0][0][health - grid[0][0]] = true;
        
        q.push({0,0, health - grid[0][0]});

        while(!q.empty()){
            auto [r, c, h] = q.front();
            q.pop();

            if(r == m-1 && c == n-1 && h)
                return true;
            
            if(h >= 1){
                for(const auto& [dr, dc] : directions){
                    int nr = r + dr, nc = c + dc;

                    if(isOutOfBounds(nr, nc, m, n))
                        continue;

                    int cost = grid[nr][nc];
                    
                    if(!canReach[nr][nc][h - cost]){
                        q.push({nr, nc, h-cost});
                        canReach[nr][nc][h-cost] = true;
                    }
                }
            }

        }

        return false;
    }

private:
    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    }};

    bool isOutOfBounds(int r, int c, int m, int n) const {
        return r < 0 || r == m || c < 0 || c == n;
    }
};