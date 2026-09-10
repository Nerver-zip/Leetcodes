using ll = long long;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int n = s1.size();
        const int m = s2.size();
        
        //dp[i][j] = greatest ascii sum for common substrings starting at index i for s1, and j for s2
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        
        ll ascii_sum1 = 0, ascii_sum2 = 0;

        for(int i = 0; i < n; ++i)
            ascii_sum1 += s1[i];

        for(int i = 0; i < m; ++i)
            ascii_sum2 += s2[i];


        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        // we maximized the ascii sum with dp, now want to remove the max value
        // so whats left is the sum of the deleted characters not included in the longest common substring sum
        
        return ascii_sum1 + ascii_sum2 - 2 * dp[n][m];
    }
};