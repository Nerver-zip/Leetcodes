class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //Problema analogo ao LIS
        const int n = strs.size();
        const int m = strs[0].size();

        vector<int> dp(m, 1);

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (strs[i][k] > strs[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
            }
        }

        int longest = *max_element(dp.begin(), dp.end());
        return m - longest;
    }
};