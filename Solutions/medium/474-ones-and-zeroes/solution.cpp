class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //máximo número de strings que podem ser escolhidas com no máximo i zeros e j uns.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& str : strs) {
            const auto& [z, o] = countBits(str);
            
            for (int i = m; i >= z; --i) {
                for (int j = n; j >= o; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - z][j - o] + 1);
                }
            }
        }
        return dp[m][n];
    }
private:
    constexpr pair<int,int> countBits(string_view s){
        int zeros = 0;
        for(auto& c : s)
            if(c == '0')
                ++zeros;

        return {zeros, (int)s.size() - zeros}; //zeros, ones
    }
};