class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            return a > b;
        });

        int ans = 0;

        for (int i = 0; i < n-2; ++i)
            if(nums[i] < nums[i+1]+nums[i+2])
                ans = max(ans, nums[i] + nums[i+1] + nums[i+2]);

        return ans;
    }
};