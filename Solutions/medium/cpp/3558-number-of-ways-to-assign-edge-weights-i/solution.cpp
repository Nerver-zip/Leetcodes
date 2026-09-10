constexpr int MOD = 1000000007; 
using ll = long long;

ll modpow(ll base, ll exp, ll mod = MOD) {
    base %= mod;
    if(base < 0) base += mod;

    ll res = 1 % mod;

    while(exp > 0) {
        if(exp & 1)
            res = (ll)((__int128)res * base % mod);

        base = (ll)((__int128)base * base % mod);
        exp >>= 1;
    }

    return res;
}

ll modinv(ll x, ll mod = MOD) {
    x %= mod;
    if(x < 0) x += mod;
    return modpow(x, mod - 2, mod);
}

class Solution {
using Graph = vector<vector<int>>;
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size();
        int maxDepth = 0;

        const auto graph = buildGraph(edges, n+2);
        
        queue<pair<int,int>> q;
        vector<bool> visited(n+2, false);
        q.push({1,0});
        visited[1] = true;
        

        while(!q.empty()){
            auto [u, depth] = q.front();
            q.pop();

            maxDepth = depth;
            
            for(const auto& v : graph[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push({v, depth + 1});
                }
            }
        }

        return modpow(2, maxDepth-1);
    }

private:
    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        return g;
    }
};