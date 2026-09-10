using ll = long long;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int N = nums.size();

        vector<long long> prefixEven(N+1, 0), prefixOdd(N+1, 0);

        for (int i = 0; i < N; i++) {
            prefixEven[i+1] = prefixEven[i];
            prefixOdd[i+1]  = prefixOdd[i];

            if (i % 2 == 0) prefixEven[i+1] += nums[i];
            else            prefixOdd[i+1]  += nums[i];
        }
        
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            long long evenBefore = prefixEven[i];
            long long oddBefore  = prefixOdd[i];

            // sum of evens and odds *after* position i
            long long evenTotal = prefixEven[N] - prefixEven[i+1];
            long long oddTotal  = prefixOdd[N]  - prefixOdd[i+1];

            // After removing i, parity flips!
            long long evenAfter = oddTotal;
            long long oddAfter  = evenTotal;

            if (evenBefore + evenAfter == oddBefore + oddAfter)
                ans++;

        }
        
        return ans;
    }
};