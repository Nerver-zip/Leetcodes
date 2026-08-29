class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;

        while(n > k){
            n -= k;
            ans += static_cast<long long>(n) * static_cast<long long>(k);
        }

        while (m > k)
        {
            m -= k;
            ans += static_cast<long long>(m) * static_cast<long long>(k);
        }

        return ans;
    }
};