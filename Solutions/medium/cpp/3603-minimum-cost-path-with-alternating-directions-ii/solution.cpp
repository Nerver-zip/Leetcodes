struct Compare
{
    bool operator()(const array<long long, 3>& a, const array<long long, 3>& b) const {
        return a[0] > b[0];
    }
};
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> minCostToCell(m, vector<long long>(n, INT64_MAX));
        vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
        };

        priority_queue<array<long long, 3>, vector<array<long long, 3>>, Compare> minHeap; //{time, second parity, row, col}
        minHeap.push({1,0,0});
        minCostToCell[0][0] = 1;

        while (!minHeap.empty())
        {
            auto [currCost, currRow, currCol] = minHeap.top();
            minHeap.pop();

            if(currCost > minCostToCell[currRow][currCol])
                continue;

            for (const auto& [r, c] : directions)
            {
                int newRow = currRow + r;
                int newCol = currCol + c;
                long long newCurrCost = currCost;
                
                if (newRow == m || newCol == n)
                    continue;
                
                if(!(currRow == 0 && currCol == 0))
                    newCurrCost += waitCost[currRow][currCol];
                
                long long updatedTime = (newRow + 1) * (newCol + 1) + newCurrCost;
                if (minCostToCell[newRow][newCol] > updatedTime)
                {
                    minCostToCell[newRow][newCol] = updatedTime;
                    minHeap.push({updatedTime, newRow, newCol});
                }
            }
        }
        return minCostToCell[m-1][n-1];
    }
};