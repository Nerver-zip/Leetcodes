class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> distToRobber(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    distToRobber[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto [dx,dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(isOutOfBounds(nx, ny, n, m))
                    continue;

                if(distToRobber[nx][ny] != INT_MAX)
                    continue;

                distToRobber[nx][ny] = distToRobber[x][y] + 1;
                q.push({nx,ny});
            }
        }

        vector<vector<int>> maxSafeFactor(n, vector<int>(m, 0));
        priority_queue<array<int, 3>> maxHeap;
        maxSafeFactor[0][0] = distToRobber[0][0];
        
        maxHeap.push({distToRobber[0][0],0,0});

        while(!maxHeap.empty()){
            auto [currW, x, y] = maxHeap.top();
            maxHeap.pop();
            
            if(x == n-1 && y == n-1) 
                return currW;

            if(maxSafeFactor[x][y] > currW)
                continue;
            
            maxSafeFactor[x][y] = currW;

            for(const auto& [dx, dy] : directions){
                int nx = x + dx, ny = y + dy;
                
                if(isOutOfBounds(nx, ny, m, n))
                    continue;
                
                // É preciso forçar o mínimo
                int newW = min(distToRobber[nx][ny], currW);

                if(newW > maxSafeFactor[nx][ny]){ 
                    maxSafeFactor[nx][ny] = newW; 
                    maxHeap.push({newW, nx, ny}); 
                } 
            }
        }

        return maxSafeFactor[n-1][m-1];
    }

private:
    bool isOutOfBounds(int x, int y, int M, int N) const {
        return x < 0 || x == M || y < 0 || y == N;
    }

    static constexpr array<pair<int,int>, 4> directions {{
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
    }};
};