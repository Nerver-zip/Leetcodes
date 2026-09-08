class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> newNums;
        
        while (n--) {
            newNums.assign(n, 0);
            for (int i = 0; i < nums.size()-1; ++i) {
                newNums[i] = (nums[i] + nums[i+1]) % 10;
            }
            nums = newNums;
        }

        return newNums[0];
    }
};