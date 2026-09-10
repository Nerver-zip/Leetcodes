using ll = long long;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<ll> costToDelete(26, 0);

        for (int i = 0; i < s.size(); ++i)
            costToDelete[s[i] - 'a'] += 1LL * cost[i];
        
        ll totalCost = LLONG_MAX;
        for (int i = 0; i < 26; ++i) {
            ll curr = 0;
            if(costToDelete[i] != 0){
                for (int j = 0; j < 26; ++j) {
                    if(i != j)
                        curr += costToDelete[j];
                }
                totalCost = min(totalCost, curr);
            }
        }
        return totalCost;
    }
};
