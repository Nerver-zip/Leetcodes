class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        const int n = nums.size();
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        
        vector<int> ans;
        ans.reserve(nums.size());
        
        for(int i = 0; i < n; ++i){
            rightSum -= nums[i];
            ans.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }

        return ans;
    }
};