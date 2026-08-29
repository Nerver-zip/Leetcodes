class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        static constexpr int MOD = 1'000'000'007;

        int maxValue = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(
            maxValue + 1,
            vector<int>(maxValue + 1)
        );

        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> newDp(
                maxValue + 1,
                vector<int>(maxValue + 1)
            );

            for (int g1 = 0; g1 <= maxValue; ++g1) {
                for (int g2 = 0; g2 <= maxValue; ++g2) {
                    int ways = dp[g1][g2];

                    if (ways == 0) {
                        continue;
                    }

                    // 1. Skip: x não pertence a nenhuma subsequência
                    add(newDp[g1][g2], ways);

                    // 2. Take: x pertence à seq1
                    int newG1 = std::gcd(g1, x);
                    add(newDp[newG1][g2], ways);

                    // 3. Take: x pertence à seq2
                    int newG2 = std::gcd(g2, x);
                    add(newDp[g1][newG2], ways);
                }
            }

            dp = std::move(newDp);
        }

        int answer = 0;

        for (int g = 1; g <= maxValue; ++g) {
            add(answer, dp[g][g]);
        }

        return answer;
    }

private:
    static constexpr int MOD = 1'000'000'007;

    void add(int& destination, int value) {
        destination += value;

        if (destination >= MOD) {
            destination -= MOD;
        }
    }
};