class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        int s = 0;
        int num = 0;
        for (int pos = 0; pos < nums.size(); ++pos) {
            num |= nums[pos];
            if((num %= 5) == 0)
                ans[pos] = true;
            num = num << 1;
        }

        return ans;
    }
};