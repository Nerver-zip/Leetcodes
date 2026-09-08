class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMaxSum = 0;
        int currMinSum = 0;
        int max = 0;
        int min = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currMaxSum += nums[i];
            currMinSum += nums[i];
            max = std::max(currMaxSum,max);
            min = std::min(currMinSum,min);
            if (currMaxSum < 0)
                currMaxSum = 0;
            if (currMinSum > 0)
                currMinSum = 0;
        }

        min = abs(min);

        return max > min ? max : min;
    }
};