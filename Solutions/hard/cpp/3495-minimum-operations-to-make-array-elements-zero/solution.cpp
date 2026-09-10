class Solution {
public:
    //How many divisions are necessary to make all numbers from 1 to n equal to 0
    long long F(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long start = 1;
        long long k = 1;
        while (start <= n) {
            long long end = min(n, ((long long)1 << (2*k)) - 1); // 4^k - 1
            res += (end - start + 1) * k;
            start = (1LL << (2*k)); // 4^k
            k++;
        }
        return res;
    }
    
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = F(r) - F(l-1);
            ans += (totalSteps + 1) / 2; // ceil(totalSteps/2)
        }
        return ans;
    }
};