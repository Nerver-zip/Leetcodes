class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size();
        const int n = isWater[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(isWater[i][j]){
                    q.push({i,j});
                    visited[i][j] = true;
                    isWater[i][j] = 0;
                }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for(const auto& [r, c] : directions){
                int newRow = row + r, newCol = col + c;

                if(isOutOfBounds(newRow, newCol, m, n) || visited[newRow][newCol])
                    continue;
                
                isWater[newRow][newCol] = isWater[row][col] + 1;
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
        
        return isWater;
    }
private:
    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    }};

    bool isOutOfBounds(int r, int c, int m, int n){
        return r < 0 || r == m || c < 0 || c == n;
    }
};