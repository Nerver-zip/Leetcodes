class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int maxSum = nums[0];
        int currSum = 0;
        bool foundPivot = false;

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] < nums[i+1] && !foundPivot)
            {
                foundPivot = true;
                currSum = nums[i];
            }
            if (nums[i] < nums[i+1] && foundPivot)
            {
                currSum += nums[i+1];
                maxSum = std::max(currSum,maxSum);
            }
            else
            {
                currSum = 0;
                foundPivot = false;
            }
        }
        return maxSum;
    }
};