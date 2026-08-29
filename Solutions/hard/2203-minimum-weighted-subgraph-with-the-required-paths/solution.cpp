class Solution {
    using ll = long long;
    using Graph = vector<vector<pair<int,int>>>;
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        const auto g = buildGraph(edges, n);
        const auto g_rev = buildGraph(edges, n, true);

        auto dijkstra = [n](const Graph& g, int src)->vector<ll>{
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>>pq;
            vector<ll> distList(n, numeric_limits<ll>::max());
            distList[src] = 0;
            
            pq.push({0, src});

            while (!pq.empty()) {
                auto [currDist, u] = pq.top();
                pq.pop();

                if(distList[u] < currDist)
                    continue;

                for(const auto& [v, w] : g[u]){
                    ll newDist = 1LL * currDist + w;
                    if(distList[v] > newDist){
                        distList[v] = newDist;
                        pq.push({newDist, v});
                    }
                }
            }
            return distList;
        };

        auto d1 = dijkstra(g, src1);
        auto d2 = dijkstra(g, src2);
        auto d3 = dijkstra(g_rev, dest);
    
        
        ll ans = numeric_limits<ll>::max();

        for(int i = 0; i < n; ++i){
            if(d1[i] == numeric_limits<ll>::max() || d2[i] == numeric_limits<ll>::max() || d3[i] == numeric_limits<ll>::max())
                continue;
            ans = min(ans, d1[i] + d2[i] + d3[i]);
        }

        return ans == numeric_limits<ll>::max() ? -1 : ans;
    }

private:
    Graph buildGraph(const vector<vector<int>>& edges, int n, bool invert = false){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            
            if(invert)
                g[v].push_back({u, w});            
            else
                g[u].push_back({v, w});
        }

        return g;
    }
};