class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int size = nums.size();
        int res = 0;
        long long sum = 0;

        for(int n : nums){
            res ^= n;
            sum += n;
        }

        if(sum == 0)
            return 0;

        return res == 0 ? size-1 : size;
    }
};