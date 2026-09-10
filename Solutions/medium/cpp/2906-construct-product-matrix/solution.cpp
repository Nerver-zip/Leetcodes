constexpr int MOD = 12345; 
using ll = long long;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();

        vector<ll> flat;
        for(const auto& r : grid)
            flat.insert(flat.end(), r.begin(), r.end());
    
        const int n = flat.size();
        vector<ll> prefix(n, 1); 
        vector<ll> suffix(n, 1);

        prefix[0] = flat[0];
        for(int i = 1; i < n; ++i)
            prefix[i] = (prefix[i-1] * flat[i]) % MOD;

        suffix[n-1] = flat[n-1];
        for(int i = n-2; i >= 0; --i)
            suffix[i] = (suffix[i+1] * flat[i]) % MOD;
        
        vector<vector<int>> ans(M, vector<int>(N, 0));

        for(int i = 0; i < n; ++i){
            if(i == 0)
                ans[i/N][i % N] = suffix[i+1] % MOD;
            else if(i == n-1)
                ans[i/N][i % N] = prefix[i-1] % MOD;
            else
                ans[i/N][i % N] = (prefix[i-1] * suffix[i+1]) % MOD;
            
        }

        return ans;
    }
};