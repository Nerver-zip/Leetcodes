class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        std::unordered_map<int,std::pair<int,int>> positions;
        int ROWS = mat.size();
        int COLS = mat[0].size();

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                positions[mat[i][j]] = {i,j};
            } 
        }

        std::unordered_map<int,int> toCompleteRows;
        std::unordered_map<int,int> toCompleteCols;

        for (int i = 0; i < arr.size(); i++)
        {
            std::pair<int,int> currPosition = positions[arr[i]];
            toCompleteRows[currPosition.first]++;
            toCompleteCols[currPosition.second]++;
            //Number of rows = size of col and vice-verse
            if (toCompleteRows[currPosition.first] == COLS || toCompleteCols[currPosition.second] == ROWS)
            {
                return i;
            }
        }
        return -1;
    }
};