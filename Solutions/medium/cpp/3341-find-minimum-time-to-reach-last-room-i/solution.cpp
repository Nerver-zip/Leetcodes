#define INFINITE 10000000000
struct Compare {
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[0] > b[0]; //Min heap sorted by first element
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int ROWS = moveTime.size();
        int COLS = moveTime[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, Compare> minHeap; //i, j, time
        vector<vector<int>> minTimeToReachCell(ROWS, vector<int>(COLS, INFINITE));
        vector<pair<int,int>> directions = {
            {0,1},
            {-1,0},
            {1,0},
            {0,-1}
        };
        minHeap.push({0,0,0});
        minTimeToReachCell[0][0] = 0;

        while (!minHeap.empty())
        {
            auto [currRow, currCol, currTime] = minHeap.top();
            minHeap.pop();

            if (minTimeToReachCell[currRow][currCol] < currTime)
                continue;
            
            for (const auto& [r, c] : directions)
            {
                int newRow = currRow + r;
                int newCol = currCol + c;
                if (newRow < 0 || newCol < 0 || newRow == ROWS || newCol == COLS)
                {
                    continue;
                }
                //either increment by one if unlocked or increment by moveTime + 1 if not unlocked yet
                int updatedTime = currTime >= moveTime[newRow][newCol] ? currTime + 1 : moveTime[newRow][newCol] + 1;
                if (minTimeToReachCell[newRow][newCol] > updatedTime)
                {
                    minTimeToReachCell[newRow][newCol] = updatedTime;
                    minHeap.push({newRow, newCol, updatedTime});
                }
            }
        }
        return minTimeToReachCell[ROWS-1][COLS-1];
    }
};