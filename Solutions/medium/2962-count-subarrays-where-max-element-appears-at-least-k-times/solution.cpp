class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *std::max_element(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        long long ans = 0;
        int countMax = 0;

        for(right; right < nums.size(); right++){
            if (nums[right] == max)
                countMax++;
            while (countMax == k)
            {
                ans += nums.size() - right;
                if(nums[left] == max)
                    countMax--;
                left++;
            }
        }
        return ans;
    }
};