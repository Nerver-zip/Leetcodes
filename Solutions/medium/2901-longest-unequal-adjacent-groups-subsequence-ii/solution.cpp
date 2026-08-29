class Solution {
private:
    bool isValidPair(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < (int)a.size(); ++i)
            diff += (a[i] != b[i]);
        return diff == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = (int)words.size();
        vector<int> dp(n, 1);       
        vector<int> parent(n, -1);

        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && isValidPair(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        vector<string> result;
        for (int cur = maxIdx; cur != -1; cur = parent[cur]) {
            result.push_back(words[cur]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
