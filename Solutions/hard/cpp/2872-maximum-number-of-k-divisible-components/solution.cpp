class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        const auto& graph = buildAdj(edges, n);

        dfs(graph, values, k, 0, -1);
        return ans;
    }
private:
    int ans = 0;

    vector<vector<int>> buildAdj(const vector<vector<int>>& edges, int n){
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return graph;
    }

    long long dfs(const vector<vector<int>>& graph, const vector<int>& values, int k, int u, int parent){
        
        long long total = values[u];
        
        for (const auto& neigh : graph[u]) {
            if(neigh != parent)
                total += dfs(graph, values, k, neigh, u);
        }


        if(total % k == 0){
            ++ans;
            return 0;
        }

        return total;
    }
};
