class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        auto applyRowShift = [&](int r){
            auto& v = grid[r];
            
            vector<int> newRow;
            for(int i = 1; i < n; ++i){
                newRow.push_back(v[i]);
            }
            newRow.push_back(v.front());
            v = newRow;
        };

        auto applyColShift = [&](int c){
            
            vector<int> newCol;
            for(int r = 1; r < n; ++r){
                newCol.push_back(grid[r][c]);
            }
            newCol.push_back(grid[0][c]);

            for(int r = 0; r < n; ++r){
                grid[r][c] = newCol[r];
            }
        };

        for(int i = 0; i < rowShift.size(); ++i){
            while(rowShift[i]--){
                applyRowShift(i);
            }
        }

        for(int i = 0; i < colShift.size(); ++i){
            while(colShift[i]--){
                applyColShift(i);
            }
        }

        return grid;
    }
};