class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0, ans = 0, count = 0, zeroCount = 0;
        
        for(int n : nums){
            if(n == 1 && zeroCount == 0)
                ++left;
            else if (n == 0 && zeroCount == 0)
                zeroCount++;
            else if (n == 1 && zeroCount >= 1)
                ++right;
            else if (n == 0 && zeroCount >= 1){
                ans = max(ans, left + right);
                left = right;
                right = 0;
            }
        }

        ans = max(ans, left + right);

        return zeroCount == 0 ? nums.size()-1 : ans;
    }
};