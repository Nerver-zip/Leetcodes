class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();

        vector<vector<int>> dist(n, vector<int>(n, INT32_MAX));

        for (int u = 0; u < n; ++u){
            dist[u] = bfsDistances(u, graph);
        }

        vector<vector<int>>().swap(graph);

        //custo mínimo de se visitar os vertices presentes na máscara terminando em u
        vector<vector<int>> dp(1 << n, vector<int>(n, INT32_MAX));

        for (int u = 0; u < n; ++u)
            dp[1 << u][u] = 0;
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int u = 0; u < n; ++u) {
                if(!(mask & (1 << u)) || dp[mask][u] == INT32_MAX) continue;
                for (int v = 0; v < n; ++v) {
                    if(mask & (1 << v)) continue;
                    int newmask = mask | (1 << v);
                    dp[newmask][v] = min(dp[newmask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }

        int ans = INT32_MAX;

        for (int res : dp[(1 << n) - 1])
            ans = min(ans, res);

        return ans;
    }

private:
    vector<int> bfsDistances(int start, const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dist(n, INT32_MAX);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (dist[v] == INT32_MAX) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    }
};
