class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();

        if(n < 3)
            return -1;

        int ans = numeric_limits<int>::max();

        for(int i = 0; i < n-2; ++i)
            for(int j = i+1; j < n-1; ++j)
                for(int k = j+1; k < n; ++k)
                    if(nums[i] == nums[j] && nums[j] == nums[k])
                        ans = min(ans, abs(i - j) + abs(j - k) + abs(k - i));
        
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};