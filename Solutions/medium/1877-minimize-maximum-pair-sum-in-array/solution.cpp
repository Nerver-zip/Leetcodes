class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size()-1, ans = 0;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            ans = max(ans, sum);
            --right;
            ++left;
        }

        return ans;
    }
};