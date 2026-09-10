class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);

        dp[0] = 1; // dp[0] significa prefixo vazio
        pref[0] = 1;

        deque<int> mn, mx;
        int L = 0;

        for (int i = 0; i < n; i++) {

            // Atualiza min deque
            while (!mn.empty() && nums[mn.back()] > nums[i])
                mn.pop_back();
            mn.push_back(i);

            // Atualiza max deque
            while (!mx.empty() && nums[mx.back()] < nums[i])
                mx.pop_back();
            mx.push_back(i);

            // Move L até ficar válido
            while (!mn.empty() && !mx.empty()
                   && nums[mx.front()] - nums[mn.front()] > k) {
                if (mn.front() == L) mn.pop_front();
                if (mx.front() == L) mx.pop_front();
                L++;
            }

            // dp[i+1] corresponde ao prefixo nums[0..i]
            long long ways = pref[i];
            if (L > 0) ways = (ways - pref[L-1] + MOD) % MOD;

            dp[i+1] = ways;
            pref[i+1] = (pref[i] + dp[i+1]) % MOD;
        }

        return dp[n];
    }
};