class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mask = 1;
        int operations = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            //we're forced to apply operation when n[left] = 0
            if (nums[left] == 0)
            {
                nums[left] ^= mask;
                nums[left+1] ^= mask;
                nums[left+2] ^= mask;
                operations++;
            }
            if (right-left+1 == 3)
                left++;
        }
        return nums[nums.size()-2] == 0 || nums[nums.size()-1] == 0 ? -1 : operations;
    }
};