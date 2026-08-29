#define Graph vector<vector<int>>

class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n) {
        Graph graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    pair<long long, long long> dfs(int u, int parent, const Graph& tree, const vector<int>& nums, int k) {
        long long even = nums[u];
        long long odd = nums[u] ^ k;

        for (int v : tree[u]) {
            if (v == parent) continue;

            auto [childEven, childOdd] = dfs(v, u, tree, nums, k);

            long long newEven = max(even + childEven, odd + childOdd);
            long long newOdd = max(even + childOdd, odd + childEven);

            even = newEven;
            odd = newOdd;
        }

        return {even, odd};
    }

public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        Graph tree = buildGraph(edges, n);
        auto [even, odd] = dfs(0, -1, tree, nums, k);
        return even;
    }
};
