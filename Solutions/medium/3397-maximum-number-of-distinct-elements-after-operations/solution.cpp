class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minAvailable = INT32_MIN, ans = 0;

        for (int n : nums) {
            int lower = n - k, upper = n + k;
            
            if(lower > minAvailable)
                minAvailable = lower;

            if(upper >= minAvailable){
                ++ans;
                ++minAvailable;
            }
        }

        return ans;
    }
};