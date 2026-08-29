struct Compare {
    bool operator()(const array<int,3>& a, const array<int,3>& b) const {
        return a[0] > b[0]; //Min heap sorted by first element
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, Compare> minHeap; //val, row, col
        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> queriesHeap; //val, index
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS));
        vector<int> maximumPoints(queries.size());
        vector<pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
        };
        int ans = 0;
        for  (int i = 0; i < queries.size(); i++)
            queriesHeap.push({queries[i],i});
        
        minHeap.push({grid[0][0],0,0});
        visited[0][0] = true;
        while (!minHeap.empty() && !queriesHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int currVal = top[0]; 
            int currRow = top[1];
            int currCol = top[2];
            
            while (!queriesHeap.empty() && queriesHeap.top().first <= currVal)
            {
                auto [query, index] = queriesHeap.top();
                maximumPoints[index] = ans;
                queriesHeap.pop();
            }
            ans++;
            for (const auto& [row, col] : directions)
            {
                int newRow = currRow + row;
                int newCol = currCol + col;
                if (newRow < 0 || newCol < 0 || newRow == ROWS || newCol == COLS || visited[newRow][newCol])
                {
                    continue;
                }
                minHeap.push({grid[newRow][newCol],newRow,newCol});
                visited[newRow][newCol] = true;
            }
        }

        while (!queriesHeap.empty()) //at this point the answer will always be N * M for the remaining queries
        {
            auto [query, index] = queriesHeap.top();
            maximumPoints[index] = ans;
            queriesHeap.pop();
        }

        return maximumPoints; 
    }
};