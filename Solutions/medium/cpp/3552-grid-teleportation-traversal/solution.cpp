struct Compare
{
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[0] > b[0];
    }
};


class Solution {
public:
    int minMoves(vector<string>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> portalMap;
        vector<vector<int>> distanceToCell(ROWS, vector<int>(COLS, INT_MAX));
        vector<bool> usedPortal(26, false);
        priority_queue<array<int, 3>, vector<array<int, 3>>, Compare> minHeap;

        const vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
            {-1, 0},
            {0,-1}
        };

        // Preprocess portals
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z') {
                    portalMap[c].emplace_back(i, j);
                }
            }
        }

        minHeap.push({0,0,0});
        distanceToCell[0][0] = 0;

        while (!minHeap.empty())
        {
            auto [currDist, currRow, currCol] = minHeap.top();
            minHeap.pop();

            if(distanceToCell[currRow][currCol] < currDist)
                continue;

            for (const auto& [r, c] : directions)
            {
                int newRow = currRow + r;
                int newCol = currCol + c;

                if(newRow < 0 || newCol < 0 || newRow == ROWS || newCol == COLS || matrix[newRow][newCol] == '#')
                    continue;
                
                if (distanceToCell[newRow][newCol] > currDist + 1)
                {
                    distanceToCell[newRow][newCol] = currDist + 1;
                    minHeap.push({currDist + 1, newRow, newCol});
                }
            }
            //try teleporting
            char c = matrix[currRow][currCol];
            if (c >= 'A' && c <= 'Z' && !usedPortal[c - 'A']) {
                usedPortal[c - 'A'] = true;
                for (auto& [pr, pc] : portalMap[c]) {
                    if (pr == currRow && pc == currCol) 
                        continue;
                    if (distanceToCell[pr][pc] > currDist) {
                        distanceToCell[pr][pc] = currDist;
                        minHeap.push({currDist, pr, pc});
                    }   
                }
            }
        }
        return distanceToCell[ROWS-1][COLS-1] == INT32_MAX ? -1 : distanceToCell[ROWS-1][COLS-1];
    }
};