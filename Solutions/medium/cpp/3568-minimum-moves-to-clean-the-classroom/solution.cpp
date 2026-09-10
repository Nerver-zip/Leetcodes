class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size();
        n = classroom[0].size();
        
        vector<vector<int>> id(m, vector<int>(n, 0));
        int litterId = 0;
        int start_x, start_y;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'L') {
                    id[i][j] = litterId++;
                }

                if(classroom[i][j] == 'S'){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
        // minMoves[m][n][energy][mask] == minMoves to achieve that state
        vector<vector<vector<vector<int>>>> minMoves(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy + 1, vector<int>(1 << litterId, INT_MAX))));     
        
        // {x,y, dist, energy_used, mask}
        queue<array<int, 5>> q;
        q.push({start_x, start_y, 0, 0, 0});
        int ans = numeric_limits<int>::max();

        while(!q.empty()){
            auto [x, y, dist, e, mask] = q.front();
            q.pop();
            
            if(mask == (1 << litterId) - 1){
                return dist;
            }

            if(minMoves[x][y][e][mask] < dist || e == energy){
                continue;
            }

            for(const auto& [dx, dy] : directions){
                int nx = x + dx, ny = y + dy;
                int newEnery = energy; 

                if(isNotValid(classroom, nx, ny)){
                    continue;
                }

                if(classroom[nx][ny] == 'R'){
                    if(minMoves[nx][ny][e+1][mask] > dist + 1){
                        minMoves[nx][ny][e+1][mask] = dist + 1;
                        q.push({nx, ny, dist + 1, 0, mask});
                    }
                }
                else if(classroom[nx][ny] == 'L'){
                    int newMask = mask | 1 << id[nx][ny]; 
                    if(minMoves[nx][ny][e+1][newMask] > dist + 1){
                        minMoves[nx][ny][e+1][newMask] = dist + 1;
                        q.push({nx, ny, dist + 1, e + 1, newMask});
                    }
                }
                else
                { 
                    if(minMoves[nx][ny][e+1][mask] > dist + 1){
                        minMoves[nx][ny][e+1][mask] = dist + 1;
                        q.push({nx, ny, dist + 1, e + 1, mask});
                    }
                }
            }
        }
        
        return -1;
    }
private:
    int m, n;

    static constexpr array<pair<int,int>, 4> directions = {
        {{0,1},{1,0},{-1,0},{0,-1}}
    };

    bool isNotValid(const vector<string>& grid, int x, int y) const {
        return x == m || x < 0 || y == n || y < 0 || grid[x][y] == 'X';  
    }
};