class Solution {
public:
    int countPartitions(vector<int>& nums) {
        const int N = nums.size();
        int rightSum = 0; 
        
        for (int n : nums)
            rightSum += n;

        rightSum -= nums[0];    
        int leftSum = nums[0], ans = 0;
    
        for (int i = 1; i < N; ++i) {
            if((rightSum - leftSum) % 2 == 0)
                ++ans;

            leftSum += nums[i];
            rightSum -= nums[i];
        }

        return ans;
    }
};