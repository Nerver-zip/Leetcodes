class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const int size = nums.size();

        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            int diff = abs(nums[i] - nums[(i+1) % size]);
            ans = max(ans, diff);    
        }
        return ans;
    }
};