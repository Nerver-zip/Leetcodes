#define INFINITE 100000000
struct Compare {
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[0] > b[0]; //Min heap sorted by first element
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
        };
        vector<vector<int>> efforts(ROWS, vector<int>(COLS, INFINITE));

        priority_queue<array<int,3>, vector<array<int,3>>, Compare> minHeap; //effort, row, col
        minHeap.push({0,0,0});
        efforts[0][0] = 0;
        
        while (!minHeap.empty())
        {
            auto [currEffort, currRow, currCol] = minHeap.top();
            minHeap.pop();

            if(currEffort > efforts[currRow][currCol])
                continue;
            for (const auto& [row, col] : directions)
            {
                int newRow = row + currRow;
                int newCol = col + currCol;
                if (newRow < 0 || newCol < 0 || newRow == ROWS || newCol == COLS)
                {
                    continue;
                }
                int newEffort = abs(heights[currRow][currCol] - heights[newRow][newCol]);
                int maxEffort = std::max(currEffort, newEffort);
                if (efforts[newRow][newCol] > maxEffort)
                {
                    efforts[newRow][newCol] = maxEffort;
                    minHeap.push({maxEffort, newRow, newCol});
                }
            }
        }
        return efforts[ROWS-1][COLS-1];
    }
};