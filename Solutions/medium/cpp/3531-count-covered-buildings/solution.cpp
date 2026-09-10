class Solution {
private:
    bool isCovered(int row, int col, const vector<set<int>>& buildingRows, const vector<set<int>>& buildingCols){
        bool hasLeft = !buildingRows[row].empty() && *buildingRows[row].begin() < col;
        bool hasRight = !buildingRows[row].empty() && *buildingRows[row].rbegin() > col;
        bool hasAbove = !buildingCols[col].empty() && *buildingCols[col].begin() < row;
        bool hasBelow = !buildingCols[col].empty() && *buildingCols[col].rbegin() > row;

        return hasLeft && hasRight && hasAbove && hasBelow;
    }

public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) { //input is 1-indexed
        int ROWS = n;
        int COLS = n;

        vector<set<int>> buildingRows(n);
        vector<set<int>> buildingCols(n);
        
        for (const auto& direction : buildings)
        {
            int row = direction[0]-1;
            int col = direction[1]-1;
            buildingRows[row].insert(col);
            buildingCols[col].insert(row);
        }

        int ans = 0;

        for (const auto& direction : buildings)
        {
            int row = direction[0]-1;
            int col = direction[1]-1;
            
            if (isCovered(row, col, buildingRows, buildingCols))
                ans++;
        }
        return ans;
    }
};
