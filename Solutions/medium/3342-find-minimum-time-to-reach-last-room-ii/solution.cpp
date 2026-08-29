struct Compare {
    bool operator()(const array<int,4>& a, const array<int, 4>& b) const {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int ROWS = moveTime.size();
        int COLS = moveTime[0].size();
        priority_queue<array<int,4>, vector<array<int,4>>, Compare> minHeap; //time, row, col, flag
        vector<vector<int>> minTimeToReachCell(ROWS, vector<int>(COLS, INT32_MAX));
        vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        minHeap.push({0,0,0,0});
        minTimeToReachCell[0][0] = 0;

        while (!minHeap.empty())
        {
            auto [currTime, currRow, currCol, flag] = minHeap.top();
            minHeap.pop();

            if (minTimeToReachCell[currRow][currCol] < currTime)
                continue;
            
            for (const auto& [r, c] : directions)
            {
                int newRow = currRow + r;
                int newCol = currCol + c;
                if (newRow < 0 || newCol < 0 || newRow == ROWS || newCol == COLS)
                    continue;
                if (flag == 0)
                {
                    int updatedTime = currTime >= moveTime[newRow][newCol] ? currTime + 1 : moveTime[newRow][newCol] + 1;
                    if (minTimeToReachCell[newRow][newCol] > updatedTime)
                    {
                        minTimeToReachCell[newRow][newCol] = updatedTime;
                        minHeap.push({updatedTime, newRow, newCol, 1});
                    }
                    
                }    
                else
                {
                    int updatedTime = currTime >= moveTime[newRow][newCol] ? currTime + 2 : moveTime[newRow][newCol] + 2;
                    if (minTimeToReachCell[newRow][newCol] > updatedTime)
                    {
                        minTimeToReachCell[newRow][newCol] = updatedTime;
                        minHeap.push({updatedTime, newRow, newCol, 0});
                    }
                }
            }
        }
        return minTimeToReachCell[ROWS-1][COLS-1];
    }
};