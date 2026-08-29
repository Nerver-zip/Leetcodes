class Solution {
private:
unsigned nChoosek(unsigned n, unsigned k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> frequency;

        for (const auto& domino : dominoes)
        {
            int left = min(domino[0], domino[1]);
            int right = max(domino[0], domino[1]);

            string key = to_string(left) + "," + to_string(right);

            frequency[key]++;
        }
        int ans = 0;
        for (const auto& [key, freq] : frequency)
            ans += nChoosek(freq, 2);
        return ans;
    }
};
