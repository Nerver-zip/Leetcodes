class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const vector<pair<int,int>> startingPoints = {
            {0,0},{0,3},{0,6},
            {3,0},{3,3},{3,6},
            {6,0},{6,3},{6,6}
        };
        
        vector<unordered_set<char>> rowSet(10);
        vector<unordered_set<char>> colSet(10);

        for (const auto& [ROW, COL] : startingPoints) {
            unordered_set<char> squareSet;
            for (int i = ROW; i < ROW + 3; ++i) {
                for (int j = COL; j < COL + 3; ++j) {
                    char curr = board[i][j];
                    if(curr == '.')
                        continue;
                    if(squareSet.count(curr) || rowSet[i].count(curr) || colSet[j].count(curr))
                        return false;
                    squareSet.insert(curr);
                    rowSet[i].insert(curr);
                    colSet[j].insert(curr);
                }
            }            
        }
        return true;
    }
};
