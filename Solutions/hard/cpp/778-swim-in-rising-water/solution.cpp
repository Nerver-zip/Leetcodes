class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        const vector<pair<int,int>> directions = {{
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        }};

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap; 
        vector<vector<int>> minTimeToReach(N, vector<int>(N, INT32_MAX));
        
        minHeap.push({grid[0][0],0,0});
        minTimeToReach[0][0] = grid[0][0];

        while (!minHeap.empty()) {
            auto [currTime, currRow, currCol] = minHeap.top();
            minHeap.pop();

            if(minTimeToReach[currRow][currCol] < currTime)
                continue;

            for (const auto& [r, c] : directions) {
                int newRow = currRow + r, newCol = currCol + c;

                if(newRow < 0 || newCol < 0 || newRow == N || newCol == N)
                    continue;
                
                int newTime = currTime;
                if(currTime < grid[newRow][newCol])
                    newTime = grid[newRow][newCol];

                if(newTime < minTimeToReach[newRow][newCol]){
                    minTimeToReach[newRow][newCol] = newTime;
                    minHeap.push({newTime, newRow, newCol});
                }
            }
        }
        
        return minTimeToReach[N-1][N-1];
    }
};