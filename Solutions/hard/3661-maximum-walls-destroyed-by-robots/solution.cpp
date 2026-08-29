class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        using ll = long long;

        int n = robots.size();

        vector<pair<ll,ll>> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = {robots[i], distance[i]};
        }
        sort(r.begin(), r.end());

        sort(walls.begin(), walls.end());

        auto count_walls = [&](ll l, ll r) {
            auto it1 = lower_bound(walls.begin(), walls.end(), l);
            auto it2 = upper_bound(walls.begin(), walls.end(), r);
            return (int)(it2 - it1);
        };

        // intervalos
        vector<pair<ll,ll>> L(n), R(n);
        vector<int> cntL(n), cntR(n);

        for (int i = 0; i < n; i++) {
            ll pos = r[i].first;
            ll d = r[i].second;

            // LEFT
            ll l = pos - d;
            if (i > 0) l = max(l, r[i-1].first);
            ll rr = pos;

            L[i] = {l, rr};
            cntL[i] = count_walls(l, rr);

            // RIGHT
            l = pos;
            rr = pos + d;
            if (i < n-1) rr = min(rr, r[i+1].first);

            R[i] = {l, rr};
            cntR[i] = count_walls(l, rr);
        }

        // função overlap
        auto overlap = [&](pair<ll,ll> a, pair<ll,ll> b) {
            ll l = max(a.first, b.first);
            ll r = min(a.second, b.second);
            if (l > r) return 0;
            return count_walls(l, r);
        };

        vector<vector<int>> dp(n, vector<int>(2, 0));

        // base
        dp[0][0] = cntL[0];
        dp[0][1] = cntR[0];

        for (int i = 1; i < n; i++) {

            // LEFT
            dp[i][0] = max(
                dp[i-1][0] + cntL[i] - overlap(L[i], L[i-1]),
                dp[i-1][1] + cntL[i] - overlap(L[i], R[i-1])
            );

            // RIGHT
            dp[i][1] = max(
                dp[i-1][0] + cntR[i] - overlap(R[i], L[i-1]),
                dp[i-1][1] + cntR[i] - overlap(R[i], R[i-1])
            );
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};