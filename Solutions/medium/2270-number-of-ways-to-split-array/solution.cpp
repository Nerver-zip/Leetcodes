class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {   
        int ways = 0;
        long long* prefixRightLeft = nullptr;
        prefixRightLeft = new long long[nums.size()];
        prefixRightLeft[nums.size()-1] = nums[nums.size()-1];

        for (int i = nums.size()-2; i >= 0; i--)
        {
            prefixRightLeft[i] = nums[i] + prefixRightLeft[i+1];
        }        

        long long* leftRightSum = nullptr;
        leftRightSum = new long long[nums.size()];
        leftRightSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            leftRightSum[i] = leftRightSum[i-1] + nums[i];
            if (leftRightSum[i-1] >= prefixRightLeft[i])
            {
                ways++;
            } 
        }

        delete[] leftRightSum;
        delete[] prefixRightLeft;
        return ways;
    }
};