class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        for(int i = 0; i < nums.size()-1; ++i){
            sum -= nums[i];
            int avg = sum/(nums.size()-i-1);

            if(nums[i] > avg)
                ++ans;
        }
        return ans;
    }
};