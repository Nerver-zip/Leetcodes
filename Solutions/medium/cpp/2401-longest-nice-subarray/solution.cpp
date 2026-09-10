class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while (nums[right] & curr)
            {
                curr ^= nums[left]; //undo
                left++;
            }
            ans = std::max(ans,(right+1) - left);
            curr |= nums[right]; //set bit
        }
        return ans;
    }
};