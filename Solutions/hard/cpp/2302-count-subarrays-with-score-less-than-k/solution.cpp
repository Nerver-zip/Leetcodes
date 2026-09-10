class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long size = nums.size();
        long long totalSubarrays = size * (size+1)/2;

        int right = 0;
        int left = 0;
        long long score = 0;
        long long count = 0;

        for (right; right < nums.size(); right++)
        {
            score += nums[right];
            while (score * (right - left + 1) >= k)
            {
                count += nums.size() - right;
                score -= nums[left];
                left++;
            }
        }
        return totalSubarrays - count;
    }
};