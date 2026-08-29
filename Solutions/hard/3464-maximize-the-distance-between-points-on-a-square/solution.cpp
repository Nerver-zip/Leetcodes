class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        long long per = 4LL * side;

        // Convert to 1D
        for (auto &p : points) {
            int x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(3LL * side - x);
            else pos.push_back(4LL * side - y);
        }

        sort(pos.begin(), pos.end());

        int n = pos.size();

        // duplicate for circular handling
        vector<long long> arr = pos;
        for (auto x : pos) arr.push_back(x + per);

        auto can = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                long long first = arr[i];
                long long last = arr[i];
                int idx = i;

                while (cnt < k) {
                    auto it = lower_bound(arr.begin() + idx + 1, arr.end(), last + d);
                    if (it == arr.end()) break;

                    long long nxt = *it;

                    // ❗ critical constraint (wrap-around check)
                    if (nxt - first > per - d) break;

                    last = nxt;
                    idx = it - arr.begin();
                    cnt++;
                }

                if (cnt >= k) return true;
            }
            return false;
        };

        long long lo = 0, hi = per;

        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};
