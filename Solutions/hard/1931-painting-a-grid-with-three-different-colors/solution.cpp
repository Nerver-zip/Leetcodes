const int MOD = 1e9 + 7;
class Solution {
private:
void generatePatterns(int m, vector<vector<int>>& patterns, vector<int>& current) {
    if (current.size() == m) {
        patterns.push_back(current);
        return;
    }

    for (int color = 0; color < 3; ++color) {
        if (current.empty() || current.back() != color) {
            current.push_back(color);
            generatePatterns(m, patterns, current);
            current.pop_back();
        }
    }
}
public:


int colorTheGrid(int m, int n) {
    vector<vector<int>> patterns;
    vector<int> current;
    generatePatterns(m, patterns, current);

    int P = patterns.size();

    vector<vector<int>> transitions(P);
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            bool valid = true;
            for (int k = 0; k < m; ++k) {
                if (patterns[i][k] == patterns[j][k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                transitions[i].push_back(j);
            }
        }
    }

    vector<int> dp(P, 1);

    for (int col = 1; col < n; ++col) {
        vector<int> new_dp(P, 0);
        for (int i = 0; i < P; ++i) {
            for (int j : transitions[i]) {
                new_dp[j] = (new_dp[j] + dp[i]) % MOD;
            }
        }
        dp = new_dp;
    }

    int result = 0;
    for (int count : dp) {
        result = (result + count) % MOD;
    }

    return result;
}
};