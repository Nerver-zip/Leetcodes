class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int ans = INT32_MAX;
        for(int right = k-1, left = 0; right < nums.size(); ++right){
            if(right - left + 1 > k)
                ++left;
            
            ans = min(ans, nums[right] - nums[left]);
        }

        return ans;
    }
};