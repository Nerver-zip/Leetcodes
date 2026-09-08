struct Compare {
    bool operator()(const array<int,3>& a, const array<int, 3>& b) const {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        const int ROWS = heightMap.size();
        const int COLS = heightMap[0].size();

        auto isOutOfBoundsOrVisited = [&](int r, int c){
            return r == ROWS || c == COLS || r < 0 || c < 0 || heightMap[r][c] == -1; 
        };

        const vector<pair<int,int>> directions = {
                {0,1},
                {1,0},
                {0,-1},
                {-1,0}
        };

        priority_queue<array<int, 3>, vector<array<int,3>>, Compare> minHeap;

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS-1)
                {
                    minHeap.push({heightMap[i][j],i,j});
                    heightMap[i][j] = -1; //visited
                }
        
        int ans = 0;
        int maxHeight = -1;

        while (!minHeap.empty())
        {
            auto [currHeight, currRow, currCol] = minHeap.top();
            minHeap.pop();
            maxHeight = max(maxHeight, currHeight);
        
            for (const auto& [r, c] : directions) {
                int newRow = currRow + r, newCol = currCol + c;

                if (isOutOfBoundsOrVisited(newRow, newCol)) {
                    continue;
                }

                ans += max(0, maxHeight - heightMap[newRow][newCol]);
                minHeap.push({heightMap[newRow][newCol],newRow,newCol});
                heightMap[newRow][newCol] = -1;
            }
            
        }
        return ans;
    }
};