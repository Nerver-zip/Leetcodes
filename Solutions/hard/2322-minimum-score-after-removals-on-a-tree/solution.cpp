#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution {
private: 
    int n;
    vector<vector<int>> adj;
    vector<int> subtreeXor, tin, tout;
    int timer = 0;
    
    void buildGraph(const vector<vector<int>>& edges, int n){
        adj.assign(n,{});
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int u, int parent, const vector<int>& nums) {
        tin[u] = timer++;
        subtreeXor[u] = nums[u];

        for (int v : adj[u]) {
            if (v == parent) continue;
            dfs(v, u, nums);
            subtreeXor[u] ^= subtreeXor[v];  // accum XOR
        }

        tout[u] = timer++;
    }

    //Euler's Tour 
    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        subtreeXor.resize(n);
        tin.resize(n);
        tout.resize(n);

        buildGraph(edges, n);

        dfs(0, -1, nums);
        int totalXor = subtreeXor[0];

        vector<pair<int, int>> directedEdges;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (isAncestor(u, v)) {
                directedEdges.emplace_back(u, v);
            } else {
                directedEdges.emplace_back(v, u);
            }
        }

        int res = INT32_MAX;

        int m = directedEdges.size();
        for (int i = 0; i < m; ++i) {
            int a = directedEdges[i].second;
            for (int j = i + 1; j < m; ++j) {
                int b = directedEdges[j].second;

                int x, y, z;

                if (isAncestor(a, b)) {
                    x = subtreeXor[b];
                    y = subtreeXor[a] ^ subtreeXor[b];
                    z = totalXor ^ subtreeXor[a];
                } else if (isAncestor(b, a)) {
                    x = subtreeXor[a];
                    y = subtreeXor[b] ^ subtreeXor[a];
                    z = totalXor ^ subtreeXor[b];
                } else {
                    x = subtreeXor[a];
                    y = subtreeXor[b];
                    z = totalXor ^ x ^ y;
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }
        return res;
    }
};