using ll = long long;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        const int n = robot.size();
    
        sort(factory.begin(), factory.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        sort(robot.begin(), robot.end());

        vector<int> slots;

        for(const auto& f : factory){
            int pos = f[0], amount = f[1];
            while(amount--)
                slots.push_back(pos);
        }
        
        const int m = slots.size();
        
        const ll INF = numeric_limits<ll>::max()/4;

        // Min cost to allocate first i robots using first j factories
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
        
        dp[0][0] = 0; // base
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][0] = INF; // can't reach this state
                dp[0][j] = 0; // base case

                // at dp[i][j] we can choose to take or not take a slot
                dp[i][j] = min(
                    dp[i][j-1],
                    dp[i-1][j-1] + abs(robot[i-1] - slots[j-1])
                );
            }
        }

        ll ans = numeric_limits<ll>::max();

        for(ll dist : dp[n])
            ans = min(ans, dist);
        
        return ans;
    }
};