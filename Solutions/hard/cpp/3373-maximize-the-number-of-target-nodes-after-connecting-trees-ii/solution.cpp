#define Graph vector<vector<int>>

class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n) {
        Graph tree(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        return tree;
    }

    void dfs(const Graph& tree, int node, int parent, int depth, vector<int>& color, int& evenCount, int& oddCount) {
        color[node] = depth % 2;
        if (depth % 2 == 0) evenCount++;
        else oddCount++;

        for (int neigh : tree[node]) {
            if (neigh == parent) continue;
            dfs(tree, neigh, node, depth + 1, color, evenCount, oddCount);
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        Graph tree1 = buildGraph(edges1, n);
        Graph tree2 = buildGraph(edges2, m);

        vector<int> color1(n);
        vector<int> color2(m);

        int evenCount1 = 0, oddCount1 = 0;
        dfs(tree1, 0, -1, 0, color1, evenCount1, oddCount1);

        int evenCount2 = 0, oddCount2 = 0;
        dfs(tree2, 0, -1, 0, color2, evenCount2, oddCount2);

        int maxOddOrEven2 = max(evenCount2, oddCount2);

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (color1[i] == 0 ? evenCount1 : oddCount1) + maxOddOrEven2;
        }

        return ans;
    }
};