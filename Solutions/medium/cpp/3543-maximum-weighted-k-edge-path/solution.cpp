#define Graph vector<vector<pair<int,int>>>
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph graph(n);
        for (const auto& edge : edges){
            int src = edge[0], tgt = edge[1], weight = edge[2];
            graph[src].emplace_back(tgt, weight);
        }
        return graph;
    }

public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if (k == 0) return 0;

        Graph graph = buildGraph(edges, n);
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(k + 1, vector<bool>(t, false)));

        queue<array<int, 3>> q; // {node, edgesUsed, weight}
        //eval from each src
        for (int i = 0; i < n; ++i) {
            dp[i][0][0] = true;
            q.push({i, 0, 0});
        }

        int maxW = -1;

        while (!q.empty()) {
            auto [u, edgesUsed, weight] = q.front();
            q.pop();

            if (edgesUsed == k) {
                maxW = max(maxW, weight);
                continue;
            }

            for (const auto& [v, w] : graph[u]) {
                int newWeight = weight + w;
                int newEdges = edgesUsed + 1;

                if (newWeight < t && !dp[v][newEdges][newWeight]) {
                    dp[v][newEdges][newWeight] = true;
                    q.push({v, newEdges, newWeight});
                }
            }
        }

        return maxW;
    }
};