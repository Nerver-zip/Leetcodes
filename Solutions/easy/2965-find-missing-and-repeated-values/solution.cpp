class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<int> frequencyMap(ROWS * COLS + 1, 0);

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                frequencyMap[grid[i][j]]++;

        vector<int> ans(2,0);

        for (int i = 1; i < frequencyMap.size(); i++)
        {
            if (frequencyMap[i] == 2)
            {
                ans[0] = i;
                if (ans[0] != 0 && ans[1] != 0)
                    return ans;
            }
            else if(frequencyMap[i] == 0)
            {
                ans[1] = i;
                if (ans[0] != 0 && ans[1] != 0)
                    return ans;
            }
        }
        return ans;
    }
};