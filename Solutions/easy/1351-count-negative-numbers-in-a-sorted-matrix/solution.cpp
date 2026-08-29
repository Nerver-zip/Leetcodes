class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if(grid[i][j] >= 0)
                    break;
                ++ans;
            }
        }
        return ans;
    }
};