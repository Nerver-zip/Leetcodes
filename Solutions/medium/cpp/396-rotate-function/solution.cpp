class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int n = nums.size();
        int f = 0;
        int sum = 0;

        for(int i = 0; i < n; ++i){
            f += 1LL * nums[i] * i;
            sum += nums[i];
        }
        
        int ans = f;
        for(int i = 1; i < n; ++i){
            f = f + sum - 1LL * n * nums[n-i];
            ans = max(ans, f);
        }

        return ans;
    }
};