class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> nums;
        nums.reserve(m * n);
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(grid[i][j] % x != grid[0][0] % x)
                    return -1;
                nums.push_back(grid[i][j]);
            }

        sort(nums.begin(), nums.end()); 
        int ans = 0;
        int median = nums[nums.size()/2];

        for(int n : nums)
            ans += abs(median - n) / x;

        return ans;
    }
};