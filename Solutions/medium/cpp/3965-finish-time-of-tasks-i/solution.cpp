using ll = long long;

class Solution {
using Graph = vector<vector<int>>;
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        Graph graph = buildGraph(n, edges);
        vector<ll> cache(n, -1);

        return dfs(graph, baseTime, cache, 0);
    }
private:
    Graph buildGraph(int n, const vector<vector<int>>& edges){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
        }

        return g;
    }

    ll dfs(const Graph& graph, const vector<int>& baseTime, vector<ll>& cache, int u){
        if(graph[u].empty()){
            return baseTime[u];
        }

        if(cache[u] != -1){
            return cache[u];
        }
        
        ll earliest = LLONG_MAX;
        ll latest = LLONG_MIN;
        ll ownDuration = 0;
        for(int v : graph[u]){
            earliest = min(earliest, dfs(graph, baseTime, cache, v));
            latest = max(latest, dfs(graph, baseTime, cache, v));
        }

        ownDuration = (latest - earliest) + baseTime[u];
        return cache[u] = ownDuration + latest;
    }
};