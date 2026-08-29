using ll = long long;
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> timeToReach(n, vector<int>(m, numeric_limits<int>::max()));
        
        unordered_set<ll> sourceSet;

        auto pack = [](int x, int y){
            return ((unsigned long long)x << 32) | (unsigned int)y;
        };
        
        auto isOutOfBounds = [n, m](int r, int c){
            return n == r || m == c || r < 0 || c < 0;
        };

        queue<array<int, 4>> q; // {r, c, color, time}

        for(const auto& s : sources){
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            q.push({r,c,color,0});
            timeToReach[r][c] = 0;
            sourceSet.insert(pack(r,c));
        }

        while (!q.empty()) {
            auto [currRow, currCol, currColor, currTime] = q.front();
            q.pop();

            for(const auto& [nr, nc] : directions){
                int newRow = nr + currRow, newCol = nc + currCol;

                if(isOutOfBounds(newRow, newCol))
                    continue;

                if(timeToReach[newRow][newCol] > currTime && !sourceSet.contains(pack(newRow, newCol))){
                    timeToReach[newRow][newCol] = currTime;
                    grid[newRow][newCol] = currColor;
                    q.push({newRow, newCol, currColor, currTime + 1});
                }
                else if(timeToReach[newRow][newCol] == currTime && currColor > grid[newRow][newCol]
                        && !sourceSet.contains(pack(newRow, newCol))){
                    grid[newRow][newCol] = currColor;
                    q.push({newRow, newCol, currColor, currTime + 1});
                }
            }
        }

        return grid;
    }

private:
    static constexpr array<pair<int,int>, 4> directions = {{
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    }};
};