using ll = long long;

class Solution {
using Graph = vector<vector<int>>;
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        Graph g = buildGraph(parent, nums);
        
        auto tree = levelOrder(g, 0, nums);
        
        ll ans = 0;
        const int h = tree.size();
        for(int d = 0; d < tree.size(); ++d){
            int depth = d + 1;

            for(ll n : tree[d]){
                ans += n * (h - depth + 1);
            }
        }
         
        return ans;
    }
private:
    vector<vector<int>> levelOrder(const Graph& g, int root, const vector<int>& nums) {
        vector<vector<int>> ans;
    
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                level.push_back(nums[u]);
                for(int v : g[u]) {
                    q.push(v);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }

    Graph buildGraph(const vector<int>& parent, const vector<int>& nums){
        Graph g(parent.size());

        for(int u = 1; u < g.size(); ++u){
            int p = parent[u];
            g[p].push_back(u);
        }

        return g;
    }
};