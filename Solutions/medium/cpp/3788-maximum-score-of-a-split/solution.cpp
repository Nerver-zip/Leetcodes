using ll = long long;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        const int n = nums.size();

        vector<ll> prefix(n,0);

        prefix[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + nums[i] * 1LL;
        }

        vector<ll> suffixMin(n, 0);
        ll currMin = nums[n-1];

        for (int i = n-2; i >= 0; --i) {
            suffixMin[i] = currMin;
        
            if(nums[i] < currMin)
                currMin = nums[i];
        }

        ll maxScore = INT64_MIN;

        for (int i = 0; i < n-1; ++i) {
            maxScore = max(maxScore, prefix[i] - suffixMin[i]);
        }

        return maxScore;
    }
};