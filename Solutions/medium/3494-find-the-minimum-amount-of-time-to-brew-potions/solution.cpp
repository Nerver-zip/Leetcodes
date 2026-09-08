using ll = long long;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<ll> earliestFinishTime(n, 0);
        for (int j = 0; j < m; ++j) {
            ll x = mana[j];
            // now = earliest time current wizard can start 
            ll now = earliestFinishTime[0];
            for (int i = 1; i < n; ++i) {
                // arrival time at wizard i if we don't wait: now + skill[i-1]*x
                // but wizard i might be busy until f[i], so take max
                now = max(now + (ll)skill[i-1] * x, earliestFinishTime[i]);
            }
            // now is the start time for wizard n-1
            earliestFinishTime[n-1] = now + (ll)skill[n-1] * x;
            // backfill earlier wizards' finish times
            for (int i = n-2; i >= 0; --i) {
                earliestFinishTime[i] = earliestFinishTime[i+1] - (ll)skill[i+1] * x;
            }
        }
        return earliestFinishTime[n-1];
    }
};
