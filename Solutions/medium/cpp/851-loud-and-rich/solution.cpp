#define Graph vector<vector<int>> 
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, vector<int>& inDegree, int n){
        Graph graph(n);
        for (const auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }
        return graph;
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int n = quiet.size();
        vector<int> inDegree(n, 0);
        Graph graph = buildGraph(richer, inDegree, n);
        
        vector<int> ans(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i){
            ans[i] = i;
            if(inDegree[i] == 0)
                q.push(i);
        }
            
        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            for (const auto& neigh : graph[currNode])
            {
                if (quiet[ans[currNode]] < quiet[ans[neigh]])
                {
                    ans[neigh] = ans[currNode];
                }
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return ans;
    }
};
