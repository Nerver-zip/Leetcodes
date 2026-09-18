class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i] = máximo de palíndromos usando s[0..i-1]
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            // Não usar nenhum palíndromo terminando em i-1
            dp[i] = dp[i - 1];

            // Palíndromo de tamanho k terminando em i-1
            if (i >= k && isPalindrome(s, i - k, i - 1)) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            // Palíndromo de tamanho k+1 terminando em i-1
            if (i >= k + 1 && isPalindrome(s, i - k - 1, i - 1)) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};