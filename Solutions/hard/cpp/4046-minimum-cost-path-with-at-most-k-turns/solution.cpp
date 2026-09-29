class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        
        enum Directions {
            UNKNOWN,
            RIGHT,
            DOWN,
            UP,
            LEFT
        };

        vector<vector<vector<vector<int>>>> dist(m, vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1, vector<int>(5, INT_MAX))));
        priority_queue<array<int, 5>, vector<array<int, 5>>, greater<>> minHeap; // {cost, turns, direction, i, j}

        minHeap.push({grid[0][0],0,UNKNOWN,0,0});
        dist[0][0][0][UNKNOWN] = grid[0][0];

        while(!minHeap.empty()){
            auto [cost, turns, direction, x, y] = minHeap.top();
            minHeap.pop();

            if(dist[x][y][turns][direction] < cost){
                continue;
            }
            
            int newDir = 0;
            for(const auto& [dx, dy] : directions){
                int nx = x + dx, ny  = y + dy;
                ++newDir; 
                if(isOutOfBounds(m, n, nx, ny)){
                    continue;
                }

                int newCost = cost + grid[nx][ny];
                
                if(direction == UNKNOWN){ 
                    if(newCost < dist[nx][ny][turns][newDir]){
                        dist[nx][ny][turns][newDir] = newCost;
                        minHeap.push({newCost, turns, newDir, nx, ny});
                    }
                }
                else if(newDir == direction){
                    if(newCost < dist[nx][ny][turns][newDir]){
                        dist[nx][ny][turns][newDir] = newCost;
                        minHeap.push({newCost, turns, newDir, nx, ny});
                    }
                }
                else{
                    if(turns + 1 <= k && newCost < dist[nx][ny][turns+1][newDir]){
                        dist[nx][ny][turns+1][newDir] = newCost;
                        minHeap.push({newCost, turns+1, newDir, nx, ny});
                    }
                }
            }
        }

        int ans = numeric_limits<int>::max();

        for(int x = 0; x <= k; ++x){
            for(int dir = 0; dir <= 4; ++dir){
                ans = min(ans, dist[m-1][n-1][x][dir]);
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }

private:
    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    }};

    bool isOutOfBounds(int m, int n, int x, int y) const {
        return x < 0 || x == m || y < 0 || y == n;
    }
};