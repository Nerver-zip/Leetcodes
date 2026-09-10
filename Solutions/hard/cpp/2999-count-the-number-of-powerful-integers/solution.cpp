class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int lim, string s) {
        suffix = s;
        limit = lim;

        low = to_string(start);
        high = to_string(finish);

        while (low.size() < high.size())
            low = "0" + low;

        prefix_len = high.size() - suffix.size();
        memo.assign(high.size(), -1);

        return dfs(0, true, true);
    }

private:
    string low, high, suffix;
    int limit, prefix_len;
    vector<long long> memo;
    long long dfs(int pos, bool tightLow, bool tightHigh) {
        if (pos == high.size())
            return 1;

        if (!tightLow && !tightHigh && memo[pos] != -1)
            return memo[pos];

        long long count = 0;
        int lo = tightLow ? low[pos] - '0' : 0;
        int hi = tightHigh ? high[pos] - '0' : 9;

        if (pos < prefix_len) {
            for (int d = lo; d <= min(hi, limit); ++d) {
                count += dfs(pos + 1, tightLow && d == lo, tightHigh && d == hi);
            }
        } else {
            int d = suffix[pos - prefix_len] - '0';
            if (d >= lo && d <= hi && d <= limit)
                count = dfs(pos + 1, tightLow && d == lo, tightHigh && d == hi);
        }

        if (!tightLow && !tightHigh)
            memo[pos] = count;

        return count;
    }
};