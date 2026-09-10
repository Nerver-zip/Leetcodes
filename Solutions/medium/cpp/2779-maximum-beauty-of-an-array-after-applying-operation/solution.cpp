class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //sorting into sw approach
        std::sort(nums.begin(),nums.end());
        int maxCount = 0;
        int right = 0;
        for (int left = 0; left < nums.size(); left++)
        {
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k)
            {
                right++;
                if (maxCount < right-left)
                {
                    maxCount = right-left;
                }
            }
        }
        return maxCount;
    }
};
